# Python controller for the C++ robot executable
import subprocess

# List of tasks (target positions)
tasks = [(3, 2), (0, 0), (2, 1)]

for t in tasks:
    print(f"[PYTHON] Sending task {t}")

    # Execute the compiled C++ program with arguments (x, y)
    subprocess.run(["../x64/Debug/robot_test.exe", str(t[0]), str(t[1])])