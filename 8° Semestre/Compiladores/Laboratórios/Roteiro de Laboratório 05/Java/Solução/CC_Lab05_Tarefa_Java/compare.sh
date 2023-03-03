#!/bin/bash

YEAR=$(pwd | grep -o '20..-.')
ROOT=/home/zambon/Teaching/$YEAR/CC/labs
ANTLR_PATH=$ROOT/tools/antlr-4.11.1-complete.jar
CLASS_PATH_OPTION="-cp .:$ANTLR_PATH"

GRAMMAR_NAME=EZ
BIN_PATH=bin

DATA=/home/zambon/Teaching/$YEAR/CC/labs/io
IN=$DATA/in
OUT=$DATA/out05_java

for infile in `ls $IN/c*.ezl`; do
    base=$(basename $infile)
    outfile=$OUT/${base/.ezl/.out}
    echo Running $base
    java $CLASS_PATH_OPTION:$BIN_PATH Main $infile 2>/dev/null | diff -w $outfile -
done
