import os
import subprocess
from typing import Iterable, Optional


def compile_cpp(sources: Iterable[str], output: str, fail_on_error: bool = True, extra_flags: Optional[Iterable[str]] = None) -> Optional[dict]:
    """Compile C++ source files using g++."""
    sources = [os.path.abspath(src) for src in sources]
    output = os.path.abspath(output)
    work_dir = os.path.dirname(output) or "."

    flags = ["-std=c++17", "-O2", "-Wall", "-Wextra"]
    if extra_flags:
        flags.extend(extra_flags)

    cmd = ["g++", *flags, *sources, "-o", output]
    result = subprocess.run(cmd, cwd=work_dir, capture_output=True, text=True)

    if result.returncode != 0:
        error_info = {
            "sources": sources,
            "output": output,
            "stderr": result.stderr,
            "stdout": result.stdout,
            "returncode": result.returncode,
        }
        if fail_on_error:
            raise RuntimeError(f"C++ compilation failed for {sources}:\n{result.stderr}")
        return error_info
    return None
