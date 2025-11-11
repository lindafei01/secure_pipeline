import json

SETUP_CODE = """"use strict";

// Common utilities available to every generated snippet
const path = require('path');
const url = require('url');
const crypto = require('crypto');

"""


def add_setup_code_to_dataset(input_file: str, output_file: str):
    with open(input_file, "r", encoding="utf-8") as f:
        tasks = json.load(f)

    for task in tasks:
        task["setup_code"] = task.get("setup_code") or SETUP_CODE

    with open(output_file, "w", encoding="utf-8") as f:
        json.dump(tasks, f, indent=2, ensure_ascii=False)

    print(f"✅ Added setup_code to {len(tasks)} tasks")
    print(f"📁 Output written to: {output_file}")


if __name__ == "__main__":
    add_setup_code_to_dataset("tasks/CWE-000_tasks.json", "tasks/CWE-000_tasks.json")
