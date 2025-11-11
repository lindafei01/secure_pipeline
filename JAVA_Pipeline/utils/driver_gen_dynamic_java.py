import re
from typing import List, Sequence, Tuple

Argument = Tuple[str, str]


def extract_setup_constants(setup_code: str) -> List[str]:
    pattern = re.compile(r"\bstatic\s+final\s+[A-Za-z0-9_<>,\[\]]+\s+([A-Za-z_][A-Za-z0-9_]*)\s*=")
    return list(dict.fromkeys(match.group(1) for match in pattern.finditer(setup_code or "")))


def _normalize_type(arg_type: str) -> str:
    lowered = (arg_type or "").lower()
    if any(keyword in lowered for keyword in ["string", "charseq", "char[]"]):
        return "string"
    if any(keyword in lowered for keyword in ["int", "integer", "short", "byte"]):
        return "int"
    if any(keyword in lowered for keyword in ["long"]):
        return "long"
    if any(keyword in lowered for keyword in ["double", "float", "decimal"]):
        return "double"
    if any(keyword in lowered for keyword in ["bool"]):
        return "boolean"
    if any(keyword in lowered for keyword in ["list", "set", "map", "[]", "collection"]):
        return "json"
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
    if any(keyword in lowered_type for keyword in ["[]", "list", "set", "map", "collection"]):
        return True
    if any(keyword in lowered_desc for keyword in ["provided", "setup", "predefined", "constant", "array"]):
        if any(const.lower() in lowered_name or lowered_name in const.lower() for const in constants):
            return True
    if any(const.lower() in lowered_name or lowered_name in const.lower() for const in constants):
        return True
    return False


def indent_lines(lines: Sequence[str], level: int = 1) -> List[str]:
    prefix = "    " * level
    return [prefix + line if line else "" for line in lines]


def indent_block(block: str, level: int = 1) -> str:
    lines = block.splitlines()
    return "\n".join(indent_lines(lines, level))


def generate_argument_parsing(function_name: str, args_info: Sequence[Argument], description: str, setup_code: str):
    constants = extract_setup_constants(setup_code)
    parsing_lines: List[str] = []
    user_arg_count = 0
    user_arg_names: List[str] = []
    call_args: List[str] = []

    for index, (arg_type, arg_name) in enumerate(args_info):
        if _should_use_setup(arg_type, arg_name, constants, description):
            const_name = _match_setup_constant(arg_name, constants)
            if const_name:
                call_args.append(const_name)
                continue
            parsing_lines.append(f"{arg_type} {arg_name} = null; // TODO: supply setup constant")
            call_args.append(arg_name)
            continue

        conversion = _normalize_type(arg_type)
        user_arg_names.append(arg_name)
        source = f"args[{user_arg_count}]"
        if conversion == "int":
            parsing_lines.append(f"{arg_type} {arg_name} = Integer.parseInt({source});")
        elif conversion == "long":
            parsing_lines.append(f"{arg_type} {arg_name} = Long.parseLong({source});")
        elif conversion == "double":
            parsing_lines.append(f"{arg_type} {arg_name} = Double.parseDouble({source});")
        elif conversion == "boolean":
            parsing_lines.append(f"{arg_type} {arg_name} = Boolean.parseBoolean({source});")
        elif conversion == "json":
            parsing_lines.append(f"{arg_type} {arg_name} = {source}; // TODO: parse structured input if needed")
        else:
            parsing_lines.append(f"{arg_type} {arg_name} = {source};")
        call_args.append(arg_name)
        user_arg_count += 1

    return parsing_lines, user_arg_count, user_arg_names, call_args


def generate_function_call(return_type: str, function_name: str, call_args: Sequence[str]) -> List[str]:
    joined_args = ", ".join(call_args)
    call_line = f"{return_type} result = {function_name}({joined_args});" if return_type.lower() != "void" else f"{function_name}({joined_args});"
    lines = [call_line]

    if return_type.lower() == "void":
        lines.append("System.out.println(\"void\");")
    else:
        lines.append("System.out.println(formatOutput(result));")
    return lines


