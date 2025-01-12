import subprocess
import glob
from pathlib import Path

print("Compiling...")
base_dir = Path(__file__).resolve().parent.parent
build = base_dir / 'build'
bin = base_dir / 'bin'
src_pattern = base_dir / 'src' / '*.c'

if not build.exists():
    build.mkdir()

if not bin.exists():
    bin.mkdir()

c_files = glob.glob(str(src_pattern))

if not c_files:
    print("No .c files found in the current directory.")
    exit(1)

try:
    obj_files = []
    for c_file in c_files:
        obj_file = build / f"{Path(c_file).stem}.o"
        subprocess.run(['gcc', '-g', '-c', c_file, '-o', str(obj_file)], check=True)
        obj_files.append(str(obj_file))

    print("Compilation to object files successful.")

    subprocess.run(['gcc', '-std=gnu99', '-g', *obj_files, '-lreadline', '-o', str(bin / 'app')], check=True)
    print("Compiled to executable successfully.")

except subprocess.CalledProcessError as e:
    print(f"Compilation failed: {e}")
    exit(1)

print("End.")
