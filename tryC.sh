#!/bin/sh
#textR using
rm result.txt
make clean
make main

./main dictionary1.txt input1.txt relation.txt result.txt
cat result.txt
