#!/bin/bash

set style data histogram
plot "./temp/result_d1.txt" using 2:xtic(1) linecolor "blue"
unset key
set style fill solid
set title "Titre"
set xlabel "x"
set ylabel "y"
replot






#https://ict4g.net/adolfo/notes/emacs/gnuplot-histogram.html
#https://gnuplot.sourceforge.net/demo_5.4/histograms.html

#Pour plus tard : commande "convert" // http://www.phyast.pitt.edu/~zov1/gnuplot/html/histogram.html
