#!/bin/bash


#Pour ce traitement, vous devez récupérer la distance totale parcourue
#par chaque conducteur, c’est à dire faire la somme des distances de
#toutes les étapes qui leurs sont associées. Vous ne garderez que les 10
#plus grandes distances classées par ordre décroissant.



#virer la 1e ligne du data.csv!
time cat ./data/data.csv | cut -f5,6 -d';' | ./programme_c_d2


