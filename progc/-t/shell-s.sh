
make full-s.o
\time -p cat ../../data/data.csv | sed "1d"|cut -f"1,5" -d";"|./full-s > ../../temp/file-s.txt
make clean
