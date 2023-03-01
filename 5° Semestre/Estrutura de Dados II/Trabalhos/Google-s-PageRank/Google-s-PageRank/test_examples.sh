#valgrind ./build/trab3 ./example/ < ./example/searches.txt > out.txt
./build/trab3 ./example/ < ./example/searches.txt > out.txt
diff --strip-trailing-cr example/sol.txt out.txt

#valgrind ./build/trab3 ./example1/ < ./example1/searches.txt > out.txt
./build/trab3 ./example1/ < ./example1/searches.txt > out.txt
diff --strip-trailing-cr example1/sol.txt out.txt

#valgrind ./build/trab3 ./example2/ < ./example2/searches.txt > out.txt
./build/trab3 ./example2/ < ./example2/searches.txt > out.txt
diff --strip-trailing-cr example2/sol2.txt out.txt
