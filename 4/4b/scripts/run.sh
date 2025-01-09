echo "Compiling..."
if [ ! -d "./build" ]; then
  mkdir ./build
fi
gcc *.c -g -o ./build/app -lreadline
echo "Compiled."
echo $'Starting program:'
# valgrind ./build/app
./build/app
echo $'\nEnd.'
