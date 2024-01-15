#!/bin/bash


#Vous devez récupérer la liste des conducteurs avec le nombre de trajets différents qu’ils ont effectués. Depuis cette liste, triée par ordre 
#décroissant de nombre de trajets, vous ne devez garder que les 10 premiers conducteurs.



# DATA.CVS NOM A CHANGER : RECUP ARG 1
time cat ./data/data.csv | cut -f1,6 -d';' | sort | uniq | cut -f2 -d';' | sort | uniq -c | sort -n -r | head -10

