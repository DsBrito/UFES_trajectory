echo Inicializa build
rm -rf build
mkdir build && cd build
cmake ../
make
ctest --verbose --rerun-failed --output-on-failure
