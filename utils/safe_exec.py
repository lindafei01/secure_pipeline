import subprocess
import tempfile

def run_binary(binary_path, input_str, timeout=2):
    try:
        result = subprocess.run(
            [binary_path, input_str],
            capture_output=True,
            text=True,
            timeout=timeout
        )
        return {"stdout": result.stdout.strip(), "stderr": result.stderr.strip(), "exit_code": result.returncode}
    except subprocess.TimeoutExpired:
        return {"stdout": "", "stderr": "timeout", "exit_code": -1}
    except Exception as e:
        return {"stdout": "", "stderr": str(e), "exit_code": -1}
