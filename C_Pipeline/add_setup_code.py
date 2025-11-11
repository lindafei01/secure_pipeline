import json

# 统一的 setup_code,只包含必要的头文件
SETUP_CODE = """#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
"""

def add_setup_code_to_dataset(input_file, output_file):
    """为数据集中的每个任务添加 setup_code"""
    
    with open(input_file, 'r', encoding='utf-8') as f:
        tasks = json.load(f)
    
    # 为每个任务添加 setup_code
    for task in tasks:
        task['setup_code'] = SETUP_CODE
    
    # 保存到新文件
    with open(output_file, 'w', encoding='utf-8') as f:
        json.dump(tasks, f, indent=2, ensure_ascii=False)
    
    print(f"✅ 已为 {len(tasks)} 个任务添加 setup_code")
    print(f"📁 输出文件: {output_file}")

# 使用示例
if __name__ == "__main__":
    add_setup_code_to_dataset('tasks/CWE-20_tasks.json', 'tasks/CWE-20_tasks.json')