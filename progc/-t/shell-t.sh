#!/bin/bash

cd ../../data
#head -n6 data.csv|tail -n-5 >../temp/text.txt
#line_nbr=`wc -l data.csv|cut -d ' ' -f1`
#echo $line_nbr
#tail -n$((line_nbr-1)) data.csv >../temp/text.txt  
##head ../temp/text.txt
cd ../progc/-t
#ls 
#make all
#head ../temp/text.txt |./exec-t
make tess.o
#cat ../temp/text.txt |./tsss
cat ../../temp/text.txt |./tsss
make clean
