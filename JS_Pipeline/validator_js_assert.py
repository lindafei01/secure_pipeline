import json
import os
from typing import Dict

import yaml
from utils.node_checker import check_js
from utils.node_runner import run_node


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
            name, value = line.split(":", 1)
            result["VARIABLES"][name.strip().upper()] = value.strip()
    return result


def _normalize_args(input_str: str):
    input_str = input_str or ""
    if not input_str.strip():
        return []
    return input_str.split()


def load_test_cases_fallback(output_dir: str):
    yaml_path = os.path.join(output_dir, "test_cases_raw.yaml")
    if not os.path.exists(yaml_path):
        return None
    try:
        with open(yaml_path, "r", encoding="utf-8") as f:
            data = yaml.safe_load(f)
    except Exception:
        return None
    if isinstance(data, dict):
        if "functional" in data or "security" in data:
            return data
    if isinstance(data, list):
        return {"functional": data, "security": []}
    return None


def validate_program_with_assertions(secure_src: str, insecure_src: str, test_cases: Dict):
    secure_check = check_js([secure_src], fail_on_error=False)
    insecure_check = check_js([insecure_src], fail_on_error=False)

    secure_dir = os.path.dirname(os.path.abspath(secure_src))
    if not test_cases.get("functional") and not test_cases.get("security"):
        fallback = load_test_cases_fallback(secure_dir)
        if fallback:
            test_cases = fallback

    def _check_has_assertions(cases):
        return any("expected_variable_values" in case for case in cases)

    func_cases = test_cases.get("functional", [])
    sec_cases = test_cases.get("security", [])
    has_any_assertions = _check_has_assertions(func_cases) or _check_has_assertions(sec_cases)

    func_total = len(func_cases)
    sec_total = len(sec_cases)

    if secure_check:
        return {
            "secure_func_pass": False,
            "secure_sec_pass": False,
            "insecure_func_pass": False,
            "insecure_sec_fail": False,
            "has_variable_assertions": has_any_assertions,
            "summary": "Secure version failed syntax check",
            "secure_compile_error": secure_check[0]["stderr"] if secure_check else "",
            "statistics": {
                "FUNCTION TOTAL": func_total,
                "FUNCTION PASS (secure)": 0,
                "FUNCTION PASS (insecure)": 0,
                "SECURITY TOTAL": sec_total,
                "SECURITY PASS (secure)": 0,
                "SECURITY PASS (insecure)": 0,
                "REQUIRES_INSECURE_IVULNERABLE": False,
            },
            "detailed_results": {"functional_tests": [], "security_tests": []},
            "valid_sample": False,
            "compilation_issue": True,
        }

    detailed_results = {"functional_tests": [], "security_tests": []}

    if insecure_check:
        insecure_sec_fail = True
        func_pass_count_secure = 0
        sec_pass_count_secure = 0
        func_pass_count_insecure = 0
        sec_pass_count_insecure = 0

        for case in func_cases:
            inp = str(case.get("input", ""))
            expected = str(case.get("expected_output", ""))
            args = _normalize_args(inp)

            res_secure = run_node(secure_src, args)
            secure_pass = res_secure.get("stdout", "") == expected

            result_entry = {
                "input": inp,
                "expected": expected,
                "secure_result": {
                    "passed": secure_pass,
                    "output": res_secure.get("stdout", ""),
                    "exit_code": res_secure.get("exit_code", 1),
                },
                "insecure_result": {
                    "passed": False,
                    "output": "SYNTAX_ERROR",
                    "exit_code": 1,
                    "stderr": insecure_check[0]["stderr"],
                },
            }
            if has_any_assertions and "expected_variable_values" in case:
                result_entry["expected_variable_values"] = case["expected_variable_values"]
            detailed_results["functional_tests"].append(result_entry)

            if secure_pass:
                func_pass_count_secure += 1

        for case in sec_cases:
            inp = str(case.get("input", ""))
            expected = str(case.get("expected_output", ""))
            args = _normalize_args(inp)

            res_secure = run_node(secure_src, args)
            secure_pass = res_secure.get("stdout", "") == expected and res_secure.get("exit_code", 1) == 0

            result_entry = {
                "input": inp,
                "expected": expected,
                "secure_result": {
                    "passed": secure_pass,
                    "output": res_secure.get("stdout", ""),
                    "exit_code": res_secure.get("exit_code", 1),
                },
                "insecure_result": {
                    "passed": False,
                    "output": "SYNTAX_ERROR",
                    "exit_code": 1,
                    "stderr": insecure_check[0]["stderr"],
                },
            }
            if has_any_assertions and "expected_variable_values" in case:
                result_entry["expected_variable_values"] = case["expected_variable_values"]
            detailed_results["security_tests"].append(result_entry)

            if secure_pass:
                sec_pass_count_secure += 1

        secure_func_pass = func_pass_count_secure == func_total if func_total else True
        valid_sample = secure_func_pass and (sec_pass_count_secure > sec_pass_count_insecure)

        return {
            "secure_func_pass": secure_func_pass,
            "secure_sec_pass": True,
            "insecure_func_pass": False,
            "insecure_sec_fail": insecure_sec_fail,
            "has_variable_assertions": has_any_assertions,
            "insecure_compile_error": insecure_check[0]["stderr"],
            "compilation_issue": True,
            "statistics": {
                "FUNCTION TOTAL": func_total,
                "FUNCTION PASS (secure)": func_pass_count_secure,
                "FUNCTION PASS (insecure)": func_pass_count_insecure,
                "SECURITY TOTAL": sec_total,
                "SECURITY PASS (secure)": sec_pass_count_secure,
                "SECURITY PASS (insecure)": sec_pass_count_insecure,
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

    def check_test_pass(case, secure_output, insecure_output):
        expected_output = str(case.get("expected_output", ""))
        expected_vars = case.get("expected_variable_values", {})

        if has_any_assertions:
            try:
                secure_parsed = parse_output_with_assertions(secure_output)
                insecure_parsed = parse_output_with_assertions(insecure_output)

                secure_ok = secure_parsed.get("RESULT") == expected_output
                insecure_ok = insecure_parsed.get("RESULT") == expected_output

                if expected_vars:
                    for var_name, exp_value in expected_vars.items():
                        var_key = var_name.upper()
                        secure_var_ok = secure_parsed["VARIABLES"].get(var_key) == str(exp_value)
                        insecure_var_ok = insecure_parsed["VARIABLES"].get(var_key) == str(exp_value)
                        if not secure_var_ok:
                            secure_ok = False
                        if not insecure_var_ok:
                            insecure_ok = False
                return secure_ok, insecure_ok
            except Exception:
                pass
        return secure_output == expected_output, insecure_output == expected_output

    for case in func_cases:
        inp = str(case.get("input", ""))
        expected = str(case.get("expected_output", ""))
        args = _normalize_args(inp)

        res_secure = run_node(secure_src, args)
        res_insecure = run_node(insecure_src, args)

        secure_pass, insecure_pass = check_test_pass(case, res_secure["stdout"], res_insecure["stdout"])

        detailed_entry = {
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
            detailed_entry["expected_variable_values"] = case["expected_variable_values"]
        detailed_results["functional_tests"].append(detailed_entry)

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

        res_secure = run_node(secure_src, args)
        res_insecure = run_node(insecure_src, args)

        secure_pass, insecure_pass = check_test_pass(case, res_secure["stdout"], res_insecure["stdout"])

        detailed_entry = {
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
            detailed_entry["expected_variable_values"] = case["expected_variable_values"]
        detailed_results["security_tests"].append(detailed_entry)

        if secure_pass:
            sec_pass_count_secure += 1
        if insecure_pass:
            sec_pass_count_insecure += 1
        if not insecure_pass:
            insecure_sec_fail = True

    valid_sample = secure_func_pass and (sec_pass_count_secure > sec_pass_count_insecure)

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
            "REQUIRES_INSECURE_IVULNERABLE": insecure_sec_fail,
        },
        "error_rate_insecure": sec_total - sec_pass_count_insecure if sec_total > 0 else 0,
        "detailed_results": detailed_results,
        "valid_sample": valid_sample,
    }


def validate_program(secure_src: str, insecure_src: str, test_cases: Dict):
    return validate_program_with_assertions(secure_src, insecure_src, test_cases)
