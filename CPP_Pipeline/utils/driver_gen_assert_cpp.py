from typing import List, Sequence, Tuple

from .driver_gen_dynamic_cpp import (
    build_dynamic_driver,  # noqa: F401 - re-export for compatibility
    generate_argument_parsing,
)

Argument = Tuple[str, str]


def build_assert_driver(function_name: str, args_info: Sequence[Argument], return_type: str, assert_variables: Sequence[str], description: str, setup_code: str) -> str:
    parsing_lines, user_arg_count, user_arg_names, call_args = generate_argument_parsing(function_name, args_info, description, setup_code)

    usage_stub = " ".join(user_arg_names)
    guard_lines: List[str] = []
    if user_arg_count > 0:
        guard_lines = [
            f"    if (args.size() < {user_arg_count}) {{",
            "        std::cout << \"Usage: <program> " + usage_stub + "\\n\";",
            "        return 64;",
            "    }",
        ]

    call_expression = ", ".join(call_args)
    call_line = (
        f"    auto result = {function_name}({call_expression});"
        if return_type.lower() != "void"
        else f"    {function_name}({call_expression});"
    )
    result_output: List[str] = []
    if return_type.lower() == "void":
        result_output.append("    std::cout << \"RESULT:void\\n\";")
    else:
        result_output.append("    std::cout << \"RESULT:\" << format_value(result) << std::endl;")

    for var_name in assert_variables:
        var_upper = var_name.upper()
        result_output.append(f"    std::cout << \"{var_upper}:\" << format_value({var_name}) << std::endl;")

    helper_method = """
template <typename T>
std::string format_value(const T& value) {
    using Decayed = std::decay_t<T>;
    if constexpr (std::is_same_v<Decayed, bool>) {
        return value ? "true" : "false";
    }
    if constexpr (std::is_arithmetic_v<Decayed>) {
        return std::to_string(value);
    }
    if constexpr (std::is_convertible_v<Decayed, std::string>) {
        return static_cast<std::string>(value);
    }
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

inline std::string format_value(const std::string& value) {
    return value;
}

inline std::string format_value(const char* value) {
    return value ? std::string(value) : "null";
}
""".strip("\n")

    main_body: List[str] = [
        "int main(int argc, char* argv[]) {",
        "    std::vector<std::string> args(argv + 1, argv + argc);",
        *guard_lines,
        *parsing_lines,
        call_line,
        *result_output,
        "    return 0;",
        "}",
        "",
        helper_method,
    ]

    return "\n".join(main_body)
