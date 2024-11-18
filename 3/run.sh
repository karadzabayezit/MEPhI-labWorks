echo "Compiling..."
if [ ! -d "./build" ]; then
  mkdir ./build
fi
gcc *.c -g -o ./build/app -lm
echo "Compiled."
echo $'Starting program:'
./build/app
echo $'\nEnd.'
