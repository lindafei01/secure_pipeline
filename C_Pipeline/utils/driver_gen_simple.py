def generate_argument_parsing_simple(function_name, args_info):
    """Generate simple argument parsing code"""
    if not args_info:
        return "    // No arguments\n"

    parsing_code = "    // Parse arguments from command line\n"
    for i, (arg_type, arg_name) in enumerate(args_info):
        arg_parse_type = 'string' if 'char*' in arg_type else 'int'

        if arg_parse_type == 'string':
            parsing_code += f"    {arg_type} {arg_name} = argv[{i+1}];\n"
        else:
            parsing_code += f"    // For {arg_type}: get value from argv[{i+1}]\n"
            # Simplified - assumes numeric for non-string types
            if 'int' in arg_type:
                parsing_code += f"    {arg_type} {arg_name} = atoi(argv[{i+1}]);\n"
            elif 'double' in arg_type:
                parsing_code += f"    {arg_type} {arg_name} = atof(argv[{i+1}]);\n"
            elif 'unsigned' in arg_type or 'size_t' in arg_type:
                parsing_code += f"    {arg_type} {arg_name} = strtoul(argv[{i+1}], NULL, 10);\n"
            else:
                # Default cast
                parsing_code += f"    {arg_type} {arg_name} = ({arg_type})atoi(argv[{i+1}]);\n"

    return parsing_code

def generate_function_call_and_result(return_type, function_name, args_info):
    """Generate function call and result output code"""

    # Build argument list for the function call - simple, no casting
    arg_str = ', '.join([arg_name for _, arg_name in args_info]) if args_info else ''

    code = f"    // Call the target function\n"
    code += f"    {return_type} result = {function_name}({arg_str});\n\n"

    # Handle return value based on type
    if 'char*' in return_type:
        code += """    // Handle string return type
    if (result == NULL) {
        printf("NULL\\n");
    } else {
        printf("%s\\n", result);
    }\n"""
    elif 'int' in return_type or 'long' in return_type:
        code += """    printf("%ld\\n", (long)result);\n"""
    elif 'unsigned' in return_type or 'size_t' in return_type:
        code += """    printf("%lu\\n", (unsigned long)result);\n"""
    elif 'double' in return_type or 'float' in return_type:
        code += """    printf("%f\\n", result);\n"""
    else:
        # Default numeric
        code += """    printf("%d\\n", (int)result);\n"""

    return code.strip()

def build_simple_driver(function_name, args_info, return_type):
    """Generate simple test driver C code"""
    # Count arguments for main
    argc_count = len(args_info) + 1

    # Generate usage pattern
    usage_params = ' '.join([f'arg{i+1}' for i in range(len(args_info))])

    # Generate function sections
    arg_parsing_code = generate_argument_parsing_simple(function_name, args_info)
    function_call_code = generate_function_call_and_result(return_type, function_name, args_info)

    # Use simple template
    template = """// Auto-generated test driver
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Basic argument validation
    if (argc < {ARGC_COUNT}) {
        printf("Usage: %s {USAGE_PARAMS}\\n", argv[0]);
        return 1;
    }

{ARGUMENT_PARSING_CODE}

    // Execute function
{FUNCTION_CALL_AND_RESULT_CODE}

    return 0;
}"""

    # Fill in all template placeholders
    driver_code = template.replace('{ARGC_COUNT}', str(argc_count))
    driver_code = driver_code.replace('{USAGE_PARAMS}', usage_params)
    driver_code = driver_code.replace('{ARGUMENT_PARSING_CODE}', arg_parsing_code)
    driver_code = driver_code.replace('{FUNCTION_CALL_AND_RESULT_CODE}', function_call_code)

    return driver_code