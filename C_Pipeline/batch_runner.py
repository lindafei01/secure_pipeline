import os
from runner import run_pipeline


BASE_DIR = os.path.dirname(os.path.abspath(__file__))
TASK_DIR = os.path.join(BASE_DIR, "tasks")


def batch_run():
    # json_files = [f for f in os.listdir(TASK_DIR) if f.endswith(".json")]
    json_files = ["CWE-79_tasks.json"]
    for jf in json_files:
        path = os.path.join(TASK_DIR, jf)
        try:
            run_pipeline(path)
        except Exception as e:
            print(f"[!] Error in {jf}: {e}")

if __name__ == "__main__":
    batch_run()
