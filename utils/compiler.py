import subprocess

def compile_c(sources, output):
    cmd = ["gcc", "-O2", "-Wall", "-o", output, *sources]
    result = subprocess.run(cmd, capture_output=True, text=True)
    if result.returncode != 0:
        raise RuntimeError(f"Compilation failed:\n{result.stderr}")