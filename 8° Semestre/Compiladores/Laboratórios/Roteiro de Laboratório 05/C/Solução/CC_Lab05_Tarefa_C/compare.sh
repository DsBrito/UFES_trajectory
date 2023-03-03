#!/bin/bash

YEAR=$(pwd | grep -o '20..-.')
DATA=/home/zambon/Teaching/$YEAR/CC/labs/io
IN=$DATA/in
OUT=$DATA/out05_c

EXE=./lab05

for infile in `ls $IN/*.ezl`; do
    base=$(basename $infile)
    outfile=$OUT/${base/.ezl/.out}
    echo $infile
    $EXE < $infile 2> /dev/null | diff -w $outfile -
done
