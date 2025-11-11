import openai
import json
import os
import re
import sys
sys.path.append('utils')
# Use dynamic driver generator instead of hard-coded generators
# from driver_gen import build_main_driver
from utils.driver_gen_dynamic import build_dynamic_driver  # Zero hard-code driver
from utils.driver_gen_assert import build_assert_driver    # Variable assertion support
import yaml

def call_llm(prompt_text, model="gpt-4o-2024-08-06"):
    client = openai.OpenAI(
        api_key=os.getenv("OPENAI_API_KEY"),
        base_url="https://ai-gateway.andrew.cmu.edu/"
    )
    response = client.chat.completions.create(
        model=model, # model to send to the proxy
        messages = [
            {
            "role": "user",
            "content": prompt_text
            }
        ]
    )

    return response.choices[0].message.content

def parse_json_code_from_response(response_text):
    """Parse JSON code from LLM response, extracting from markdown blocks"""
    import re

    # Method 1: Look for ```json ... ``` code blocks
    json_block_pattern = r'```json\n(.*?)\n```'
    matches = re.findall(json_block_pattern, response_text, re.DOTALL)

    if matches:
        return matches[0].strip()

    # Method 2: Look for ``` ... ``` code blocks (generic)
    code_block_pattern = r'```\n(.*?)\n```'
    matches = re.findall(code_block_pattern, response_text, re.DOTALL)

    if matches:
        # Check if it looks like JSON
        first_match = matches[0].strip()
        if (first_match.startswith('{') and first_match.endswith('}')) or \
           (first_match.startswith('[') and first_match.endswith(']')):
            return first_match

    # Method 3: Look for JSON in plain text
    # Find JSON object or array
    json_pattern = r'({[^{}]*[^{}].*}|{[\s\S]*?}|\[[\s\S]*?\])'
    matches = re.findall(json_pattern, response_text, re.DOTALL)

    if matches:
        for match in matches:
            try:
                json.loads(match)  # Validate it's parseable JSON
                return match.strip()
            except json.JSONDecodeError:
                continue

    # Method 4: Return the whole thing if nothing else works
    return response_text.strip()

def parse_c_code_from_response(response_text):
    """Parse C code from LLM response, extracting code from markdown blocks"""

    # Method 1: Look for ```c ... ``` code blocks (case-insensitive)
    code_block_pattern = r'```[cC]\n(.*?)\n```'
    matches = re.findall(code_block_pattern, response_text, re.DOTALL)

    if matches:
        return matches[0].strip()

    # Method 2: Look for any ``` ... ``` code block
    generic_code_pattern = r'```\n(.*?)\n```'
    matches = re.findall(generic_code_pattern, response_text, re.DOTALL)

    if matches:
        return matches[0].strip()

    # Method 3: If no code blocks but contains C syntax, return as is
    if any(keyword in response_text for keyword in ['#include', 'int ', 'char*', 'void ', 'return']):
        return response_text.strip()

    # Method 4: Return original if nothing else found
    return response_text.strip()

