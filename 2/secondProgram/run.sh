echo "Compiling..."
if [ ! -d "./build" ]; then
  mkdir ./build
fi  
gcc *.c -o ./build/app -lm
echo "Compiled."

echo $'\nStarting program:'
./build/app
echo "End."
