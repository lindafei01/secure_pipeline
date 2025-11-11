import os
import subprocess
from typing import Iterable, List, Union


def _normalize_inputs(inputs: Union[str, Iterable[Union[str, int, float]], None]) -> List[str]:
    if inputs is None:
        return []
    if isinstance(inputs, str):
        return [inputs]
    if isinstance(inputs, Iterable):
        return [str(item) for item in inputs]
    return [str(inputs)]


def run_binary(binary_path: str, inputs: Union[str, Iterable[Union[str, int, float]], None] = None, timeout: int = 3):
    binary_path = os.path.abspath(binary_path)
    args = _normalize_inputs(inputs)
    cmd = [binary_path, *args]

    try:
        result = subprocess.run(
            cmd,
            capture_output=True,
            text=True,
            timeout=timeout,
            check=False,
        )
        return {
            "stdout": result.stdout.strip(),
            "stderr": result.stderr.strip(),
            "exit_code": result.returncode,
        }
    except subprocess.TimeoutExpired:
        return {"stdout": "", "stderr": "timeout", "exit_code": -1}
    except Exception as exc:  # pragma: no cover
        return {"stdout": "", "stderr": str(exc), "exit_code": -1}
