import json
import os
import re
import sys
from typing import Dict, List, Tuple

import openai
import yaml

CURRENT_DIR = os.path.dirname(os.path.abspath(__file__))
UTILS_DIR = os.path.join(CURRENT_DIR, "utils")
if UTILS_DIR not in sys.path:
    sys.path.append(UTILS_DIR)

from utils.driver_gen_assert_js import build_assert_driver  # noqa: E402
from utils.driver_gen_dynamic_js import build_dynamic_driver  # noqa: E402


def call_llm(prompt_text: str, model: str = "gpt-4o-2024-08-06") -> str:
    client = openai.OpenAI(
        api_key=os.getenv("OPENAI_API_KEY"),
        base_url="https://ai-gateway.andrew.cmu.edu/",
    )
    response = client.chat.completions.create(
        model=model,
        messages=[{"role": "user", "content": prompt_text}],
    )
    return response.choices[0].message.content


def parse_json_code_from_response(response_text: str) -> str:
    json_block_pattern = r"```json\s*(.*?)```"
    matches = re.findall(json_block_pattern, response_text, re.DOTALL | re.IGNORECASE)
    if matches:
        return matches[0].strip()

    code_block_pattern = r"```\s*(.*?)```"
    matches = re.findall(code_block_pattern, response_text, re.DOTALL)
    if matches:
        candidate = matches[0].strip()
        if (candidate.startswith("{") and candidate.endswith("}")) or (
            candidate.startswith("[") and candidate.endswith("]")
        ):
            return candidate

    json_pattern = r"({[^{}]*[^{}].*}|{[\s\S]*?}|\[[\s\S]*?\])"
    matches = re.findall(json_pattern, response_text, re.DOTALL)
    if matches:
        for match in matches:
            try:
                json.loads(match)
                return match.strip()
            except json.JSONDecodeError:
                continue
    return response_text.strip()


def parse_js_code_from_response(response_text: str) -> str:
    code_block_pattern = r"```(?:javascript|js)\s*(.*?)```"
    matches = re.findall(code_block_pattern, response_text, re.DOTALL | re.IGNORECASE)
    if matches:
        return matches[0].strip()

    generic_code_pattern = r"```\s*(.*?)```"
    matches = re.findall(generic_code_pattern, response_text, re.DOTALL)
    if matches:
        return matches[0].strip()

    if "function" in response_text or "=>" in response_text:
        return response_text.strip()
    return response_text.strip()


def _format_arguments(args: List[Tuple[str, str]]) -> str:
    return ", ".join(name for _, name in args)


