#!/bin/bash


\time -p cat $1 | sed "1d" | cut -f"1,5" -d";" | ./progc/s > ./temp/result_s.txt

echo 'load "-s.p"' | gnuplot
