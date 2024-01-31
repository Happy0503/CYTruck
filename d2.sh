#!/bin/bash


#Récupère les 10 conducteurs ayant la plus grande distance parcourue par ordre décroissant.
time cat ./data/data.csv | sed -e 1d | cut -f5,6 -d';' | ./d2 | sort -n -r | head -10 > ./temp/result_d2.txt
# DATA.CVS NOM A CHANGER : RECUP ARG 1


#time cat ./data/data.csv | sed -e 1d | cut -f5,6 -d';' | ./d2 > ./temp/result_d2.txt