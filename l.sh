#!/bin/bash


#Récupère les 10 trajets aux distances les plus longues par ordre croissant.
time cat ./data/data.csv | cut -f1,5 -d';' | sort | ./l | sort -n -r | head -10 | sort -n > ./temp/result_l.txt
# DATA.CVS NOM A CHANGER : RECUP ARG 1


#time cat ./data/data.csv | cut -f1,5 -d';' | sort | ./l > ./temp/result_l.txt






