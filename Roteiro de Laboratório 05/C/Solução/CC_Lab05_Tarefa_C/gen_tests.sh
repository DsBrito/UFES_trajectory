#!/bin/bash

YEAR=$(pwd | grep -o '20..-.')
DATA=/home/zambon/Teaching/$YEAR/CC/labs/io
IN=$DATA/in
OUT=$DATA/out05_c

EXE=./lab05

for infile in `ls $IN/*.ezl`; do
    base=$(basename $infile)
    outfile=$OUT/${base/.ezl/.out}
    dotfile=$OUT/${base/.ezl/.dot}
    pdffile=$OUT/${base/.ezl/.pdf}
    echo Running $base
    $EXE < $infile 1> $outfile 2> $dotfile
    dot -Tpdf $dotfile -o $pdffile
done
