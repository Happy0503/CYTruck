reset
set datafile separator ";"
set boxwidth 0.75
set xlabel "Conducteur" rotate by 180
set ylabel "Distance total selon Conducteur" 
set y2label "Distance totale en Km" rotate by 90 offset 2
set grid ytics linestyle 0
set style fill solid 0.5 border 5 
set xtic rotate by 90 right
set ytic offset 101 rotate by 90
plot "./temp/result_d2.txt" using 0:1:xtic(2) title "Distance totale" with boxes




set terminal png size 1000, 1000
set output "images/image_d2.png" 
replot
