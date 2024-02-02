reset
set datafile separator ";"
set style histogram clustered gap 1 title textcolor lt -1
set style data histograms
set style fill solid 1  solid 1
set title "Trajet et depart par Ville"
set xlabel "VILLES"
set ylabel "NOMBRE DE TRAJETS"
set ytic 0, 100
set xtic rotate by 90 right
set grid ytic linestyle  0
plot './temp/result_t.txt' using 3:xtic(1) title "départ"
replot './temp/result_t.txt' using 2  title "passage"


set terminal png size 500, 1000
set output "images/image_t.png" 
replot
