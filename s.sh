#!/bin/bash


\time -p cat ./data/data.csv | sed "1d" | cut -f"1,5" -d";" | ./progc/s > ./temp/result_s.txt

