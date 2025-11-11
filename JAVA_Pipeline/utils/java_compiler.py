import os
import subprocess
from typing import Optional


def compile_java(source: str, fail_on_error: bool = True) -> Optional[dict]:
    """Compile a Java source file using ``javac``.

    Args:
        source: Absolute path to the ``.java`` source file.
        fail_on_error: When True, raise ``RuntimeError`` if compilation fails.

    Returns:
        ``None`` on success. On failure (and ``fail_on_error`` is False) returns a
        dictionary describing the error.
    """
    source = os.path.abspath(source)
    work_dir = os.path.dirname(source)

    cmd = ["javac", source]
    result = subprocess.run(cmd, cwd=work_dir, capture_output=True, text=True)

    if result.returncode != 0:
        error_info = {
            "source": source,
            "stderr": result.stderr,
            "stdout": result.stdout,
            "returncode": result.returncode,
        }
        if fail_on_error:
            raise RuntimeError(f"Java compilation failed for {source}:\n{result.stderr}")
        return error_info
    return None