def generate_code_and_tests(task, output_dir):
    func_name = task["function_name"]
    desc = task["description"]
    args = task["arguments"]
    returns = task["returns"]
    cwe_id = task["cwe_id"]
    assert_variable = task.get("assert_variable", "")

    # setup code 统一
    setup_code = task["setup_code"]

    # 构造 prompt
    base_prompt = f"""
**Task Description:**
{desc}

**Function Signature:**
{func_name}({', '.join([t+' '+n for t,n in args])});

** Returns:**
{returns}

**IMPORTANT INSTRUCTIONS:**
- Return ONLY the complete function implementation
- Do NOT include any #include statements
- Do NOT include comments
- Do NOT include example usage
- The function will be automatically placed after setup code
- Write the exact function signature as specified above
"""
    # 构造 prompt
    base_test_prompt = f"""
**Task Description:**
{desc}

**Function Signature:**
{func_name}({', '.join([t+' '+n for t,n in args])});

** Returns:**
{returns}
"""

    # --- secure ---
    secure_prompt = base_prompt + f"""\nWrite the secure implementation of this function.
Important: Pay attention to {cwe_id}. But don't generate overly defensive code since there won't be super-edge cases.
Return only pure C code without comments or explanations.
Write self-contained code, don't assume there are other helper functions. You may write helper functions yourself if necessary.

Example output:
```c
Your implementation goes here.
```
"""
    secure_response = call_llm(secure_prompt)
    secure_code = parse_c_code_from_response(secure_response)

    # --- insecure ---
    insecure_prompt = base_prompt + f"""\nWrite a vulnerable version of this function that contains {cwe_id}.
Avoid comments or explanations, just return the C code.
Write self-contained code, don't assume there are other helper functions. You may write helper functions yourself if necessary.

Example output:
```c
Your implementation goes here.
```
    """
    insecure_response = call_llm(insecure_prompt)
    insecure_code = parse_c_code_from_response(insecure_response)
    
    # --- test cases ---
    # AI分析步骤：让AI自己阅读setup_code并决定哪些参数需要用户提供，哪些通过setup注入
    smart_prompt_intro = f"""
**SMART TEST CASE GENERATION for {func_name}**

**SETUP CODE ANALYSIS - Study carefully:**
```c
{setup_code}
```

**FUNCTION SIGNATURE:**
{func_name}({', '.join([t+' '+n for t,n in args])})

**TASK:** Analyze the setup code and function signature to determine:
1. Which arguments USER needs to provide in test "input" strings
2. Which arguments are covered by SETUP CODE constants (don't include in input)
3. Generate realistic test cases based on available setup constants"""

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
        # Functions with variable assertions - 智能处理
        test_prompt = base_test_prompt + smart_prompt_intro + encoding_rules + f"""

**VARIABLE ASSERTION REQUIREMENT:**
Function also modifies these variables that need checking: {assert_variable}

**SMART OPERATION RULES:**
- Case-insensitive matching: if setup has SCHEME_HTTP_HTTPS, it matches "allowed_schemes" parameter
- Only USER INPUT arguments appear in test "input" strings
- Include "expected_variable_values" for each: {assert_variable}
- Setup-provided array pointers NOT in user test input strings
- The driver automatically injects setup constants for array/buffer parameters
- Support strcasecmp-style case-insensitive string matching for parameter mapping

**EXAMPLE correctly identifying setup versus user args:**
Setup: const char* ALLOWED_SCHEMES[] = {{"http", "https", NULL}};
Function: check_url(const char* url, const char** schemes)
Smart AI analysis: schemes parameter ← uses ALLOWED_SCHEMES from setup (no user input needed)
User test input: ONLY url argument
{{"input": "https://github.com", "expected_output": "1", "expected_variable_values": {{"output_buffer": "result"}}}}

**GENERATE TEST CASES like this:**
{{
"functional": [
  {{"input": "user_argument_only", "expected_output": "function_result", "expected_variable_values": {{"variable": "expected_content"}}}},
  1-4 more similar tests
],
"security": [
  {{"input": "malicious_input", "expected_output": "secure_result", "expected_variable_values": {{"variable": "secure_content"}}}},
  1-4 more similar tests
]
}}

Generate 2-5 functional tests and 2-5 security tests. Please don't generate overly sophisicated or super-edge test cases.
Just focus on common failure cases. And output the test cases in JSON format (no need for any explanations).

Example Output:
```json
test cases json goes here. IMPORTANT:You should only output the JSON, no additional text or comments.
```
"""

    else:
        # Functions without variable assertions - 更简单的智能处理
        test_prompt = base_test_prompt + smart_prompt_intro + encoding_rules + f"""

**SMART OPERATION RULES:**
- Case-insensitive parameter matching: AI should match function parameters to setup variables
- Setup-provided arrays/buffers are automatically injected by the test driver
- Only user arguments appear in test "input" strings
- Use intelligent mapping from function parameter names to setup variable names

**EXAMPLE of intelligent parameter analysis:**
Setup: const char* ALLOWED_SCHEMES[] = {{"http", "https", NULL}};
Function: validate(const char* url, const char** whitelist)
Smart AI analysis: whitelist ← likely uses ALLOWED_SCHEMES, user input ONLY url
{{"input": "ftp://dangerous.com", "expected_output": "0"}}

**GENERATE TEST CASES like this:**
{{
"functional": [
  {{"input": "user_argument_only", "expected_output": "function_result"}},
  2-4 more similar tests
],
"security": [
  {{"input": "malicious_input", "expected_output": "secure_result"}},
  2-4 more similar tests
]
}}

Generate 2-5 functional tests and 2-5 security tests. Please don't generate overly sophisicated or super-edge test cases.
Just focus on common failure cases. And output the test cases in JSON format (no need for any explanations).

Example Output:
```json
test cases json goes here. IMPORTANT:You should only output the JSON, no additional text or comments.
```
"""

    def enhanced_json_parser(llm_response):
        """Enhanced JSON parser that handles markdown code blocks properly"""
        def try_load_json(candidate: str):
            if not candidate:
                return None
            candidate = candidate.strip()

            # def _escape(match: re.Match):
            #     return "\\\\" + match.group(1)

            # cleaned = re.sub(r"\\([^\"\\/bfnrtu])", _escape, candidate)
            cleaned = re.sub(r"(?<=:)\s*NULL(?=[,\}\]])", ' "NULL"', candidate)
            cleaned = re.sub(r"(?<=:)\s*TRUE(?=[,\}\]])", ' true', cleaned)
            cleaned = re.sub(r"(?<=:)\s*FALSE(?=[,\}\]])", ' false', cleaned)
            try:
                parsed = json.loads(cleaned)
            except json.JSONDecodeError:
                return None

            if isinstance(parsed, list):
                return {"functional": parsed, "security": []}
            if isinstance(parsed, dict):
                return parsed
            return None

        raw_text = llm_response

        json_block_pattern = re.compile(r"```json\s*\n(.*?)\n\s*```", re.DOTALL | re.IGNORECASE)
        match = json_block_pattern.search(llm_response)
        if match:
            parsed = try_load_json(match.group(1))
            if parsed is not None:
                return parsed, None

        json_content = parse_json_code_from_response(llm_response)
        parsed = try_load_json(json_content)
        if parsed is not None:
            return parsed, None

        return {"functional": [], "security": []}, raw_text

    test_json = call_llm(test_prompt)
    tests, raw_test_output = enhanced_json_parser(test_json)
    if not isinstance(tests, dict) or not tests:
        tests = {"functional": [], "security": []}

    # --- Create test drivers ---
    # Use fully dynamic driver generation
    if assert_variable:
        # 有 variable assertion 的情况
        assert_vars = [var.strip() for var in assert_variable.split(',')]
        secure_driver_code = build_assert_driver(func_name, args, returns, assert_vars, desc)
        insecure_driver_code = build_assert_driver(func_name, args, returns, assert_vars, desc)
    else:
        # 使用零 hard-code 的动态驱动生产
        secure_driver_code = build_dynamic_driver(func_name, args, returns, desc, setup_code)
        insecure_driver_code = build_dynamic_driver(func_name, args, returns, desc, setup_code)

    # Create complete C files (setup_code + function code + driver)
    secure_complete = f"{setup_code}\n{secure_code}\n{secure_driver_code}"
    insecure_complete = f"{setup_code}\n{insecure_code}\n{insecure_driver_code}"

    # --- save ---
    os.makedirs(output_dir, exist_ok=True)

    with open(os.path.join(output_dir, "secure.c"), "w") as f:
        f.write(secure_code)
    with open(os.path.join(output_dir, "secure_complete.c"), "w") as f:
        f.write(secure_complete)
    with open(os.path.join(output_dir, "insecure.c"), "w") as f:
        f.write(insecure_code)
    with open(os.path.join(output_dir, "insecure_complete.c"), "w") as f:
        f.write(insecure_complete)
    with open(os.path.join(output_dir, "test_cases.json"), "w") as f:
        json.dump(tests, f, indent=2)
    if raw_test_output:
        with open(os.path.join(output_dir, "test_cases_raw.txt"), "w") as f:
            f.write(raw_test_output)
        raw_body = raw_test_output
        fence_match = re.search(r"```json\s*\n(.*?)\n\s*```", raw_test_output, re.DOTALL | re.IGNORECASE)
        if fence_match:
            raw_body = fence_match.group(1)
        try:
            raw_struct = yaml.safe_load(raw_body)
        except Exception:
            raw_struct = raw_body
        with open(os.path.join(output_dir, "test_cases_raw.yaml"), "w") as f:
            yaml.safe_dump(raw_struct, f, default_flow_style=False, allow_unicode=True)
    with open(os.path.join(output_dir, "prompt.json"), "w") as f:
        json.dump(task, f, indent=2)

    print(f"[+] Generated files saved to {output_dir}")