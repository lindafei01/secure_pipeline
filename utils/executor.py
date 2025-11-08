import subprocess, os, signal

def run_executable_safe(executable, args=None, timeout=2):
    args = args or []
    try:
        proc = subprocess.Popen(
            [executable] + args,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            preexec_fn=os.setsid
        )
        try:
            out, err = proc.communicate(timeout=timeout)
        except subprocess.TimeoutExpired:
            os.killpg(os.getpgid(proc.pid), signal.SIGKILL)
            return {"status": "timeout", "stdout": "", "stderr": "", "exit_code": -1}

        code = proc.returncode
        if code < 0:
            sig = -code
            sig_name = signal.Signals(sig).name if sig in signal.Signals.__members__.values() else f"SIG{sig}"
            return {"status": f"crash:{sig_name}", "stdout": out, "stderr": err, "exit_code": code}
        elif code > 0:
            if "AddressSanitizer" in err or "runtime error" in err:
                return {"status": "crash:asan", "stdout": out, "stderr": err, "exit_code": code}
            return {"status": "error", "stdout": out, "stderr": err, "exit_code": code}
        else:
            return {"status": "ok", "stdout": out, "stderr": err, "exit_code": 0}
    except Exception as e:
        return {"status": "error", "stdout": "", "stderr": str(e), "exit_code": -999}
