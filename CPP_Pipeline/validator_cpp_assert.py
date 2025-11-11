import os
from typing import Dict

import yaml
from utils.cpp_compiler import compile_cpp
from utils.cpp_runner import run_binary


def load_test_cases_fallback(output_dir: str):
    yaml_path = os.path.join(output_dir, "test_cases_raw.yaml")
    if not os.path.exists(yaml_path):
        return None
    try:
        with open(yaml_path, "r") as f:
            data = yaml.safe_load(f)
    except Exception:
        return None
    if isinstance(data, dict):
        if "functional" in data or "security" in data:
            return data
    if isinstance(data, list):
        return {"functional": data, "security": []}
    return None


def parse_output_with_assertions(output: str) -> Dict:
    lines = (output or "").strip().splitlines()
    result = {"RESULT": None, "VARIABLES": {}, "RAW": output}
    for line in lines:
        line = line.strip()
        if not line:
            continue
        if line.startswith("RESULT:"):
            result["RESULT"] = line.replace("RESULT:", "", 1).strip()
        elif ":" in line:
            key, value = line.split(":", 1)
            result["VARIABLES"][key.strip().upper()] = value.strip()
    return result


def _normalize_args(input_str: str):
    input_str = input_str or ""
    if not input_str.strip():
        return []
    return input_str.split()


