#!/bin/bash


#Récupère les 10 conducteurs ayant la plus grande distance parcourue par ordre décroissant.
time cat $1 | sed -e 1d | cut -f5,6 -d';' | ./progc/d2 | sort -n -r | head -10 > ./temp/result_d2.txt

echo 'load "-d2.p"' | gnuplot

convert images/image_d2.png -rotate 90 images/image_d2.png
