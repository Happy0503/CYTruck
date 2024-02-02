#!/bin/bash


\time -p cat ./data/data.csv | sed "1d" | cut -f"1,2,3,4" -d";" | sort -rn -t";" -k 2 | ./progc/t > ./temp/result_t.txt

