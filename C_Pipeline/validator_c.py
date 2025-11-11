import os, json
from utils.compiler import compile_c
from utils.safe_exec import run_binary

def validate_program(secure_src, insecure_src, test_cases):
    compile_c([secure_src], "secure_complete.out")
    compile_c([insecure_src], "insecure_complete.out")

    # Initialization states
    secure_func_pass = True  # Secure must通过所有功能测试
    secure_sec_pass = True   # Secure必须正确、安全地处理各种情况
    insecure_func_pass = True # Insecure必须通过所有功能测试
    insecure_sec_fail = False  # Insecure必须在至少一个安全测试中失败

    func_total = len(test_cases.get("functional", []))
    sec_total = len(test_cases.get("security", []))

    func_pass_count_secure = 0
    func_pass_count_insecure = 0
    sec_pass_count_secure = 0
    sec_pass_count_insecure = 0

    # 详细的测试用例执行结果记录
    detailed_results = {
        "functional_tests": [],
        "security_tests": []
    }

    # Functional tests - 修改以支持多参数
    for case in test_cases.get("functional", []):
        inp = str(case["input"])
        exp = str(case["expected_output"])

        # 将单个字符串按空格分割成多个参数
        args = inp.split() if inp.strip() else [""]

        res_s = run_binary("./secure_complete.out", args)
        res_i = run_binary("./insecure_complete.out", args)

        # 记录详细结果
        secure_pass = (res_s["stdout"] == exp)
        insecure_pass = (res_i["stdout"] == exp)

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
        detailed_results["functional_tests"].append(test_result)

        # 统计 Secure 通过率
        if secure_pass:
            func_pass_count_secure += 1
        else:
            secure_func_pass = False

        # 统计 Insecure 通过率
        if insecure_pass:
            func_pass_count_insecure += 1
        else:
            insecure_func_pass = False

    # Security tests - 同时运行 secure 和 insecure 版本，记录对比结果
    for case in test_cases.get("security", []):
        inp = str(case["input"])
        exp = str(case["expected_output"])

        # 将单个字符串按空格分割成多个参数（与functional测试一样）
        args = inp.split() if inp.strip() else [""]

        # 运行两个版本
        res_s = run_binary("./secure_complete.out", args)
        res_i = run_binary("./insecure_complete.out", args)

        # 计算通过状态
        secure_pass = (res_s["exit_code"] == 0 and res_s["stdout"] == exp)
        insecure_pass = (res_i["exit_code"] == 0 and res_i["stdout"] == exp)

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
        detailed_results["security_tests"].append(test_result)

        # 统计通过率 - secure必须大于insecure
        if secure_pass:
            sec_pass_count_secure += 1
        if insecure_pass:
            sec_pass_count_insecure += 1

        # Insecure失败是期望的 (表示检测到漏洞)
        if not insecure_pass:
            insecure_sec_fail = True

    # 最终验收标准：
    # 1. Secure必须通过所有FUNCTION测试
    # 2. Insecure不需要通过所有FUNCTION测试
    # 3. Secure在安全测试中的通过率必须 **高于** insecure
    valid_sample = (secure_func_pass and
                   (sec_pass_count_secure > sec_pass_count_insecure))

    return {
        "secure_func_pass": secure_func_pass,
        "secure_sec_pass": secure_sec_pass,
        "insecure_func_pass": insecure_func_pass,
        "insecure_sec_fail": insecure_sec_fail,
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
