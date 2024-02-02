#!/bin/bash
# à faire :
#Temps d'éxecution à afficher


#Vérifie si le -h est présent, afin d'afficher l'aide et quitter le code
for j in `seq $#` ; do
	if [ ${!j} == '-h' ] ; then
		echo `cat 'README.md'`
		exit 0
	fi
done


#Vérification du nombre d'arguments
if [ $# -lt 2 ] ; then
	echo "Mauvais nombre d'arguments."
	exit 1
fi


#Vérification de la présence du dossier images, et (re)création du dossier temp vidé
if [ ! -d './images' ] ; then
	mkdir images
fi
rm -rf ./temp
mkdir temp


#Stockage de l'argument
data=$1


#Variables vérifiant si une commande a déjà été effectuée
flag_d1=0
flag_d2=0
flag_l=0
flag_t=0
flag_s=0


#Vérification que l'argument 1 est un fichier
if [ ! -f "$data" ] ; then
	echo "L'argument donné n'est pas un fichier."
	exit 2
fi


#Vérification de la présence des éxecutables C
#if [ ! -f './progc/test' ] || [ ! -x './progc/test' ] ; then
#	echo "L'éxéctubale n'était pas présent, tentative de compilation."
#	cd ./progc
#	make
#	if [ $? -ne 0 ] ; then #Si le retour de 'make' est différent de 0, exit
#		echo "Compilation échouée, sortie du programme."
#		exit 3
#	fi
#	cd ..
#fi


#Boucle sur les autres arguments qui va vérifier les commandes demandées. Sinon : exit problème d'arguments
for i in `seq 2 $#` ; do #Parcours les arguments à partir du 2e
	process=${!i} #process prend la valeur de l'argument i ème
	
	case $process in
	
		'-d1')
			if [ $flag_d1 -eq 0 ] ; then
				flag_d1=1
				#echo "D1" #remplacer par l'éxection -d1 dans un autre fichier
				./d1.sh
			fi
			;;
		
		'-d2')
			if [ $flag_d2 -eq 0 ] ; then
				flag_d2=1
				#echo "D2"
				./d2.sh
			fi
			;;
		
		'-l')
			if [ $flag_l -eq 0 ] ; then
				flag_l=1
				#echo "L"
				./l.sh
			fi
			;;
		
		'-t')
			if [ $flag_t -eq 0 ] ; then
				flag_t=1
				#echo "T"
				./t.sh
			fi
			;;
		
		'-s')
			if [ $flag_s -eq 0 ] ; then
				flag_s=1
				#echo "S"
				./s.sh
			fi
			;;
		
		*) #Default
			echo default
			;;
		
	esac
	
	echo "Temps de l'éxecution 1 : $i"
done








#$? = Variable ayant le code retour de la dernière commande
#time cat data.cvs | cut -d';' -f1,6
#Outil : AWK : permet de passer en argument un bout de code à éxecuter sur les données qui arrivent
#awk '{tab[$1] += 1} END {for (v in tab) {print v";"tab[v]} }' // Compte le nombre d'itération de $1 et l'affiche
