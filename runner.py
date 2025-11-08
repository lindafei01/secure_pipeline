import os, json
from generator_c import generate_code_and_tests
from validator_c import validate_program
from datetime import datetime

def run_pipeline(task_path):
    with open(task_path) as f:
        task = json.load(f)

    cwe_id = task["cwe_id"]
    task_name = task["task_name"].replace(" ", "_")
    output_dir = os.path.join("outputs", cwe_id, f"{cwe_id}__{task_name}")
    os.makedirs(output_dir, exist_ok=True)

    print(f"[+] Generating and validating {task_name} ({cwe_id})...")
    generate_code_and_tests(task, output_dir)

    test_path = os.path.join(output_dir, "test_cases.json")
    with open(test_path) as f:
        test_cases = json.load(f)

    result = validate_program(
        os.path.join(output_dir, "secure.c"),
        os.path.join(output_dir, "insecure.c"),
        test_cases
    )

    result_path = os.path.join(output_dir, "validation.json")
    with open(result_path, "w") as f:
        json.dump(result, f, indent=2)

    print(f"[✓] Validation result: {result}")
    return result