def validate_program_with_assertions(secure_src: str, insecure_src: str, test_cases: Dict):
    secure_src = os.path.abspath(secure_src)
    insecure_src = os.path.abspath(insecure_src)
    secure_dir = os.path.dirname(secure_src)

    if not test_cases.get("functional") and not test_cases.get("security"):
        fallback = load_test_cases_fallback(secure_dir)
        if fallback:
            test_cases = fallback

    secure_binary = os.path.join(secure_dir, "secure_assert.out")
    insecure_binary = os.path.join(secure_dir, "insecure_assert.out")

    secure_compile = compile_cpp([secure_src], secure_binary, fail_on_error=False)
    insecure_compile = compile_cpp([insecure_src], insecure_binary, fail_on_error=False)

    func_cases = test_cases.get("functional", [])
    sec_cases = test_cases.get("security", [])

    if secure_compile:
        return {
            "secure_func_pass": False,
            "secure_sec_pass": False,
            "insecure_func_pass": False,
            "insecure_sec_fail": False,
            "has_variable_assertions": True,
            "summary": "Secure version failed to compile",
            "secure_compile_error": secure_compile.get("stderr", ""),
            "statistics": {
                "FUNCTION TOTAL": len(func_cases),
                "FUNCTION PASS (secure)": 0,
                "FUNCTION PASS (insecure)": 0,
                "SECURITY TOTAL": len(sec_cases),
                "SECURITY PASS (secure)": 0,
                "SECURITY PASS (insecure)": 0,
                "REQUIRES_INSECURE_IVULNERABLE": False,
            },
            "detailed_results": {"functional_tests": [], "security_tests": []},
            "valid_sample": False,
            "compilation_issue": True,
        }

    has_any_assertions = any("expected_variable_values" in case for case in (func_cases + sec_cases))

    detailed_results = {"functional_tests": [], "security_tests": []}

    if insecure_compile:
        print("[+] Note: Insecure version failed to compile - treating as vulnerability")

        func_pass_count_secure = 0
        sec_pass_count_secure = 0

        for case in func_cases:
            inp = str(case.get("input", ""))
            expected = str(case.get("expected_output", ""))
            args = _normalize_args(inp)

            res_secure = run_binary(secure_binary, args)
            secure_pass = res_secure.get("stdout", "") == expected

            entry = {
                "input": inp,
                "expected": expected,
                "secure_result": {
                    "passed": secure_pass,
                    "output": res_secure.get("stdout", ""),
                    "exit_code": res_secure.get("exit_code", 1),
                },
                "insecure_result": {
                    "passed": False,
                    "output": "COMPILATION_FAILED",
                    "exit_code": 1,
                    "stderr": insecure_compile.get("stderr", ""),
                },
            }
            if has_any_assertions and "expected_variable_values" in case:
                entry["expected_variable_values"] = case["expected_variable_values"]
            detailed_results["functional_tests"].append(entry)

            if secure_pass:
                func_pass_count_secure += 1

        for case in sec_cases:
            inp = str(case.get("input", ""))
            expected = str(case.get("expected_output", ""))
            args = _normalize_args(inp)

            res_secure = run_binary(secure_binary, args)
            secure_pass = res_secure.get("stdout", "") == expected and res_secure.get("exit_code", 1) == 0

            entry = {
                "input": inp,
                "expected": expected,
                "secure_result": {
                    "passed": secure_pass,
                    "output": res_secure.get("stdout", ""),
                    "exit_code": res_secure.get("exit_code", 1),
                },
                "insecure_result": {
                    "passed": False,
                    "output": "COMPILATION_FAILED",
                    "exit_code": 1,
                    "stderr": insecure_compile.get("stderr", ""),
                },
            }
            if has_any_assertions and "expected_variable_values" in case:
                entry["expected_variable_values"] = case["expected_variable_values"]
            detailed_results["security_tests"].append(entry)

            if secure_pass:
                sec_pass_count_secure += 1

        secure_func_pass = func_pass_count_secure == len(func_cases) if func_cases else True
        valid_sample = secure_func_pass and (sec_pass_count_secure > 0 or not sec_cases)

        return {
            "secure_func_pass": secure_func_pass,
            "secure_sec_pass": True,
            "insecure_func_pass": False,
            "insecure_sec_fail": True,
            "has_variable_assertions": has_any_assertions,
            "insecure_compile_error": insecure_compile.get("stderr", ""),
            "compilation_issue": True,
            "statistics": {
                "FUNCTION TOTAL": len(func_cases),
                "FUNCTION PASS (secure)": func_pass_count_secure,
                "FUNCTION PASS (insecure)": 0,
                "SECURITY TOTAL": len(sec_cases),
                "SECURITY PASS (secure)": sec_pass_count_secure,
                "SECURITY PASS (insecure)": 0,
                "REQUIRES_INSECURE_IVULNERABLE": True,
            },
            "detailed_results": detailed_results,
            "valid_sample": valid_sample,
        }

    secure_func_pass = True
    secure_sec_pass = True
    insecure_func_pass = True
    insecure_sec_fail = False

    func_pass_count_secure = 0
    func_pass_count_insecure = 0
    sec_pass_count_secure = 0
    sec_pass_count_insecure = 0

    def evaluate_case(case, secure_output, insecure_output):
        expected_output = str(case.get("expected_output", ""))
        expected_vars = case.get("expected_variable_values", {})

        try:
            secure_parsed = parse_output_with_assertions(secure_output)
            insecure_parsed = parse_output_with_assertions(insecure_output)

            secure_result_value = secure_parsed.get("RESULT")
            insecure_result_value = insecure_parsed.get("RESULT")

            if secure_result_value is None:
                secure_result_value = secure_output.strip()
            if insecure_result_value is None:
                insecure_result_value = insecure_output.strip()

            secure_ok = secure_result_value == expected_output
            insecure_ok = insecure_result_value == expected_output

            for var_name, exp_value in expected_vars.items():
                key = var_name.upper()
                if secure_parsed["VARIABLES"].get(key) != str(exp_value):
                    secure_ok = False
                if insecure_parsed["VARIABLES"].get(key) != str(exp_value):
                    insecure_ok = False
        except Exception:
            secure_ok = secure_output.strip() == expected_output
            insecure_ok = insecure_output.strip() == expected_output

        return secure_ok, insecure_ok

    def run_secure(args):
        return run_binary(secure_binary, args)

    def run_insecure(args):
        return run_binary(insecure_binary, args)

    detailed_results = {"functional_tests": [], "security_tests": []}

    for case in func_cases:
        inp = str(case.get("input", ""))
        expected = str(case.get("expected_output", ""))
        args = _normalize_args(inp)

        res_secure = run_secure(args)
        res_insecure = run_insecure(args)

        secure_pass, insecure_pass = evaluate_case(case, res_secure["stdout"], res_insecure["stdout"])

        entry = {
            "input": inp,
            "expected": expected,
            "secure_result": {
                "passed": secure_pass,
                "output": res_secure["stdout"],
                "exit_code": res_secure["exit_code"],
            },
            "insecure_result": {
                "passed": insecure_pass,
                "output": res_insecure["stdout"],
                "exit_code": res_insecure["exit_code"],
            },
        }
        if has_any_assertions and "expected_variable_values" in case:
            entry["expected_variable_values"] = case["expected_variable_values"]
        detailed_results["functional_tests"].append(entry)

        if secure_pass:
            func_pass_count_secure += 1
        else:
            secure_func_pass = False

        if insecure_pass:
            func_pass_count_insecure += 1
        else:
            insecure_func_pass = False

    for case in sec_cases:
        inp = str(case.get("input", ""))
        expected = str(case.get("expected_output", ""))
        args = _normalize_args(inp)

        res_secure = run_secure(args)
        res_insecure = run_insecure(args)

        secure_pass, insecure_pass = evaluate_case(case, res_secure["stdout"], res_insecure["stdout"])

        entry = {
            "input": inp,
            "expected": expected,
            "secure_result": {
                "passed": secure_pass,
                "output": res_secure["stdout"],
                "exit_code": res_secure["exit_code"],
                "stderr": res_secure["stderr"],
            },
            "insecure_result": {
                "passed": insecure_pass,
                "output": res_insecure["stdout"],
                "exit_code": res_insecure["exit_code"],
                "stderr": res_insecure["stderr"],
            },
        }
        if has_any_assertions and "expected_variable_values" in case:
            entry["expected_variable_values"] = case["expected_variable_values"]
        detailed_results["security_tests"].append(entry)

        if secure_pass:
            sec_pass_count_secure += 1
        if insecure_pass:
            sec_pass_count_insecure += 1
        if not insecure_pass:
            insecure_sec_fail = True

    statistics = {
        "FUNCTION TOTAL": len(func_cases),
        "FUNCTION PASS (secure)": func_pass_count_secure,
        "FUNCTION PASS (insecure)": func_pass_count_insecure,
        "SECURITY TOTAL": len(sec_cases),
        "SECURITY PASS (secure)": sec_pass_count_secure,
        "SECURITY PASS (insecure)": sec_pass_count_insecure,
        "REQUIRES_INSECURE_IVULNERABLE": insecure_sec_fail,
    }

    valid_sample = secure_func_pass and (sec_pass_count_secure > sec_pass_count_insecure)

    return {
        "secure_func_pass": secure_func_pass,
        "secure_sec_pass": secure_sec_pass,
        "insecure_func_pass": insecure_func_pass,
        "insecure_sec_fail": insecure_sec_fail,
        "has_variable_assertions": has_any_assertions,
        "statistics": statistics,
        "error_rate_insecure": len(sec_cases) - sec_pass_count_insecure if sec_cases else 0,
        "detailed_results": detailed_results,
        "valid_sample": valid_sample,
    }


def validate_program(secure_src: str, insecure_src: str, test_cases: Dict):
    return validate_program_with_assertions(secure_src, insecure_src, test_cases)
