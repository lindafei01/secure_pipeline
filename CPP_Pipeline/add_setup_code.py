import json

SETUP_CODE = """#include <bits/stdc++.h>
using namespace std;

// Shared helper functions can be defined here
"""


def add_setup_code_to_dataset(input_file: str, output_file: str):
    with open(input_file, "r", encoding="utf-8") as f:
        tasks = json.load(f)

    for task in tasks:
        task.setdefault("setup_code", SETUP_CODE)

    with open(output_file, "w", encoding="utf-8") as f:
        json.dump(tasks, f, indent=2, ensure_ascii=False)

    print(f"✅ Added setup_code to {len(tasks)} tasks")
    print(f"📁 Output written to: {output_file}")


if __name__ == "__main__":
    add_setup_code_to_dataset("tasks/CWE-000_tasks.json", "tasks/CWE-000_tasks.json")
