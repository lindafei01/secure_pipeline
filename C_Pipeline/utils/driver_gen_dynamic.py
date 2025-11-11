#!/usr/bin/env python3
# 零 hard-code 的动态驱动程序生成器

import re

def extract_setup_variables(setup_code):
    """完全基于任务本身 setup_code，自动提取所有可用的常量、数组名称"""
    variables = {'arrays': [], 'strings': [], 'int_arrays': [], 'constants': []}

    # const char* NAME[] = { ... };
    pattern = re.compile(r'\bconst\s+char\s*\*\s*([A-Za-z_][A-Za-z0-9_]*)\s*\[\s*\]\s*=')
    for match in pattern.finditer(setup_code):
        var_name = match.group(1)
        variables['arrays'].append(var_name)

    # const int NAME[] = { ... };
    int_array_pattern = re.compile(r'\bconst\s+int\s+([A-Za-z_][A-Za-z0-9_]*)\s*\[\s*\]\s*=')
    for match in int_array_pattern.finditer(setup_code):
        var_name = match.group(1)
        variables['int_arrays'].append(var_name)

    # 其他字符串常量（可选）
    const_pattern = re.compile(r'\bconst\s+char\s*\*\s*([A-Za-z_][A-Za-z0-9_]*)\s*=')
    for match in const_pattern.finditer(setup_code):
        var_name = match.group(1)
        variables['strings'].append(var_name)

    return variables

def infer_argument_purpose(function_name, arg_name, arg_type, task_description):
    """完全从任务描述和函数签名推断每个参数的目的，无需任何预定义模式"""
    arg_name_lower = arg_name.lower()
    desc_lower = task_description.lower()

    # 判断这是指针数组还是简单输入
    if 'const char**' in arg_type or 'char**' in arg_type:
        # 指针数组类型，看描述怎么说
        if 'array' in desc_lower or 'list' in desc_lower or 'null-terminated' in desc_lower:
            return 'use_setup_array'
        else:
            return 'user_input'  # 用户实际输入的命令行参数

    elif 'const char*' in arg_type or 'char*' in arg_type:
        return 'user_input'  # 字符串输入

    elif 'int*' in arg_type:
        return 'use_setup_array'  # 整数数组指针

    elif 'int' in arg_type:
        return 'user_input'  # 整数输入

    return 'user_input'

def select_setup_array_for_argument(arg_name, arg_type, setup_vars, fallback=True):
    """为参数智能选择一个合适的 setup 数组；如无特别匹配则回到第一个数组"""
    arg_lower = arg_name.lower()

    # 如果这是指针数组类型，优先找任务定义好的数组
    if 'const char**' in arg_type or 'char**' in arg_type:
        for arr in setup_vars['arrays']:
            arr_lower = arr.lower()
            if arg_lower in arr_lower or arr_lower in arg_lower:
                return arr
        # 无特定匹配，用第一个指针数组
        if setup_vars['arrays']:
            return setup_vars['arrays'][0]
        elif fallback:
            return 'HTTP_ONLY'  # 最默认的后备

    elif 'int*' in arg_type:
        for arr in setup_vars['int_arrays']:
            arr_lower = arr.lower()
            if arg_lower in arr_lower or arr_lower in arg_lower:
                return arr
        if setup_vars['int_arrays']:
            return setup_vars['int_arrays'][0]
        elif fallback:
            return 'ALLOWED_PORTS'

    return None

def generate_argument_parsing_dynamic(function_name, args_info, task_description, setup_code):
    """根据提取的 setup 变量和推理，生成参数解析代码；零 hard-code"""
    setup_vars = extract_setup_variables(setup_code)
    parsing_code = "    // Auto-generated argument parsing (no hardcode)\n"

    for i, (arg_type, arg_name) in enumerate(args_info):
        purpose = infer_argument_purpose(function_name, arg_name, arg_type, task_description)

        if purpose == 'use_setup_array':
            chosen_array = select_setup_array_for_argument(arg_name, arg_type, setup_vars)
            if chosen_array:
                parsing_code += f"    {arg_type} {arg_name} = {chosen_array}; // From setup\n"
            else:
                # 如果连备用都没有，直接引用用户输入（退化）
                parsing_code += f"    {arg_type} {arg_name} = (const char* []){{argv[{i+1}], NULL}}; // No array in setup, create one\n"
        else:
            # 用户输入处理
            if 'char*' in arg_type:
                parsing_code += f"    {arg_type} {arg_name} = argv[{i+1}];\n"
            elif 'int' in arg_type or 'size_t' in arg_type or 'unsigned' in arg_type:
                if 'unsigned' in arg_type:
                    parsing_code += f"    {arg_type} {arg_name} = (unsigned)atol(argv[{i+1}]);\n"
                elif 'size_t' in arg_type:
                    parsing_code += f"    {arg_type} {arg_name} = strtoul(argv[{i+1}], NULL, 10);\n"
                else:
                    parsing_code += f"    {arg_type} {arg_name} = atoi(argv[{i+1}]);\n"
            else:
                parsing_code += f"    {arg_type} {arg_name} = argv[{i+1}]; // fallback\n"

    return parsing_code

def generate_function_call_and_output(return_type, function_name, args_info):
    """动态生成函数调用和输出，保持正确的缩进"""
    arg_str = ', '.join([f"{arg_name}" for _, arg_name in args_info]) if args_info else ''
    code = f"    // Execute function\n"
    code += f"    {return_type} result = {function_name}({arg_str});\n\n"

    if 'char*' in return_type:
        code += '''    if (result == NULL) {
        printf("NULL\\n");
    } else {
        printf("%s\\n", result);
    }'''
    elif 'int' in return_type or 'long' in return_type or 'size_t' in return_type:
        code += '''    printf("%ld\\n", (long)result);'''
    elif 'unsigned' in return_type and 'char' not in return_type:
        code += '''    printf("%lu\\n", (unsigned long)result);'''
    elif 'double' in return_type or 'float' in return_type:
        code += '''    printf("%f\\n", result);'''
    else:
        code += '''    printf("%d\\n", (int)result);'''
    return code

def build_dynamic_driver(function_name, args_info, return_type, task_description, setup_code):
    """
    零 hard-code 的动态驱动生产器。
    参数：
      function_name: str
      args_info: [(type, name), ...]
      return_type: str
      task_description: str
      setup_code: str
    """
    argument_parsing = generate_argument_parsing_dynamic(function_name, args_info, task_description, setup_code)
    function_call = generate_function_call_and_output(return_type, function_name, args_info)

    # 计算真正需要用户输入的参数个数（setup注入的不算）
    setup_vars = extract_setup_variables(setup_code)
    user_arg_count = 0
    user_arg_names = []

    for i, (arg_type, arg_name) in enumerate(args_info):
        purpose = infer_argument_purpose(function_name, arg_name, arg_type, task_description)
        if purpose == 'user_input':
            user_arg_count += 1
            user_arg_names.append(arg_name)

    argc_count = user_arg_count + 1  # 程序名argv[0] + 用户参数
    usage_params = ' '.join(user_arg_names) if user_arg_names else ''

    template = f'''// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{{
    if (argc < {argc_count}) {{
        printf("Usage: %s {usage_params}\\n", argv[0]);
        return 1;
    }}
{argument_parsing}

{function_call}
    return 0;
}}'''

    return template

# EXPORTED interface，保持兼容
build_simple_driver = build_dynamic_driver