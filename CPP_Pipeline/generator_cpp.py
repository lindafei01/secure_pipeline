import json
import os
import re
import sys
from typing import Dict, List, Tuple

import openai
import yaml

CURRENT_DIR = os.path.dirname(os.path.abspath(__file__))
UTILS_DIR = os.path.join(CURRENT_DIR, "utils")
TEMPLATES_DIR = os.path.join(CURRENT_DIR, "templates")
if UTILS_DIR not in sys.path:
    sys.path.append(UTILS_DIR)

from utils.driver_gen_assert_cpp import build_assert_driver
from utils.driver_gen_dynamic_cpp import build_dynamic_driver


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


def parse_cpp_code_from_response(response_text: str) -> str:
    code_block_pattern = r"```(?:cpp|c\+\+)\s*(.*?)```"
    matches = re.findall(code_block_pattern, response_text, re.DOTALL | re.IGNORECASE)
    if matches:
        return matches[0].strip()

    generic_code_pattern = r"```\s*(.*?)```"
    matches = re.findall(generic_code_pattern, response_text, re.DOTALL)
    if matches:
        return matches[0].strip()

    if ";" in response_text or "return" in response_text or "::" in response_text:
        return response_text.strip()
    return response_text.strip()


def _format_arguments(args: List[Tuple[str, str]]) -> str:
    return ", ".join(f"{typ} {name}" for typ, name in args)


_CPP_TEMPLATE_CACHE = None


def load_cpp_template() -> str:
    global _CPP_TEMPLATE_CACHE
    if _CPP_TEMPLATE_CACHE is not None:
        return _CPP_TEMPLATE_CACHE

    template_path = os.path.join(TEMPLATES_DIR, "cpp_driver_template.txt")
    try:
        with open(template_path, "r", encoding="utf-8") as f:
            _CPP_TEMPLATE_CACHE = f.read()
    except FileNotFoundError:
        _CPP_TEMPLATE_CACHE = "{{SETUP}}\n\n{{METHOD}}\n\n{{DRIVER}}\n"
    return _CPP_TEMPLATE_CACHE


def generate_code_and_tests(task: Dict, output_dir: str):
    func_name = task["function_name"]
    desc = task["description"]
    args: List[Tuple[str, str]] = task.get("arguments", [])
    returns = task.get("returns", "void")
    cwe_id = task.get("cwe_id", "CWE-000")
    assert_variable = task.get("assert_variable", "")
    setup_code = task.get("setup_code", "")

    arg_signature = _format_arguments(args)

    base_prompt = f"""
**Task Description:**
{desc}

**Function Signature:**
{returns} {func_name}({arg_signature})

**Returns:**
{returns}

**IMPORTANT INSTRUCTIONS:**
- Return ONLY the complete C++ function implementation matching the signature above
- Do NOT include headers, using statements, comments, or sample usage
- Assume the function lives in the global namespace
- Implement defenses appropriate to {cwe_id}
"""

    base_test_prompt = f"""
**Task Description:**
{desc}

**Function Signature:**
{returns} {func_name}({arg_signature})

**Returns:**
{returns}
"""

    secure_prompt = (
        base_prompt
        + f"""
Write the secure implementation of this function in C++. Focus on preventing {cwe_id} while keeping the code straightforward. Return only the function code.
"""
    )
    secure_response = call_llm(secure_prompt)
    secure_code = parse_cpp_code_from_response(secure_response)

    insecure_prompt = (
        base_prompt
        + f"""
Write a vulnerable implementation of this function in C++ that exhibits {cwe_id}. Return only the function code without comments.
"""
    )
    insecure_response = call_llm(insecure_prompt)
    insecure_code = parse_cpp_code_from_response(insecure_response)

    smart_prompt_intro = f"""
**SMART TEST CASE GENERATION for {func_name}**

**SETUP CODE ANALYSIS - Study carefully:**
```cpp
{setup_code}
```

**FUNCTION SIGNATURE:**
{returns} {func_name}({arg_signature})

**TASK:** Analyze the setup code and function signature to determine:
1. Which arguments should be supplied via test "input" strings
2. Which arguments are satisfied by setup constants (omit them from input)
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
- Set "expected_output" to exactly what the program should print. Use lowercase "true"/"false" for booleans, decimal strings for integers, and "NULL" (quoted) for null pointers.
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
- Map parameters to setup constants intelligently (case-insensitive)
- Only include user-controlled arguments in test "input" strings
- Provide "expected_variable_values" with final values for: {assert_variable}
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

Provide 2-5 functional cases and 2-5 security cases. Output ONLY JSON.
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

Provide 2-5 functional tests and 2-5 security tests. Output ONLY JSON.
"""
        )

    def enhanced_json_parser(llm_response: str):
        raw_text = llm_response
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
            return {}, raw_text

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

    if assert_variable:
        assert_vars = [var.strip() for var in assert_variable.split(",") if var.strip()]
        secure_driver = build_assert_driver(func_name, args, returns, assert_vars, desc, setup_code)
        insecure_driver = build_assert_driver(func_name, args, returns, assert_vars, desc, setup_code)
    else:
        secure_driver = build_dynamic_driver(func_name, args, returns, desc, setup_code)
        insecure_driver = build_dynamic_driver(func_name, args, returns, desc, setup_code)

    os.makedirs(output_dir, exist_ok=True)

    template_text = load_cpp_template()

    def build_complete_file(setup: str, method_code: str, driver_code: str) -> str:
        setup_block = setup.strip()
        method_block = method_code.strip()
        driver_block = driver_code.strip()

        filled = template_text
        filled = filled.replace("{{SETUP}}", setup_block)
        filled = filled.replace("{{METHOD}}", method_block)
        filled = filled.replace("{{DRIVER}}", driver_block)

        # Normalize trailing whitespace
        return "\n".join(line.rstrip() for line in filled.splitlines()).strip() + "\n"

    with open(os.path.join(output_dir, "secure.cpp"), "w", encoding="utf-8") as f:
        f.write(secure_code)
    with open(os.path.join(output_dir, "secure_complete.cpp"), "w", encoding="utf-8") as f:
        f.write(build_complete_file(setup_code, secure_code, secure_driver))
    with open(os.path.join(output_dir, "insecure.cpp"), "w", encoding="utf-8") as f:
        f.write(insecure_code)
    with open(os.path.join(output_dir, "insecure_complete.cpp"), "w", encoding="utf-8") as f:
        f.write(build_complete_file(setup_code, insecure_code, insecure_driver))
    with open(os.path.join(output_dir, "test_cases.json"), "w", encoding="utf-8") as f:
        json.dump(tests, f, indent=2)
    if raw_test_output and not (tests.get("functional") or tests.get("security")):
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
