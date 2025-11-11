import os
from typing import Dict

import yaml
from utils.cpp_compiler import compile_cpp
from utils.cpp_runner import run_binary


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


def validate_program(secure_src: str, insecure_src: str, test_cases: Dict):
    secure_src = os.path.abspath(secure_src)
    insecure_src = os.path.abspath(insecure_src)
    secure_dir = os.path.dirname(secure_src)
    insecure_dir = os.path.dirname(insecure_src)

    if not test_cases.get("functional") and not test_cases.get("security"):
        fallback = load_test_cases_fallback(secure_dir)
        if fallback:
            test_cases = fallback

    secure_binary = os.path.join(secure_dir, "secure.out")
    insecure_binary = os.path.join(insecure_dir, "insecure.out")

    secure_compile = compile_cpp([secure_src], secure_binary, fail_on_error=False)
    insecure_compile = compile_cpp([insecure_src], insecure_binary, fail_on_error=False)

    if secure_compile:
        return {
            "secure_func_pass": False,
            "secure_sec_pass": False,
            "insecure_func_pass": False,
            "insecure_sec_fail": False,
            "summary": "Secure version failed to compile",
            "secure_compile_error": secure_compile.get("stderr", ""),
            "statistics": {
                "FUNCTION TOTAL": len(test_cases.get("functional", [])),
                "FUNCTION PASS (secure)": 0,
                "FUNCTION PASS (insecure)": 0,
                "SECURITY TOTAL": len(test_cases.get("security", [])),
                "SECURITY PASS (secure)": 0,
                "SECURITY PASS (insecure)": 0,
                "REQUIRES_INSECURE_IVULNERABLE": False,
            },
            "detailed_results": {"functional_tests": [], "security_tests": []},
            "valid_sample": False,
            "compilation_issue": True,
        }

    if insecure_compile:
        print("[+] Note: Insecure version failed to compile - treating as vulnerability")

    secure_func_pass = True
    secure_sec_pass = True
    insecure_func_pass = True
    insecure_sec_fail = bool(insecure_compile)

    func_total = len(test_cases.get("functional", []))
    sec_total = len(test_cases.get("security", []))

    func_pass_count_secure = 0
    func_pass_count_insecure = 0
    sec_pass_count_secure = 0
    sec_pass_count_insecure = 0

    detailed_results = {"functional_tests": [], "security_tests": []}

    def run_secure(args):
        return run_binary(secure_binary, args)

    def run_insecure(args):
        if insecure_compile:
            return {"stdout": "COMPILATION_FAILED", "stderr": insecure_compile.get("stderr", ""), "exit_code": 1}
        return run_binary(insecure_binary, args)

    for case in test_cases.get("functional", []):
        inp = str(case.get("input", ""))
        expected = str(case.get("expected_output", ""))
        args = _normalize_args(inp)

        res_secure = run_secure(args)
        res_insecure = run_insecure(args)

        secure_pass = res_secure["stdout"] == expected
        insecure_pass = res_insecure["stdout"] == expected

        detailed_results["functional_tests"].append(
            {
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
        )

        if secure_pass:
            func_pass_count_secure += 1
        else:
            secure_func_pass = False

        if insecure_pass:
            func_pass_count_insecure += 1
        else:
            insecure_func_pass = False

    for case in test_cases.get("security", []):
        inp = str(case.get("input", ""))
        expected = str(case.get("expected_output", ""))
        args = _normalize_args(inp)

        res_secure = run_secure(args)
        res_insecure = run_insecure(args)

        secure_pass = res_secure["exit_code"] == 0 and res_secure["stdout"] == expected
        insecure_pass = res_insecure["exit_code"] == 0 and res_insecure["stdout"] == expected

        detailed_results["security_tests"].append(
            {
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
        )

        if secure_pass:
            sec_pass_count_secure += 1
        if insecure_pass:
            sec_pass_count_insecure += 1
        if not insecure_pass:
            insecure_sec_fail = True

    statistics = {
        "FUNCTION TOTAL": func_total,
        "FUNCTION PASS (secure)": func_pass_count_secure,
        "FUNCTION PASS (insecure)": func_pass_count_insecure,
        "SECURITY TOTAL": sec_total,
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
        "statistics": statistics,
        "error_rate_insecure": sec_total - sec_pass_count_insecure if sec_total > 0 else 0,
        "detailed_results": detailed_results,
        "valid_sample": valid_sample,
    }
