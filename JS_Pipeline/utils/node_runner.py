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


def run_node(script_path: str, inputs: Union[str, Iterable[Union[str, int, float]], None] = None, timeout: int = 3):
    """Execute a Node.js script with the provided inputs.

    Args:
        script_path: Absolute path to the script to execute.
        inputs: Optional string or iterable of arguments to pass to the script.
        timeout: Maximum number of seconds to allow the process to run.

    Returns:
        A dictionary with keys ``stdout``, ``stderr``, and ``exit_code``.
    """
    args = _normalize_inputs(inputs)
    cmd = ["node", script_path, *args]

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
    except FileNotFoundError:
        return {"stdout": "", "stderr": "node executable not found", "exit_code": -1}
    except Exception as exc:  # pragma: no cover - defensive fallback
        return {"stdout": "", "stderr": str(exc), "exit_code": -1}
