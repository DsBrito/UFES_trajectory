#!/bin/bash

dir="${PWD}/../../"
echo $dir

valgrind $dir/trab3 $dir/../example/ < $dir/../example/searches.txt > $dir/output.txt
diff -c --strip-trailing-cr $dir/../example/sol.txt $dir/output.txt

valgrind $dir/trab3 $dir/../example1/ < $dir/../example1/searches.txt > $dir/output.txt
diff -c --strip-trailing-cr $dir/../example1/sol.txt $dir/output.txt

$dir/trab3 $dir/../example2/ < $dir/../example2/searches.txt > $dir/output.txt
diff -c --strip-trailing-cr $dir/../example2/sol2.txt $dir/output.txt

