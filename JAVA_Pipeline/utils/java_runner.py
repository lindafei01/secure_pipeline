import os
import subprocess
from typing import Iterable, List, Optional, Union


def _normalize_inputs(inputs: Union[str, Iterable[Union[str, int, float]], None]) -> List[str]:
    if inputs is None:
        return []
    if isinstance(inputs, str):
        return [inputs]
    if isinstance(inputs, Iterable):
        return [str(item) for item in inputs]
    return [str(inputs)]


def run_java(class_name: str, working_dir: str, inputs: Union[str, Iterable[Union[str, int, float]], None] = None, timeout: int = 3):
    """Execute a compiled Java class.

    Args:
        class_name: Fully qualified class name to execute.
        working_dir: Directory containing class files (added to classpath).
        inputs: Optional CLI arguments for ``main``.
        timeout: Seconds before aborting execution.

    Returns:
        A dictionary with keys ``stdout``, ``stderr`` and ``exit_code``.
    """
    args = _normalize_inputs(inputs)
    cmd = ["java", "-cp", working_dir, class_name, *args]

    try:
        result = subprocess.run(
            cmd,
            cwd=working_dir,
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
        return {"stdout": "", "stderr": "java executable not found", "exit_code": -1}
    except Exception as exc:  # pragma: no cover - defensive fallback
        return {"stdout": "", "stderr": str(exc), "exit_code": -1}
