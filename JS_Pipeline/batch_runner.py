import os

from runner import run_pipeline

BASE_DIR = os.path.dirname(os.path.abspath(__file__))
TASK_DIR = os.path.join(BASE_DIR, "tasks")


def batch_run():
    if not os.path.exists(TASK_DIR):
        print(f"[!] Task directory '{TASK_DIR}' does not exist.")
        return

    # json_files = sorted(f for f in os.listdir(TASK_DIR) if f.endswith(".json"))
    json_files = ["CWE-78_tasks.json"]
    for filename in json_files:
        path = os.path.join(TASK_DIR, filename)
        try:
            run_pipeline(path)
        except Exception as exc:
            print(f"[!] Error in {filename}: {exc}")


if __name__ == "__main__":
    batch_run()
