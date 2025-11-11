def parse_arg_c_type(c_type):
    """Parse C type to determine how to parse command line arguments"""
    if 'char*' in c_type or c_type == 'const char*':
        return 'string'
    elif 'int' in c_type:
        return 'int'
    elif 'float' in c_type:
        return 'float'
    elif 'double' in c_type:
        return 'double'
    elif 'unsigned' in c_type:
        return 'unsigned'
    elif 'size_t' in c_type:
        return 'size_t'
    else:
        return 'string'

def generate_argument_parsing(function_name, args_info):
    """Generate argument parsing code based on function signature"""
    if not args_info:
        return "    // No arguments for this function\n"

    parsing_code = "    // Parse arguments from command line\n"
    for i, (arg_type, arg_name) in enumerate(args_info):
        arg_parse_type = parse_arg_c_type(arg_type)

        if arg_parse_type == 'string':
            parsing_code += f"    {arg_type} {arg_name} = argv[{i+1}];\n"
        elif arg_parse_type == 'int':
            parsing_code += f"\n    char* endptr{i};\n"
            parsing_code += f"    long {arg_name} = strtol(argv[{i+1}], \u0026endptr{i}, 10);\n"
            parsing_code += f"    if (endptr{i}[0] != '\\0' || {arg_name} \u003c INT_MIN || {arg_name} \u003e INT_MAX) {{\n"
            parsing_code += f"        printf(\"Error: Invalid integer input for {arg_name}\\n\");\n"
            parsing_code += f"        return RESPONSE_ERROR_TEST_FAILED;\n"
            parsing_code += f"    }}\n"
        elif arg_parse_type == 'double':
            parsing_code += f"    char* endptr{i};\n"
            parsing_code += f"    double {arg_name} = strtod(argv[{i+1}], \u0026endptr{i});\n"
            parsing_code += f"    if (endptr{i}[0] != '\\0') {{\n"
            parsing_code += f"        printf(\"Error: Invalid double input for {arg_name}\\n\");\n"
            parsing_code += f"        return RESPONSE_ERROR_TEST_FAILED;\n"
            parsing_code += f"    }}\n"
        elif arg_parse_type == 'unsigned':
            parsing_code += f"\n    char* endptr{i};\n"
            parsing_code += f"    unsigned long {arg_name} = strtoul(argv[{i+1}], \u0026endptr{i}, 10);\n"
            parsing_code += f"    if (endptr{i}[0] != '\\0') {{\n"
            parsing_code += f"        printf(\"Error: Invalid unsigned integer input for {arg_name}\\n\");\n"
            parsing_code += f"        return RESPONSE_ERROR_TEST_FAILED;\n"
            parsing_code += f"    }}\n"
        elif arg_parse_type == 'size_t':
            parsing_code += f"\n    char* endptr{i};\n"
            parsing_code += f"    size_t {arg_name} = (size_t)strtoul(argv[{i+1}], \u0026endptr{i}, 10);\n"
            parsing_code += f"    if (endptr{i}[0] != '\\0') {{\n"
            parsing_code += f"        printf(\"Error: Invalid size_t input for {arg_name}\\n\");\n"
            parsing_code += f"        return RESPONSE_ERROR_TEST_FAILED;\n"
            parsing_code += f"    }}\n"

    return parsing_code

def generate_result_processing(return_type, function_name, args_info):
    """Generate the function call and result processing code"""
    # Build argument list for the function call
    arg_names = [arg_name for _, arg_name in args_info]
    cast_args = []

    for arg_type, arg_name in args_info:
        if 'long' in arg_type or 'int' in arg_type:
            cast_args.append(f"(int){arg_name}")
        elif 'unsigned' in arg_type and 'long' not in arg_type:
            cast_args.append(f"(unsigned int){arg_name}")
        elif 'unsigned long' in arg_type:
            cast_args.append(f"(unsigned long){arg_name}")
        elif 'double' in arg_type:
            cast_args.append(f"(double){arg_name}")
        elif 'size_t' in arg_type:
            cast_args.append(f"(size_t){arg_name}")
        else:
            cast_args.append(arg_name)

    arg_str = ', '.join(cast_args) if cast_args else ''

    if 'char*' in return_type:
        return f"""    // Execute target function
    {return_type} result = {function_name}({arg_str});
    handle_null_output(result);
    """
    elif 'int' in return_type:
        return f"""    // Execute target function
    {return_type} result = {function_name}({arg_str});
    handle_numeric_output(result);
    """
    elif 'unsigned long' in return_type or 'size_t' in return_type:
        return f"""    // Execute target function
    {return_type} result = {function_name}({arg_str});
    handle_unsigned_output(result);
    """
    elif 'double' in return_type:
        return f"""    // Execute target function
    {return_type} result = {function_name}({arg_str});
    handle_numeric_output((long)result);
    """
    else:
        # Default to numeric handling
        return f"""    // Execute target function
    {return_type} result = {function_name}({arg_str});
    handle_numeric_output(result);
    """

def generate_cleanup(cleanup_info):
    """Generate cleanup code for memory management"""
    if cleanup_info.get('needs_cleanup', False):
        return "\n    free(result);\n"
    return ""

def build_main_driver(function_signature, function_name, args_info, return_type, needs_cleanup=False):
    """Generate complete test driver C code"""
    # Count arguments for main
    argc_count = len(args_info) + 1

    # Generate usage pattern
    usage_params = ' '.join([f'arg{i+1}' for i in range(len(args_info))])

    # Generate all sections
    arg_parsing_code = generate_argument_parsing(function_name, args_info)
    result_processing_code = generate_result_processing(return_type, function_name, args_info)
    cleanup_code = generate_cleanup({'needs_cleanup': needs_cleanup and 'char*' in return_type})

    # Read template
    with open('templates/test_driver.c', 'r') as f:
        template = f.read()

    # Fill in all template placeholders
    driver_code = template.replace('{FUNCTION_SIGNATURE}', function_signature)
    driver_code = driver_code.replace('{ARGC_COUNT}', str(argc_count))
    driver_code = driver_code.replace('{USAGE_PARAMS}', usage_params)
    driver_code = driver_code.replace('{ARGUMENT_PARSING_CODE}', arg_parsing_code)
    driver_code = driver_code.replace('{RESULT_PROCESSING_CODE}', result_processing_code)
    driver_code = driver_code.replace('{CLEANUP_CODE}', cleanup_code)

    return driver_code

def generate_driver_for_task(func_name, args_info, return_type):
    """Generate test driver code for a specific task"""
    # Build function signature from args
    if args_info:
        args_str = ', '.join([f"{arg_type} {arg_name}" for arg_type, arg_name in args_info])
        function_signature = f"{return_type} {func_name}({args_str})"
    else:
        function_signature = f"{return_type} {func_name}(void)"

    return build_main_driver(function_signature, func_name, args_info, return_type, 'char*' in return_type)

if __name__ == "__main__":
    # Test with get_email_domain
    func_name = "get_email_domain"
    args = [("const char*", "mail_address")]
    return_type = "char*"

    driver = generate_driver_for_task(func_name, args, return_type)
    print("Generated test driver for get_email_domain:")
    print(driver)