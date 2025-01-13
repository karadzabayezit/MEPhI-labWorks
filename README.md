# Project Description

This is a MEPhI project for the course **"Introduction to Programming in C"**. The project is a simple console application that works with different types of data structures.

## Compilation and Running

### Task 1 and Task 2
To compile and run the first two tasks, use the following command:

```bash
gcc -o task1 task1.c
```

### Other Tasks
For the remaining tasks, you can use scripts (Bash, Python) or Makefile:

#### Using Python
```bash
cd project_folder/scripts
python run.py
```

#### Using Makefile
```bash
make watch
```
Then navigate to the `bin` directory and run the program with:
```bash
./app
```
For **Lab 5**, use the `-h` option to see available commands:
```bash
./app -h
```

## Directory Structure

- **`src/`**: Source code files.
- **`include/`**: Header files.
- **`scripts/`**: Python and Bash scripts for running tasks.
- **`build/`**: Compiled object files.
- **`bin/`**: Executable files.

---

### Notes
This project follows a basic C project structure.
