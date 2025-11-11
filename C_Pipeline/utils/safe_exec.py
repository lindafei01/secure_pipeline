import subprocess
import tempfile

def run_binary(binary_path, inputs, timeout=2):
    """Enhanced secure binary execution with timeout and multi-parameter support
    inputs can be either a single string or a list/array of arguments
    """
    try:
        if isinstance(inputs, str):
            # 单参数情况（兼容旧代码）
            cmd = [binary_path, inputs]
        elif isinstance(inputs, (list, tuple)):
            # 多参数情况 - 输入已经是一个参数列表
            cmd = [binary_path] + list(inputs)
        else:
            # 默认转换为字符串
            cmd = [binary_path, str(inputs)]

        result = subprocess.run(
            cmd,
            capture_output=True,
            text=True,
            timeout=timeout
        )
        return {"stdout": result.stdout.strip(), "stderr": result.stderr.strip(), "exit_code": result.returncode}
    except subprocess.TimeoutExpired:
        return {"stdout": "", "stderr": "timeout", "exit_code": -1}
    except Exception as e:
        return {"stdout": "", "stderr": str(e), "exit_code": -1}
