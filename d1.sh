#!/bin/bash


#Récupère les 10 conducteurs ayant le plus de trajets par ordre décroissant.
time cat ./data/data.csv | cut -f1,6 -d';' | sort | uniq | cut -f2 -d';' | sort | uniq -c | sort -n -r | head -10 | sed -e 's/^[ \t]*//' > ./temp/result_d1.txt
# DATA.CVS NOM A CHANGER : RECUP ARG 1














#Pour plus tard : commande "convert" // http://www.phyast.pitt.edu/~zov1/gnuplot/html/histogram.html
