Cy-Trucks

Ce programme génère des histogrammes, ou un graphique à partir d'un fichier data contenant des données de trajets routiers des camions.

Utilisation : CyTrucks.sh [Fichier data] [Option]...

Le fichier data est nécessairement le premier argument. Plusieurs options peuvent être utilisés.
Si le fichier data est manquant, ou qu'il n'y a aucun arugment, le programme ne fera rien.

Liste des options :

	-d1,	Génère un histogramme horizontal des 10 conducteurs ayant le plus de trajets, par ordre décroissant.
	-d2,	Génère un histogramme horizontal des 10 conducteurs ayant parcouru le plus de kilomètres, par ordre décroissant.
	-l,	Génère un histogramme vertical des 10 trajets aux distances les plus longues, par ordre croissant.
	-t,	Génère un histogramme regroupé des 10 villes ayant le plus de trajets, par ordre alphabétique.
	-s,	Calcule la distance minimale, maximale et moyenne des distances des étapes de chaques trajets, et génère un graphique des 50 premiers trajets. 

Les images générées seront dans un dossier "images" sous format pdf, avec comme nom : result_[Option choisie].pdf.
