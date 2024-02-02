reset
set datafile separator ";"
set title "Option -s : Distance = f(Route)"
set xlabel "ROUTE ID"
set ylabel "DISTANCE KM"
set xtic rotate by 45 right
plot './temp/result_s.txt' using 0:4:2 title "Distance Max/Min" with filledcurve fc "skyblue"
replot './temp/result_s.txt' using 0:3:xtic(1) title "Distance Moyenne" with l lc "red"
 
set terminal png size 2000, 1000
set output "images/image_s.png" 
replot

