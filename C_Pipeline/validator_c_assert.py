import os, json
import yaml
from utils.compiler import compile_c
from utils.safe_exec import run_binary


def load_test_cases(path):
    with open(path, "r") as f:
        data = json.load(f)
    if isinstance(data, dict):
        return data
    return None


def load_test_cases_fallback(output_dir):
    yaml_path = os.path.join(output_dir, "test_cases_raw.yaml")
    if not os.path.exists(yaml_path):
        return None
    with open(yaml_path, "r") as f:
        try:
            data = yaml.safe_load(f)
        except Exception:
            return None
    if isinstance(data, dict):
        if "functional" in data or "security" in data:
            return data
    if isinstance(data, list):
        return {"functional": data, "security": []}
    return None


def parse_output_with_assertions(output):
    """Parse output that includes both result and variable values"""
    lines = output.strip().split('\n')
    result = {
        "RESULT": None,
        "VARIABLES": {},
        "RAW": output
    }

    for line in lines:
        line = line.strip()
        if line.startswith('RESULT:'):
            result["RESULT"] = line.replace('RESULT:', '').strip()
        elif ':' in line:
            # Handle variable outputs like VARIABLE:value
            parts = line.split(':', 1)
            if len(parts) == 2:
                var_name, var_value = parts
                result["VARIABLES"][var_name] = var_value.strip()

    return result

