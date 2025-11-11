from typing import List, Sequence, Tuple

from .driver_gen_dynamic_java import (
    build_dynamic_driver,  # noqa: F401 - re-export for compatibility
    generate_argument_parsing,
    indent_block,
    indent_lines,
)

Argument = Tuple[str, str]


def build_assert_driver(function_name: str, args_info: Sequence[Argument], return_type: str, assert_variables: Sequence[str], description: str, setup_code: str) -> str:
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

    call_expression = f"{function_name}({', '.join(call_args)})"
    if return_type.lower() == "void":
        call_line = f"{call_expression};"
    else:
        call_line = f"{return_type} result = {call_expression};"

    result_output: List[str] = []
    if return_type.lower() == "void":
        result_output.append('System.out.println("RESULT:void");')
    else:
        result_output.append('System.out.println("RESULT:" + formatValue(result));')

    for var_name in assert_variables:
        var_upper = var_name.upper()
        result_output.append(f'System.out.println("{var_upper}:" + formatValue({var_name}));')

    body_lines: List[str] = []
    body_lines.extend(guard_lines)
    body_lines.extend(parsing_lines)
    body_lines.append(call_line)
    body_lines.extend(result_output)

    helper_method = """
private static String formatValue(Object value) {
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

    main_lines: List[str] = [
        "    public static void main(String[] args) throws Exception {",
        indented_body,
        "    }",
        "",
        indent_block(helper_method, 1),
    ]

    return "\n".join(main_lines)
