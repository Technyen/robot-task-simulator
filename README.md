# Robot Task Simulator (C++ + Python)

## Overview

This project is a simple robot simulation system built with C++ and Python.

It demonstrates a layered architecture where:
- C++ acts as the execution engine (movement and logic)
- Python acts as the control layer (task orchestration)

The robot processes tasks defined as target positions and moves step by step until reaching each destination.

## Architecture

The system is divided into two main components:

- **C++ Engine**
  - Handles robot movement and task execution
  - Uses a queue-based system (FIFO)
  - Implements step-by-step navigation with logging

- **Python Controller**
  - Sends tasks to the C++ executable
  - Orchestrates multiple robot movements
  - Demonstrates multi-language integration


## 📁 Project Structure

```text
robot_test/
│
├── README.md
├── python/
│   └── controller.py
│
├── Robot.h
├── Robot.cpp
├── main.cpp
│
├── x64/
│   └── Debug/
│       └── robot_test.exe
```

## 🚀 How to Run

### 1. Build the C++ project

Use Visual Studio to compile the project.

### 2. Run Python controller

Navigate to the python folder:

```bash
cd python
```

Run:

```bash
py controller.py
```

---

## ⚙️ Example Output

```text
[PYTHON] Sending task (3, 2)
[INFO] Moving to (3, 2)
[STEP] Position: (1, 0)
[STEP] Position: (2, 0)
[STEP] Position: (3, 0)
[STEP] Position: (3, 1)
[STEP] Position: (3, 2)
[INFO] Reached destination!
```

---

## 🎯 Key Concepts Demonstrated

* Object-Oriented Programming (C++)
* Separation of Concerns
* Modular architecture (.h / .cpp separation)
* Queue-based task processing (FIFO)
* Multi-language integration (C++ + Python)
* Process orchestration using subprocess
