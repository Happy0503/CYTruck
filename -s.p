set terminal png size 2000, 1000
set datafile separator ";"
set title "Option -s : Distance = f(Route)"
set xlabel "ROUTE ID"
set ylabel "DISTANCE KM"
set xtic rotate by 45 right
plot 'file-s.txt' using 0:2:xtic(1) title "min" with l
replot 'file-s.txt' using 0:3:xtic(1) title "moyenne" with l
replot 'file-s.txt' using 0:4:xtic(1) title "max" with l



#set terminal png size 500, 1000
set output "image.png" 
replot