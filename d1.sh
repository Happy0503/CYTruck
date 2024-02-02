#!/bin/bash


#Récupère les 10 conducteurs ayant le plus de trajets par ordre décroissant.
time cat $1 | cut -f1,6 -d';' | sort | uniq | cut -f2 -d';' | sort | uniq -c | sort -n -r | head -10 | sed -e 's/^[ \t]*//' | awk '{printf"%d;%s %s\n",$1,$2,$3}' > ./temp/result_d1.txt

echo 'load "-d1.p"' | gnuplot

convert images/image_d1.png -rotate 90 images/image_d1.png
