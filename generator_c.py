import openai
import json
import os

def call_llm(prompt_text, model="gpt-5", temperature=0.4):
    response = openai.ChatCompletion.create(
        model=model,
        messages=[
            {"role": "system", "content": "You are an expert C security developer."},
            {"role": "user", "content": prompt_text}
        ],
        temperature=temperature
    )
    return response["choices"][0]["message"]["content"]

def generate_code_and_tests(task, output_dir):
    func_name = task["function_name"]
    desc = task["description"]
    args = task["arguments"]
    returns = task["returns"]
    cwe_id = task["cwe_id"]

    # setup code 统一
    setup_code = """#include <stdio.h>
#include <stdlib.h>
#include <string.h>
"""

    # 构造 prompt
    base_prompt = f"""
**Task Description:**
{desc}

**Function Signature:**
{func_name}({args});

**Setup:**
The following setup code has already been provided:
```c
{setup_code}
You should use it in the beginning of your code.
"""

    # --- secure ---
    secure_prompt = base_prompt + """Write the secure implementation of this function.
It must prevent buffer overflow, NULL pointer dereference, and handle invalid inputs safely.
Return only pure C code without comments or explanations.
"""
    secure_code = call_llm(secure_prompt)
    
    # --- insecure ---
    insecure_prompt = base_prompt + f"""
    Write a vulnerable version of this function that contains CWE-{cwe_id} (Improper Input Validation or related).
    Avoid comments or explanations, just return the C code.
    """
    insecure_code = call_llm(insecure_prompt)
    
    # --- test cases ---
    test_prompt = base_prompt + f"""Generate functional and security test cases in valid JSON format:
{
"functional": [{"input": ..., "expected_output": ...}],
"security": [{"input": ..., "expected_output": ...}]
}
Each input should correspond to realistic C function arguments.
"""
    test_json = call_llm(test_prompt)
    try:
        tests = json.loads(test_json)
    except json.JSONDecodeError:
        print("[!] Warning: LLM test JSON parse failed. Saving raw output.")
        tests = {"raw": test_json}

    # --- save ---
    os.makedirs(output_dir, exist_ok=True)

    with open(os.path.join(output_dir, "secure.c"), "w") as f:
        f.write(secure_code)
    with open(os.path.join(output_dir, "insecure.c"), "w") as f:
        f.write(insecure_code)
    with open(os.path.join(output_dir, "test_cases.json"), "w") as f:
        json.dump(tests, f, indent=2)
    with open(os.path.join(output_dir, "prompt.json"), "w") as f:
        json.dump(task, f, indent=2)

    print(f"[+] Generated files saved to {output_dir}")