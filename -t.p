set terminal png size 2000, 1000
set datafile separator ";"
set style histogram clustered gap 1 title textcolor lt -1
set style data histograms
set style fill solid 1  solid 1
set title "Trajet et depart par Ville"
set xlabel "VILLES"
set ylabel "NOMBRE DE TRAJETS"
set xtic 100
plot 'file-t.txt' using 3:xtic(1)
replot 'file-t.txt' using 2 
#replot 'file-s.txt' using 0:3:xtic(1) title "Départ" with l



set output "image.png" 
replot