#!/bin/bash


#Récupère les 10 trajets aux distances les plus longues par ordre croissant.
time cat ./data/data.csv | cut -f1,5 -d';' | sort | ./progc/l | sort -n -r | head -10 | sort -t";" -nk 2 > ./temp/result_l.txt
# DATA.CVS NOM A CHANGER : RECUP ARG 1



