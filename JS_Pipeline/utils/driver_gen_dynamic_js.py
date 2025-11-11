#!/usr/bin/env python3
"""Utilities to build zero-hardcode Node.js test drivers."""

import re
from typing import List, Sequence, Tuple

Argument = Tuple[str, str]


def extract_setup_constants(setup_code: str) -> List[str]:
    pattern = re.compile(r"\bconst\s+([A-Za-z_][A-Za-z0-9_]*)\s*=\s*([^;]+);", re.MULTILINE)
    constants: List[str] = []
    for match in pattern.finditer(setup_code or ""):
        name = match.group(1)
        initializer = match.group(2).strip()
        initializer = initializer.split("//", 1)[0].strip()
        if re.search(r"\brequire\s*\(", initializer):
            continue
        if initializer.startswith("function"):
            continue
        if "=>" in initializer and initializer.startswith("("):
            continue
        constants.append(name)
    return list(dict.fromkeys(constants))


def _normalize_type(arg_type: str) -> str:
    lowered = (arg_type or "").lower()
    if any(keyword in lowered for keyword in ["json", "object", "dict", "map"]):
        return "json"
    if any(keyword in lowered for keyword in ["array", "list", "[]", "set"]):
        return "json"
    if any(keyword in lowered for keyword in ["bool", "boolean"]):
        return "bool"
    if any(keyword in lowered for keyword in ["float", "double", "decimal"]):
        return "float"
    if any(keyword in lowered for keyword in ["int", "size_t", "long", "number", "count"]):
        return "int"
    if any(keyword in lowered for keyword in ["char*", "string", "cstring", "str"]):
        return "string"
    return "string"


def _match_setup_constant(arg_name: str, constants: Sequence[str]) -> str:
    arg_lower = arg_name.lower()
    for const in constants:
        const_lower = const.lower()
        if arg_lower in const_lower or const_lower in arg_lower:
            return const
    return constants[0] if constants else ""


def _should_use_setup(arg_type: str, arg_name: str, constants: Sequence[str], description: str) -> bool:
    if not constants:
        return False
    lowered_type = (arg_type or "").lower()
    lowered_name = arg_name.lower()
    lowered_desc = (description or "").lower()
    if any(keyword in lowered_type for keyword in ["array", "list", "map", "set", "dict", "pointer"]):
        return True
    if any(keyword in lowered_desc for keyword in ["array", "list", "provided", "predefined", "setup"]):
        if any(const.lower() in lowered_name or lowered_name in const.lower() for const in constants):
            return True
    if any(const.lower() in lowered_name or lowered_name in const.lower() for const in constants):
        return True
    return False


def generate_argument_parsing(function_name: str, args_info: Sequence[Argument], description: str, setup_code: str):
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

        if parser_type == "int":
            parsing_lines.append(f"  const {arg_name} = Number({raw_var});")
        elif parser_type == "float":
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


def generate_function_call_and_output(return_type: str, function_name: str, arg_names: Sequence[str]) -> str:
    joined_args = ", ".join(arg_names)
    code = ["  const value = await Promise.resolve(" + f"{function_name}({joined_args})" + ");"]
    code.append("  console.log(formatOutput(value));")
    return "\n".join(code)


def build_dynamic_driver(function_name: str, args_info: Sequence[Argument], return_type: str, description: str, setup_code: str) -> str:
    parsing_lines, user_arg_names, arg_names = generate_argument_parsing(function_name, args_info, description, setup_code)
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

    function_call = generate_function_call_and_output(return_type, function_name, arg_names)

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

function formatOutput(value) {{
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


# Backwards compatibility alias
build_simple_driver = build_dynamic_driver
