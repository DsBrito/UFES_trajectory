#!/bin/bash

YEAR=$(pwd | grep -o '20..-.')
DATA=/home/zambon/Teaching/$YEAR/CC/labs/io
IN=$DATA/out07_c
OUT=$DATA/out07_c

EXE=./tmsim

for infile in `ls $IN/c*.tm`; do
    base=$(basename $infile)
    outfile=$OUT/${base/.tm/.out}
    echo Running $base
    $EXE < $infile > $outfile
done