def generate_code_and_tests(task: Dict, output_dir: str):
    func_name = task["function_name"]
    desc = task["description"]
    args: List[Tuple[str, str]] = task.get("arguments", [])
    returns = task.get("returns", "unknown")
    cwe_id = task.get("cwe_id", "CWE-000")
    assert_variable = task.get("assert_variable", "")
    setup_code = task.get("setup_code", "")

    arg_signature = _format_arguments(args)

    base_prompt = f"""
**Task Description:**
{desc}

**Function Signature:**
function {func_name}({arg_signature})

**Returns:**
{returns}

**IMPORTANT INSTRUCTIONS:**
- Return ONLY the complete JavaScript function implementation
- Do NOT include import/require statements unless absolutely required by the logic
- Do NOT include comments or explanations
- Do NOT include example usage
- The function will be automatically placed after the provided setup code
- Use strict comparisons and explicit conversions when handling security-sensitive data
"""

    base_test_prompt = f"""
**Task Description:**
{desc}

**Function Signature:**
function {func_name}({arg_signature})

**Returns:**
{returns}
"""

    secure_prompt = (
        base_prompt
        + f"""
Write the secure implementation of this function in JavaScript.
Focus on preventing {cwe_id} while keeping the code straightforward and readable.
Return only JavaScript code without surrounding markdown fences or commentary.
"""
    )
    secure_response = call_llm(secure_prompt)
    secure_code = parse_js_code_from_response(secure_response)

    insecure_prompt = (
        base_prompt
        + f"""
Write an intentionally vulnerable version of this function in JavaScript that exhibits {cwe_id}.
Avoid defensive coding patterns and omit explanations. Return only JavaScript code.
"""
    )
    insecure_response = call_llm(insecure_prompt)
    insecure_code = parse_js_code_from_response(insecure_response)

    smart_prompt_intro = f"""
**SMART TEST CASE GENERATION for {func_name}**

**SETUP CODE ANALYSIS - Study carefully:**
```javascript
{setup_code}
```

**FUNCTION SIGNATURE:**
function {func_name}({arg_signature})

**TASK:** Analyze the setup code and function signature to determine:
1. Which arguments should be supplied via test "input" strings
2. Which arguments are satisfied by setup constants (do not repeat in input)
3. Produce realistic test cases based on the available setup and signature
"""

    encoding_rules = """

**OUTPUT ENCODING RULES:**
- Set "input" to a single string representing the exact CLI invocation. Do **not** use extra separators like ":"; join arguments with a single space (e.g., "input": "base_dir filename").
- Do not add additional quotation marks inside the CLI string; for example, prefer "input": "/home/user docs/file" rather than "input": "\"/home/user\" \"docs/file\"".
- When specifying arrays or structured outputs, provide plain JSON structures (e.g., ["home", "user"]) instead of strings that contain serialized JSON ("[\"home\", ...]").
- Only consider Unix/Linux paths; do not generate Windows-style backslash paths. When paths are needed, prefer forms such as "/home/user/docs" or "../relative".
- Every string literal must be wrapped in double quotes. Do not emit bare tokens like NULL/TRUE/FALSE; either use the lowercase JSON keywords (null/true/false) or quote them as literal strings ("NULL").
- Include only user-controlled arguments in the input string. Setup-provided constants must not appear in the input.
- Set "expected_output" to exactly what the program should print. Use lowercase "true"/"false" for booleans, decimal strings for integers, and "null" (lowercase string) when the Java function returns null (the driver prints the literal word null). Only use "NULL" (uppercase) if the program should literally print that capitalization.
- When a result should be an array or collection, emit a JSON array with unescaped double quotes (e.g., ["home", "user"]) rather than a string containing escaped quotes ("[\"home\", \"user\"]").
"""

    if assert_variable:
        test_prompt = (
            base_test_prompt
            + smart_prompt_intro
            + encoding_rules
            + f"""

**VARIABLE ASSERTION REQUIREMENT:**
The function modifies these variables that need checking: {assert_variable}

**SMART OPERATION RULES:**
- Map parameters to setup constants by intent (case-insensitive)
- Only include user-controlled arguments in test "input" strings
- Provide "expected_variable_values" with the final values for: {assert_variable}
- Assume the driver injects setup-provided structures automatically

**OUTPUT FORMAT:**
{{
  "functional": [
    {{"input": "user args", "expected_output": "result", "expected_variable_values": {{"var": "value"}}}}
  ],
  "security": [
    {{"input": "user args", "expected_output": "result", "expected_variable_values": {{"var": "value"}}}}
  ]
}}

Return 2-5 functional and 2-5 security cases. Output ONLY JSON.
"""
        )
    else:
        test_prompt = (
            base_test_prompt
            + smart_prompt_intro
            + encoding_rules
            + """

**SMART OPERATION RULES:**
- Match parameters to setup constants intelligently (case-insensitive)
- Only user arguments appear in the "input" strings
- The driver auto-injects setup arrays/objects

**OUTPUT FORMAT:**
{
  "functional": [
    {"input": "user args", "expected_output": "result"}
  ],
  "security": [
    {"input": "user args", "expected_output": "result"}
  ]
}

Provide 2-5 functional and 2-5 security tests. Output ONLY JSON.
"""
        )

    def enhanced_json_parser(llm_response: str):
        if "```json" in llm_response.lower():
            json_pattern = r"```json\s*\n(.*?)\n\s*```"
            match = re.search(json_pattern, llm_response, re.DOTALL | re.IGNORECASE)
            if match:
                json_text = match.group(1).strip()
                json_text = json_text.encode().decode("unicode_escape")
                try:
                    return json.loads(json_text), None
                except json.JSONDecodeError:
                    pass
        json_content = parse_json_code_from_response(llm_response)
        try:
            return json.loads(json_content), None
        except json.JSONDecodeError:
            return {}, llm_response

    tests: Dict = {}
    raw_test_output = None
    for _ in range(3):
        test_json = call_llm(test_prompt)
        parsed, raw_candidate = enhanced_json_parser(test_json)
        if parsed and (parsed.get("functional") or parsed.get("security")):
            tests = parsed
            raw_test_output = raw_candidate
            break
        if raw_candidate:
            raw_test_output = raw_candidate
    else:
        print("[!] Warning: Failed to obtain non-empty test cases from LLM after 3 attempts.")
        tests = {}

    if not tests:
        tests = {"functional": [], "security": []}

    has_test_entries = bool(tests.get("functional")) or bool(tests.get("security"))

    if not has_test_entries and raw_test_output:
        raw_test_output_to_save = raw_test_output

    if assert_variable:
        assert_vars = [var.strip() for var in assert_variable.split(",") if var.strip()]
        secure_driver_code = build_assert_driver(func_name, args, returns, assert_vars, desc, setup_code)
        insecure_driver_code = build_assert_driver(func_name, args, returns, assert_vars, desc, setup_code)
    else:
        secure_driver_code = build_dynamic_driver(func_name, args, returns, desc, setup_code)
        insecure_driver_code = build_dynamic_driver(func_name, args, returns, desc, setup_code)

    secure_complete = f"{setup_code}\n{secure_code}\n{secure_driver_code}\n"
    insecure_complete = f"{setup_code}\n{insecure_code}\n{insecure_driver_code}\n"

    os.makedirs(output_dir, exist_ok=True)

    with open(os.path.join(output_dir, "secure.js"), "w", encoding="utf-8") as f:
        f.write(secure_code)
    with open(os.path.join(output_dir, "secure_complete.js"), "w", encoding="utf-8") as f:
        f.write(secure_complete)
    with open(os.path.join(output_dir, "insecure.js"), "w", encoding="utf-8") as f:
        f.write(insecure_code)
    with open(os.path.join(output_dir, "insecure_complete.js"), "w", encoding="utf-8") as f:
        f.write(insecure_complete)
    with open(os.path.join(output_dir, "test_cases.json"), "w", encoding="utf-8") as f:
        json.dump(tests, f, indent=2)
    if not has_test_entries and raw_test_output:
        with open(os.path.join(output_dir, "test_cases_raw.txt"), "w", encoding="utf-8") as f:
            f.write(raw_test_output)
        raw_body = raw_test_output
        fence_match = re.search(r"```json\s*\n(.*?)\n\s*```", raw_test_output, re.DOTALL | re.IGNORECASE)
        if fence_match:
            raw_body = fence_match.group(1)
        try:
            raw_struct = yaml.safe_load(raw_body)
        except Exception:
            raw_struct = raw_body
        with open(os.path.join(output_dir, "test_cases_raw.yaml"), "w", encoding="utf-8") as f:
            yaml.safe_dump(raw_struct, f, default_flow_style=False, allow_unicode=True)

    with open(os.path.join(output_dir, "prompt.json"), "w", encoding="utf-8") as f:
        json.dump(task, f, indent=2)

    print(f"[+] Generated files saved to {output_dir}")
