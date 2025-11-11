import json
import os

import yaml

from generator_js import generate_code_and_tests
from validator_js_assert import validate_program

BASE_DIR = os.path.dirname(os.path.abspath(__file__))
OUTPUTS_ROOT = os.path.join(BASE_DIR, "outputs")


def run_pipeline(task_path: str):
    with open(task_path, encoding="utf-8") as f:
        task_data = json.load(f)

    if isinstance(task_data, list):
        for task in task_data:
            process_single_task(task)
    else:
        process_single_task(task_data)


def process_single_task(task):
    cwe_id = task["cwe_id"]
    task_name = task["task_name"].replace(" ", "_")
    output_dir = os.path.join(OUTPUTS_ROOT, cwe_id, f"{cwe_id}__{task_name}")

    if os.path.exists(output_dir):
        print(f"[-] Skipping {task_name} ({cwe_id}) - already exists at {output_dir}")
        return

    os.makedirs(output_dir, exist_ok=True)
    print(f"[+] Generating and validating {task_name} ({cwe_id})...")

    generate_code_and_tests(task, output_dir)

    test_cases = load_test_cases_with_yaml_fallback(output_dir)

    result = validate_program(
        os.path.join(output_dir, "secure_complete.js"),
        os.path.join(output_dir, "insecure_complete.js"),
        test_cases,
    )

    result_path = os.path.join(output_dir, "validation.json")
    with open(result_path, "w", encoding="utf-8") as f:
        json.dump(result, f, indent=2)

    stats = result.get("statistics", {})
    func_total = stats.get("FUNCTION TOTAL", 0)
    func_pass_secure = stats.get("FUNCTION PASS (secure)", 0)
    func_pass_insecure = stats.get("FUNCTION PASS (insecure)", 0)

    sec_total = stats.get("SECURITY TOTAL", 0)
    sec_pass_secure = stats.get("SECURITY PASS (secure)", 0)
    sec_pass_insecure = stats.get("SECURITY PASS (insecure)", 0)

    print(f"FUNCTION TOTAL: {func_total}")
    print(f"FUNCTION PASS (secure): {func_pass_secure}")
    print(f"FUNCTION PASS (insecure): {func_pass_insecure}")
    print(f"SECURITY TOTAL: {sec_total}")
    print(f"SECURITY PASS (secure): {sec_pass_secure}")
    print(f"SECURITY PASS (insecure): {sec_pass_insecure}")

    if result.get("valid_sample"):
        status = "✅ VALID"
        details = f"Secure={sec_pass_secure}/{sec_total}, Insecure={sec_pass_insecure}/{sec_total}"
    else:
        status = "❌ INVALID"
        issues = []
        if not result.get("secure_func_pass"):
            issues.append("Secure failed function tests")
        if sec_pass_secure <= sec_pass_insecure:
            issues.append("Insecure not vulnerable enough")
        details = f"Issues: {', '.join(issues)}"

    print(f"[{status}] {details}")
    print(f"[{status}] Security comparison - S:{sec_pass_secure}/{sec_total} vs I:{sec_pass_insecure}/{sec_total}")

    return result


def load_test_cases_with_yaml_fallback(output_dir: str):
    test_path = os.path.join(output_dir, "test_cases.json")
    try:
        with open(test_path, encoding="utf-8") as f:
            return json.load(f)
    except (json.JSONDecodeError, FileNotFoundError) as exc:
        print(f"[!] Warning: Failed to load JSON test cases ({exc}). Trying YAML fallback.")

    yaml_path = os.path.join(output_dir, "test_cases_raw.yaml")
    if os.path.exists(yaml_path):
        try:
            with open(yaml_path, "r", encoding="utf-8") as f:
                data = yaml.safe_load(f)
            if isinstance(data, dict):
                if "functional" in data or "security" in data:
                    return data
            if isinstance(data, list):
                return {"functional": data, "security": []}
        except Exception as exc:
            print(f"[!] Warning: Failed to load YAML fallback ({exc}).")

    return {"functional": [], "security": []}