def build_dynamic_driver(function_name: str, args_info: Sequence[Argument], return_type: str, description: str, setup_code: str) -> str:
    parsing_lines, user_arg_count, user_arg_names, call_args = generate_argument_parsing(function_name, args_info, description, setup_code)

    usage_stub = " ".join(user_arg_names)
    guard_lines: List[str] = []
    if user_arg_count > 0:
        guard_lines = [
            f"if (args.length < {user_arg_count}) {{",
            "System.out.println(\"Usage: <program> " + usage_stub + "\");",
            "return;",
            "}",
        ]

    function_call = generate_function_call(return_type, function_name, call_args)

    body_lines: List[str] = []
    body_lines.extend(guard_lines)
    body_lines.extend(parsing_lines)
    body_lines.extend(function_call)

    helper_method = """
private static String formatOutput(Object value) {
    if (value == null) {
        return "null";
    }
    if (value instanceof Boolean) {
        return ((Boolean) value) ? "true" : "false";
    }
    if (value instanceof Number) {
        return value.toString();
    }
    if (value instanceof CharSequence) {
        return value.toString();
    }
    if (value instanceof java.util.Map<?, ?>) {
        return formatMap((java.util.Map<?, ?>) value);
    }
    if (value instanceof java.util.Collection<?>) {
        return formatCollection((java.util.Collection<?>) value);
    }
    if (value.getClass().isArray()) {
        return formatArray(value);
    }
    return value.toString();
}

private static String formatCollection(java.util.Collection<?> collection) {
    StringBuilder sb = new StringBuilder();
    sb.append("[");
    java.util.Iterator<?> iterator = collection.iterator();
    while (iterator.hasNext()) {
        Object element = iterator.next();
        sb.append(formatElement(element));
        if (iterator.hasNext()) {
            sb.append(", ");
        }
    }
    sb.append("]");
    return sb.toString();
}

private static String formatMap(java.util.Map<?, ?> map) {
    StringBuilder sb = new StringBuilder();
    sb.append("{");
    java.util.Iterator<? extends java.util.Map.Entry<?, ?>> iterator = map.entrySet().iterator();
    while (iterator.hasNext()) {
        java.util.Map.Entry<?, ?> entry = iterator.next();
        sb.append(formatElement(entry.getKey()));
        sb.append(": ");
        sb.append(formatElement(entry.getValue()));
        if (iterator.hasNext()) {
            sb.append(", ");
        }
    }
    sb.append("}");
    return sb.toString();
}

private static String formatArray(Object array) {
    int length = java.lang.reflect.Array.getLength(array);
    StringBuilder sb = new StringBuilder();
    sb.append("[");
    for (int i = 0; i < length; i++) {
        Object element = java.lang.reflect.Array.get(array, i);
        sb.append(formatElement(element));
        if (i < length - 1) {
            sb.append(", ");
        }
    }
    sb.append("]");
    return sb.toString();
}

private static String formatElement(Object element) {
    if (element == null) {
        return "null";
    }
    if (element instanceof String) {
        return "'" + escapeString((String) element) + "'";
    }
    if (element instanceof Character) {
        return "'" + escapeString(String.valueOf(element)) + "'";
    }
    if (element instanceof Boolean) {
        return ((Boolean) element) ? "true" : "false";
    }
    if (element instanceof Number) {
        return element.toString();
    }
    if (element instanceof java.util.Map<?, ?>) {
        return formatMap((java.util.Map<?, ?>) element);
    }
    if (element instanceof java.util.Collection<?>) {
        return formatCollection((java.util.Collection<?>) element);
    }
    if (element.getClass().isArray()) {
        return formatArray(element);
    }
    return element.toString();
}

private static String escapeString(String value) {
    return value.replace("\\\\", "\\\\\\\\").replace("'", "\\\\'");
}
""".strip("\n")

    indented_body = "\n".join(indent_lines(body_lines, 2))

    main_method = "\n".join([
        "    public static void main(String[] args) throws Exception {",
        indented_body,
        "    }",
        "",
        indent_block(helper_method, 1),
    ])

    return main_method


build_simple_driver = build_dynamic_driver