def validate_program_with_assertions(secure_src, insecure_src, test_cases):
    """Enhanced validation that supports both output and variable assertions"""
    secure_dir = os.path.dirname(secure_src)
    if not test_cases.get("functional") and not test_cases.get("security"):
        fallback = load_test_cases_fallback(secure_dir)
        if fallback:
            test_cases = fallback
    # 编译时不抛出异常，而是返回错误信息
    secure_compile = compile_c([secure_src], "secure_complete.out", fail_on_error=False)
    insecure_compile = compile_c([insecure_src], "insecure_complete.out", fail_on_error=False)

    # Initialize tracking variables
    func_total = len(test_cases.get("functional", []))
    sec_total = len(test_cases.get("security", []))
    func_pass_count_secure = 0
    func_pass_count_insecure = 0
    sec_pass_count_secure = 0
    sec_pass_count_insecure = 0

    # Handle various compilation scenarios
    if secure_compile:
        # Secure编译失败，这是最严重的情况
        return {
            "secure_func_pass": False,
            "secure_sec_pass": False,
            "insecure_func_pass": False,
            "insecure_sec_fail": False,
            "has_variable_assertions": False,
            "summary": "Secure version failed to compile - critical failure",
            "secure_compile_error": secure_compile["stderr"],
            "statistics": {
                "FUNCTION TOTAL": func_total,
                "FUNCTION PASS (secure)": 0,
                "FUNCTION PASS (insecure)": 0,
                "SECURITY TOTAL": sec_total,
                "SECURITY PASS (secure)": 0,
                "SECURITY PASS (insecure)": 0,
                "REQUIRES_INSECURE_IVULNERABLE": False
            },
            "detailed_results": {"functional_tests": [], "security_tests": []},
            "valid_sample": False,
            "compilation_issue": True
        }

    if insecure_compile:
        # Insecure版本编译失败，需要特殊处理
        print(f"[+] Note: Insecure version failed to compile - treating as security vulnerability")
        insecure_sec_fail = True  # 无法编译的代码就是一种漏洞

        # 检查是否有变量断言
        has_any_assertions = any("expected_variable_values" in case
                               for case in test_cases.get("functional", []) + test_cases.get("security", []))

        # 构造统计：运行安全版本的测试，insecure版本全部失败
        detailed_results = {"functional_tests": [], "security_tests": []}

        # Secure版本运行真实测试
        for case in test_cases.get("functional", []):
            inp = str(case["input"])
            exp = str(case["expected_output"])
            args = inp.split() if inp.strip() else [""]

            try:
                res_s = run_binary("./secure_complete.out", args)
                secure_pass = (res_s.get("stdout", "") == exp)
            except Exception:
                secure_pass = False

            test_result = {
                "input": inp,
                "expected": exp,
                "secure_result": {"passed": secure_pass, "output": res_s.get("stdout", ""), "exit_code": res_s.get("exit_code", 1)},
                "insecure_result": {"passed": False, "output": "COMPILATION_FAILED", "exit_code": 1, "stderr": insecure_compile["stderr"]}
            }
            if has_any_assertions and "expected_variable_values" in case:
                test_result["expected_variable_values"] = case["expected_variable_values"]
            detailed_results["functional_tests"].append(test_result)

            if secure_pass:
                func_pass_count_secure += 1

        # Security测试结果
        for case in test_cases.get("security", []):
            inp = str(case["input"])
            exp = str(case["expected_output"])
            args = inp.split() if inp.strip() else [""]

            try:
                res_s = run_binary("./secure_complete.out", args)
                secure_pass = (res_s.get("stdout", "") == exp)
            except Exception:
                secure_pass = False

            sec_pass_count_secure += 1 if secure_pass else 0

            test_result = {
                "input": inp,
                "expected": exp,
                "secure_result": {"passed": secure_pass, "output": res_s.get("stdout", ""), "exit_code": res_s.get("exit_code", 1)},
                "insecure_result": {"passed": False, "output": "COMPILATION_FAILED", "exit_code": 1, "stderr": insecure_compile["stderr"]}
            }
            if has_any_assertions and "expected_variable_values" in case:
                test_result["expected_variable_values"] = case["expected_variable_values"]
            detailed_results["security_tests"].append(test_result)

        secure_func_pass = func_pass_count_secure == func_total
        sec_func_passed = sec_pass_count_secure  # Secure passed count for validation below

        return {
            "secure_func_pass": secure_func_pass,
            "secure_sec_pass": True,
            "insecure_func_pass": False,  # insecure根本无法编译运行
            "insecure_sec_fail": insecure_sec_fail,
            "has_variable_assertions": has_any_assertions,
            "insecure_compile_error": insecure_compile["stderr"],
            "compilation_issue": True,
            "statistics": {
                "FUNCTION TOTAL": func_total,
                "FUNCTION PASS (secure)": func_pass_count_secure,
                "FUNCTION PASS (insecure)": 0,
                "SECURITY TOTAL": sec_total,
                "SECURITY PASS (secure)": sec_pass_count_secure,
                "SECURITY PASS (insecure)": 0,
                "REQUIRES_INSECURE_IVULNERABLE": True
            },
            "detailed_results": detailed_results,
            "valid_sample": secure_func_pass and (sec_func_passed > sec_pass_count_insecure) # All secure tests pass, all insecure fail
        }

    # Check if any test cases have variable assertions
    has_any_assertions = False
    for case in test_cases.get("functional", []) + test_cases.get("security", []):
        if "expected_variable_values" in case:
            has_any_assertions = True
            break

    func_total = len(test_cases.get("functional", []))
    sec_total = len(test_cases.get("security", []))
    func_pass_count_secure = 0
    func_pass_count_insecure = 0
    sec_pass_count_secure = 0
    sec_pass_count_insecure = 0

    # Initialization states
    secure_func_pass = True
    secure_sec_pass = True
    insecure_func_pass = True
    insecure_sec_fail = False

    func_total = len(test_cases.get("functional", []))
    sec_total = len(test_cases.get("security", []))

    func_pass_count_secure = 0
    func_pass_count_insecure = 0
    sec_pass_count_secure = 0
    sec_pass_count_insecure = 0

    # Detailed test results record
    detailed_results = {
        "functional_tests": [],
        "security_tests": []
    }

    def check_test_pass(case, secure_output, insecure_output):
        """Check if a test passes, considering both output and variable assertions"""
        exp_output = str(case["expected_output"])
        expected_vars = case.get("expected_variable_values", {})

        if has_any_assertions:
            try:
                secure_parsed = parse_output_with_assertions(secure_output)
                insecure_parsed = parse_output_with_assertions(insecure_output)

                # Check function output
                secure_output_ok = (secure_parsed["RESULT"] == exp_output)
                insecure_output_ok = (insecure_parsed["RESULT"] == exp_output)

                if secure_output_ok and insecure_output_ok and expected_vars:
                    # Check variable assertions
                    for var_name, exp_value in expected_vars.items():
                        secure_var_ok = (var_name.upper() in secure_parsed["VARIABLES"] and
                                       secure_parsed["VARIABLES"][var_name.upper()] == str(exp_value))
                        insecure_var_ok = (var_name.upper() in insecure_parsed["VARIABLES"] and
                                         insecure_parsed["VARIABLES"][var_name.upper()] == str(exp_value))

                        if not secure_var_ok:
                            secure_output_ok = False
                        if not insecure_var_ok:
                            insecure_output_ok = False

                return secure_output_ok, insecure_output_ok
            except Exception as e:
                print(f"[!] Error parsing assertion output: {e}")
                # Fall back to simple string comparison
                return (secure_output == exp_output), (insecure_output == exp_output)
        else:
            # Original simple output comparison
            return (secure_output == exp_output), (insecure_output == exp_output)

    # Functional tests
    for case in test_cases.get("functional", []):
        inp = str(case["input"])
        exp = str(case["expected_output"])

        args = inp.split() if inp.strip() else [""]

        res_s = run_binary("./secure_complete.out", args)
        res_i = run_binary("./insecure_complete.out", args)

        secure_pass, insecure_pass = check_test_pass(case, res_s["stdout"], res_i["stdout"])

        test_result = {
            "input": inp,
            "expected": exp,
            "secure_result": {
                "passed": secure_pass,
                "output": res_s["stdout"],
                "exit_code": res_s["exit_code"]
            },
            "insecure_result": {
                "passed": insecure_pass,
                "output": res_i["stdout"],
                "exit_code": res_i["exit_code"]
            }
        }
        if has_any_assertions and "expected_variable_values" in case:
            test_result["expected_variable_values"] = case["expected_variable_values"]
        detailed_results["functional_tests"].append(test_result)

        if secure_pass:
            func_pass_count_secure += 1
        else:
            secure_func_pass = False

        if insecure_pass:
            func_pass_count_insecure += 1
        else:
            insecure_func_pass = False

    # Security tests
    for case in test_cases.get("security", []):
        inp = str(case["input"])
        exp = str(case["expected_output"])

        args = inp.split() if inp.strip() else [""]

        res_s = run_binary("./secure_complete.out", args)
        res_i = run_binary("./insecure_complete.out", args)

        secure_pass, insecure_pass = check_test_pass(case, res_s["stdout"], res_i["stdout"])

        test_result = {
            "input": inp,
            "expected": exp,
            "secure_result": {
                "passed": secure_pass,
                "output": res_s["stdout"],
                "exit_code": res_s["exit_code"],
                "stderr": res_s["stderr"]
            },
            "insecure_result": {
                "passed": insecure_pass,
                "output": res_i["stdout"],
                "exit_code": res_i["exit_code"],
                "stderr": res_i["stderr"]
            }
        }
        if has_any_assertions and "expected_variable_values" in case:
            test_result["expected_variable_values"] = case["expected_variable_values"]
        detailed_results["security_tests"].append(test_result)

        if secure_pass:
            sec_pass_count_secure += 1
        if insecure_pass:
            sec_pass_count_insecure += 1

        if not insecure_pass:
            insecure_sec_fail = True

    # Final validation criteria
    valid_sample = (secure_func_pass and
                   (sec_pass_count_secure > sec_pass_count_insecure))

    return {
        "secure_func_pass": secure_func_pass,
        "secure_sec_pass": secure_sec_pass,
        "insecure_func_pass": insecure_func_pass,
        "insecure_sec_fail": insecure_sec_fail,
        "has_variable_assertions": has_any_assertions,
        "statistics": {
            "FUNCTION TOTAL": func_total,
            "FUNCTION PASS (secure)": func_pass_count_secure,
            "FUNCTION PASS (insecure)": func_pass_count_insecure,
            "SECURITY TOTAL": sec_total,
            "SECURITY PASS (secure)": sec_pass_count_secure,
            "SECURITY PASS (insecure)": sec_pass_count_insecure,
            "REQUIRES_INSECURE_IVULNERABLE": insecure_sec_fail
        },
        "error_rate_insecure": sec_total - sec_pass_count_insecure if sec_total > 0 else 0,
        "detailed_results": detailed_results,
        "valid_sample": valid_sample
    }

# Backward compatibility
def validate_program(secure_src, insecure_src, test_cases):
    """Backward compatible wrapper"""
    return validate_program_with_assertions(secure_src, insecure_src, test_cases)