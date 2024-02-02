reset
set datafile separator ";"
set boxwidth 0.75
set xlabel "Numero Trajet"
set title "Distance totale selon Trajet"
set ylabel "Distance en Km"
set grid ytics linestyle 0
set style fill solid 0.5 border 5 
plot "./temp/result_l.txt" using 0:1:xtic(2) title "Distance Totale" with boxes

set terminal png size 1000, 1000
set output "images/image_l.png" 
replot
