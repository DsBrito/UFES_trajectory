#!/bin/bash

YEAR=$(pwd | grep -o '20..-.')
DATA=/home/zambon/Teaching/$YEAR/CC/labs/io
IN=$DATA/in
OUT=$DATA/out07_c

EXE=./lab07

for infile in `ls $IN/c*.ezl`; do
    base=$(basename $infile)
    outfile=$OUT/${base/.ezl/.tm}
    echo Compiling $base
    $EXE < $infile > $outfile
done
