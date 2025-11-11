import re
from typing import List, Sequence, Tuple

Argument = Tuple[str, str]


def extract_setup_constants(setup_code: str) -> List[str]:
    pattern = re.compile(r"\b(?:const|static\s+const)\s+[A-Za-z0-9_:\s<>,\[\]*&]+\s+([A-Za-z_][A-Za-z0-9_]*)\s*=")
    return list(dict.fromkeys(match.group(1) for match in pattern.finditer(setup_code or "")))


def _normalize_type(arg_type: str) -> str:
    lowered = (arg_type or "").lower()
    if any(keyword in lowered for keyword in ["char*", "string", "std::string"]):
        return "string"
    if any(keyword in lowered for keyword in ["int", "short", "size_t", "long", "unsigned"]):
        return "int"
    if any(keyword in lowered for keyword in ["double", "float", "decimal"]):
        return "double"
    if any(keyword in lowered for keyword in ["bool"]):
        return "bool"
    if any(keyword in lowered for keyword in ["vector", "array", "list", "set", "map", "[]"]):
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
    if any(keyword in lowered_type for keyword in ["*", "[]", "vector", "array", "set", "map"]):
        return True
    if any(keyword in lowered_desc for keyword in ["provided", "setup", "predefined", "constant", "array"]):
        if any(const.lower() in lowered_name or lowered_name in const.lower() for const in constants):
            return True
    if any(const.lower() in lowered_name or lowered_name in const.lower() for const in constants):
        return True
    return False


def _clean_numeric_type(arg_type: str) -> str:
    cleaned = re.sub(r"\b(const|volatile|static)\b", "", arg_type)
    cleaned = cleaned.replace("&", "").strip()
    return cleaned or "int"


def _select_integer_parser(arg_type: str) -> str:
    lowered = arg_type.lower()
    if "unsigned long long" in lowered:
        return "std::stoull"
    if "unsigned long" in lowered:
        return "std::stoul"
    if "unsigned" in lowered or "size_t" in lowered:
        return "std::stoull"
    if "long long" in lowered:
        return "std::stoll"
    if "long" in lowered:
        return "std::stol"
    return "std::stoi"


def generate_argument_parsing(function_name: str, args_info: Sequence[Argument], description: str, setup_code: str):
    constants = extract_setup_constants(setup_code)
    parsing_lines: List[str] = []
    user_arg_index = 0
    user_arg_names: List[str] = []
    call_args: List[str] = []

    for arg_type, arg_name in args_info:
        if _should_use_setup(arg_type, arg_name, constants, description):
            const_name = _match_setup_constant(arg_name, constants)
            if const_name:
                call_args.append(f"::{const_name}")
                continue

        converter = _normalize_type(arg_type)
        source = f"args[{user_arg_index}]"

        if "char*" in arg_type:
            holder = f"{arg_name}_holder"
            parsing_lines.append(f"    auto& {holder} = {source};")
            if "const" in arg_type:
                parsing_lines.append(f"    {arg_type} {arg_name} = {holder}.c_str();")
            else:
                parsing_lines.append(f"    {arg_type} {arg_name} = {holder}.data();")
        else:
            if converter == "int":
                parser = _select_integer_parser(arg_type)
                clean_type = _clean_numeric_type(arg_type)
                parsing_lines.append(f"    auto {arg_name}_value = {parser}({source});")
                parsing_lines.append(f"    {arg_type} {arg_name} = static_cast<{clean_type}>({arg_name}_value);")
            elif converter == "double":
                func = "std::stod" if "double" in arg_type.lower() else "std::stof"
                parsing_lines.append(f"    {arg_type} {arg_name} = {func}({source});")
            elif converter == "bool":
                parsing_lines.append(f"    {arg_type} {arg_name} = ({source} == \"true\" || {source} == \"1\");")
            elif converter == "json":
                parsing_lines.append(f"    {arg_type} {arg_name} = {source}; // TODO: parse structured input")
            else:
                if "&" in arg_type:
                    parsing_lines.append(f"    std::string {arg_name}_value = {source};")
                    parsing_lines.append(f"    {arg_type} {arg_name} = {arg_name}_value;")
                else:
                    parsing_lines.append(f"    {arg_type} {arg_name} = {source};")

        call_args.append(arg_name)
        user_arg_names.append(arg_name)
        user_arg_index += 1

    return parsing_lines, user_arg_index, user_arg_names, call_args


def generate_function_call(return_type: str, function_name: str, arg_exprs: Sequence[str]) -> List[str]:
    joined_args = ", ".join(arg_exprs)
    if return_type.lower() == "void":
        return [f"    {function_name}({joined_args});", "    std::cout << \"void\\n\";"]
    return [f"    auto result = {function_name}({joined_args});", "    std::cout << format_output(result) << std::endl;"]


def build_dynamic_driver(function_name: str, args_info: Sequence[Argument], return_type: str, description: str, setup_code: str) -> str:
    parsing_lines, user_arg_count, user_arg_names, call_args = generate_argument_parsing(function_name, args_info, description, setup_code)

    usage_stub = " ".join(user_arg_names)
    guard_lines: List[str] = []
    if user_arg_count > 0:
        guard_lines = [
            f"    if (args.size() < {user_arg_count}) {{",
            f"        std::cout << \"Usage: <program> {usage_stub}\\n\";",
            "        return 64;",
            "    }",
        ]

    function_call = generate_function_call(return_type, function_name, call_args)

    helper = """
std::string format_output(const std::string& value) {
    return value;
}

template <typename T>
std::string format_output(const T& value) {
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

std::string format_output(const char* value) {
    if (value == nullptr) {
        return "null";
    }
    return std::string(value);
}

std::string format_output(std::nullptr_t) {
    return "null";
}
""".strip("\n")

    main_lines = [
        "int main(int argc, char* argv[]) {",
        "    std::vector<std::string> args(argv + 1, argv + argc);",
        *guard_lines,
        *parsing_lines,
        *function_call,
        "    return 0;",
        "}",
    ]

    return "\n".join([helper, "", *main_lines])


build_simple_driver = build_dynamic_driver
