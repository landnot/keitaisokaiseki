#!/bin/sh
#textR using
rm result.txt
make clean
make main

./main dictionary2.txt input2.txt relation.txt result.txt
cat result.txt
