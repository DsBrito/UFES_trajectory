#!/bin/bash

YEAR=$(pwd | grep -o '20..-.')
ROOT=/home/zambon/Teaching/$YEAR/CC/labs
ANTLR_PATH=$ROOT/tools/antlr-4.11.1-complete.jar
CLASS_PATH_OPTION="-cp .:$ANTLR_PATH"

GRAMMAR_NAME=EZLexer
GEN_PATH=lexer

DATA=/home/zambon/Teaching/$YEAR/CC/labs/io
IN=$DATA/in
OUT=$DATA/out01_java

cd $GEN_PATH
for infile in `ls $IN/*.ezl`; do
    base=$(basename $infile)
    outfile=$OUT/${base/.ezl/.out}
    echo Running $base
    java $CLASS_PATH_OPTION org.antlr.v4.gui.TestRig $GRAMMAR_NAME tokens -tokens $infile 2>&1 | diff -w $outfile -
done
