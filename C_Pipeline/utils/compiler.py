import subprocess

def compile_c(sources, output, fail_on_error=True):
    """编译C源文件，如果fail_on_error=False则返回错误信息而不是抛出异常"""
    cmd = ["gcc", "-O2", "-Wall", "-o", output, *sources]
    result = subprocess.run(cmd, capture_output=True, text=True)

    if result.returncode != 0:
        error_info = {
            'sources': sources,
            'output': output,
            'stderr': result.stderr,
            'error_summary': 'Compilation failed',
            'returncode': result.returncode
        }
        if fail_on_error:
            raise RuntimeError(f"Compilation failed:\n{result.stderr}")
        else:
            return error_info
    return None  # 表示成功编译