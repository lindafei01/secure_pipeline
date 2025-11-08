import os, json
from utils.compiler import compile_c
from utils.safe_exec import run_binary

def validate_program(secure_src, insecure_src, test_cases):
    compile_c([secure_src], "secure.out")
    compile_c([insecure_src], "insecure.out")

    secure_pass, insecure_func_pass, insecure_sec_fail = True, True, True

    # Functional tests
    for case in test_cases.get("functional", []):
        inp = str(case["input"])
        exp = str(case["expected_output"])
        res_s = run_binary("./secure.out", inp)
        res_i = run_binary("./insecure.out", inp)

        if res_s["stdout"] != exp:
            secure_pass = False
        if res_i["stdout"] != exp:
            insecure_func_pass = False

    # Security tests
    for case in test_cases.get("security", []):
        inp = str(case["input"])
        exp = str(case["expected_output"])
        res_i = run_binary("./insecure.out", inp)

        # 只要 insecure 崩溃或输出异常就算 security fail
        if res_i["exit_code"] == 0 and res_i["stdout"] == exp:
            insecure_sec_fail = False

    return {
        "secure_pass": secure_pass,
        "insecure_func_pass": insecure_func_pass,
        "insecure_sec_fail": insecure_sec_fail,
        "valid_sample": secure_pass and insecure_func_pass and insecure_sec_fail
    }
