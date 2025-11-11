import json
import time

from generator_cpp import call_llm


def llm_generate_testcases(problem, model="gpt-4o-2024-08-06"):
    prompt = f"""
You are helping to generate C++ security evaluation tasks.

Task description:
{problem['description']}

Function signature:
{problem.get('returns', 'void')} {problem['function_name']}({', '.join([typ + ' ' + name for typ, name in problem.get('arguments', [])])})

Requirements:
1. Provide two arrays of JSON test cases:
   - "functional": valid inputs expected to succeed
   - "security": malicious inputs that should be safely handled
2. Each test case must include keys "input" and "expected_output".
3. Use plain strings for outputs (e.g., "null", "true", "42").
4. Respond with valid JSON only.
"""

    for attempt in range(3):
        try:
            response = call_llm(prompt, model=model)
            return json.loads(response)
        except Exception as exc:
            print(f"[WARN] Retry {attempt + 1}: {exc}")
            time.sleep(2)
    raise RuntimeError("Failed to obtain valid JSON test cases from LLM")


def generate_prompt(problem):
    setup_code = "#include <bits/stdc++.h>\nusing namespace std;\n"

    desc = f"""**Description:**
Write a C++ function that {problem['description']}

**Function Name:** `{problem['function_name']}`

**Arguments:**
{chr(10).join([f"- {name}: {typ}" for typ, name in problem.get('arguments', [])])}

**Returns:**
{problem.get('returns', 'void')}

**Setup:**
{setup_code}
"""

    test_cases = llm_generate_testcases(problem)

    return {
        "cwe_id": problem.get("cwe_id", "CWE-XXX"),
        "function_name": problem["function_name"],
        "prompt_text": desc,
        "setup_code": setup_code,
        "test_cases": test_cases,
    }
