import os
from runner import run_pipeline

TASK_DIR = "tasks"

def batch_run():
    json_files = [f for f in os.listdir(TASK_DIR) if f.endswith(".json")]
    for jf in json_files:
        path = os.path.join(TASK_DIR, jf)
        try:
            run_pipeline(path)
        except Exception as e:
            print(f"[!] Error in {jf}: {e}")

if __name__ == "__main__":
    batch_run()
