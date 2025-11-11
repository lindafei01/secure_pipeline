#!/usr/bin/env python3
"""Generate Node.js drivers that capture return values and variable assertions."""

from typing import List, Sequence, Tuple

from .driver_gen_dynamic_js import (
    _match_setup_constant,
    _normalize_type,
    _should_use_setup,
    extract_setup_constants,
)

Argument = Tuple[str, str]


def generate_argument_parsing_with_assert(args_info: Sequence[Argument], description: str, setup_code: str):
    constants = extract_setup_constants(setup_code)
    parsing_lines: List[str] = ["  const argv = process.argv.slice(2);"]
    user_arg_index = 0
    user_arg_names: List[str] = []
    arg_names: List[str] = []

    for arg_type, arg_name in args_info:
        arg_names.append(arg_name)
        if _should_use_setup(arg_type, arg_name, constants, description):
            const_name = _match_setup_constant(arg_name, constants)
            if const_name:
                if const_name == arg_name:
                    parsing_lines.append(f"  // Argument '{arg_name}' uses setup constant {const_name}")
                else:
                    parsing_lines.append(f"  const {arg_name} = {const_name}; // Provided via setup code")
            else:
                parsing_lines.append(f"  const {arg_name} = undefined; // Fallback when setup constant missing")
            continue

        parser_type = _normalize_type(arg_type)
        source_expr = f"argv[{user_arg_index}]"
        raw_var = f"raw_{arg_name}"
        parsing_lines.append(f"  const {raw_var} = {source_expr};")

        if parser_type == "int" or parser_type == "float":
            parsing_lines.append(f"  const {arg_name} = Number({raw_var});")
        elif parser_type == "bool":
            parsing_lines.append(f"  const {arg_name} = ({raw_var} || '').toLowerCase() === 'true';")
        elif parser_type == "json":
            parsing_lines.append(f"  const {arg_name} = {raw_var} ? JSON.parse({raw_var}) : undefined;")
        else:
            parsing_lines.append(f"  const {arg_name} = {raw_var};")

        user_arg_names.append(arg_name)
        user_arg_index += 1

    return parsing_lines, user_arg_names, arg_names


def generate_function_call_with_assert(function_name: str, arg_names: Sequence[str], assert_variables: Sequence[str]) -> str:
    joined_args = ", ".join(arg_names)
    lines = [f"  const result = await Promise.resolve({function_name}({joined_args}));"]
    lines.append("  console.log(`RESULT:${formatValue(result)}`);")
    for var_name in assert_variables:
        lines.append(f"  console.log(`{var_name.upper()}:${formatValue({var_name})}`);")
    return "\n".join(lines)


def build_assert_driver(function_name: str, args_info: Sequence[Argument], return_type: str, assert_variables: Sequence[str], description: str = "", setup_code: str = "") -> str:
    parsing_lines, user_arg_names, arg_names = generate_argument_parsing_with_assert(args_info, description, setup_code)
    user_arg_count = len(user_arg_names)
    usage_stub = " ".join(user_arg_names)

    guard_lines: List[str] = []
    if user_arg_count > 0:
        guard_lines = [
            f"  if (argv.length < {user_arg_count}) {{",
            "    console.log(`Usage: ${process.argv[1]} " + usage_stub + "`);",
            "    process.exit(1);",
            "  }",
        ]

    function_call = generate_function_call_with_assert(function_name, arg_names, assert_variables)

    body_lines: List[str] = []
    if parsing_lines:
        body_lines.append(parsing_lines[0])
        body_lines.extend(guard_lines)
        body_lines.extend(parsing_lines[1:])
    else:
        body_lines.extend(guard_lines)
    body_lines.append(function_call)
    body = "\n".join(body_lines)

    driver = f"""'use strict';

function escapeString(value) {{
  return value.replace(/\\\\/g, "\\\\\\\\").replace(/'/g, "\\\\'");
}}

function formatElement(value) {{
  if (value === null) {{
    return "null";
  }}
  if (value === undefined) {{
    return "undefined";
  }}
  if (typeof value === "string") {{
    return `'${{escapeString(value)}}'`;
  }}
  if (typeof value === "boolean") {{
    return value ? "true" : "false";
  }}
  if (typeof value === "number" && Number.isFinite(value)) {{
    return String(value);
  }}
  if (Array.isArray(value)) {{
    return formatArray(value);
  }}
  if (typeof value === "object") {{
    return formatObject(value);
  }}
  return String(value);
}}

function formatArray(array) {{
  return "[" + array.map((item) => formatElement(item)).join(", ") + "]";
}}

function formatObject(obj) {{
  const entries = Object.keys(obj).map((key) => [key, obj[key]]);
  return "{{" + entries.map(([key, val]) => formatElement(key) + ": " + formatElement(val)).join(", ") + "}}";
}}

function formatValue(value) {{
  if (value === null) {{
    return "null";
  }}
  if (value === undefined) {{
    return "undefined";
  }}
  if (typeof value === "boolean") {{
    return value ? "true" : "false";
  }}
  if (typeof value === "number" && Number.isFinite(value)) {{
    return String(value);
  }}
  if (typeof value === "string") {{
    return value;
  }}
  if (Array.isArray(value)) {{
    return formatArray(value);
  }}
  if (typeof value === "object") {{
    return formatObject(value);
  }}
  return String(value);
}}

(async function main() {{
{body}
}})().catch((error) => {{
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
}});
"""
    return driver.strip()
