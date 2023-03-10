#!/bin/bash

YEAR=$(pwd | grep -o '20..-.')
DATA=/home/zambon/Teaching/$YEAR/CC/labs/io
IN=$DATA/in
OUT=$DATA/out03_c

EXE=./lab03

for infile in `ls $IN/*.ezl`; do
    base=$(basename $infile)
    outfile=$OUT/${base/.ezl/.out}
    $EXE < $infile > $outfile
done
