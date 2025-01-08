import subprocess
import glob
from pathlib import Path

print("Compiling...")
build = Path('../build')
bin = Path('../bin')

if not build.exists() :
  build.mkdir()

if not bin.exists() :
  bin.mkdir()

c_files = glob.glob('../src/*.c')

if not c_files:
    print("No .c files found in the current directory.")
    exit(1)

try:
  obj_files = []
  for c_file in c_files:
    obj_file = f"../build/{Path(c_file).stem}.o"
    subprocess.run(['gcc', '-g', '-c', c_file, '-o', obj_file], check=True)
    obj_files.append(obj_file)

  print("Compilation to object files successful.")

  subprocess.run(['gcc', '-g', *obj_files, '-lreadline', '-o', '../bin/app'], check=True)
  print("Compiled to executable successfully.\nRunning:\n")

except subprocess.CalledProcessError as e:
  print(f"Compilation failed: {e}")
  exit(1)


try:
    subprocess.run(['valgrind','--leak-check=full', '--track-origins=yes', '--track-origins=yes', '../bin/app'], check=True)
except FileNotFoundError:
    print("Executable not found.")
except subprocess.CalledProcessError as e:
    print(f"Execution failed: {e}")
except KeyboardInterrupt:
    print("\nExecution was stopped forcefully.")

print("\nEnd.")
