import subprocess
from typing import Iterable, List, Optional


def _normalize_sources(sources: Iterable[str]) -> List[str]:
    return [str(src) for src in sources]


def check_js(sources: Iterable[str], fail_on_error: bool = True) -> Optional[List[dict]]:
    """Run ``node --check`` against the provided sources.

    Args:
        sources: Iterable of file paths to check. Paths should be absolute.
        fail_on_error: When True, raise ``RuntimeError`` on the first failure.

    Returns:
        ``None`` if all sources pass the syntax check. Otherwise, a list of
        dictionaries describing the failed files when ``fail_on_error`` is False.
    """
    failed = []
    for source in _normalize_sources(sources):
        try:
            result = subprocess.run(
                ["node", "--check", source],
                capture_output=True,
                text=True,
                check=False,
            )
        except FileNotFoundError:
            error_info = {
                "source": source,
                "stderr": "node executable not found",
                "returncode": -1,
            }
            if fail_on_error:
                raise RuntimeError(error_info["stderr"])
            failed.append(error_info)
            continue

        if result.returncode != 0:
            error_info = {
                "source": source,
                "stderr": result.stderr,
                "returncode": result.returncode,
            }
            if fail_on_error:
                raise RuntimeError(f"JavaScript syntax check failed for {source}:\n{result.stderr}")
            failed.append(error_info)
    return None if not failed else failed
