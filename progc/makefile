
all : exec

test.o : test.c headers.h
	gcc -c test.c -o test.o

main.o : main.c test.c
	gcc -c main.c -o main.o

exec : test.o main.o
	gcc test.o main.o -o exec

clean :
	rm -f *.o
	rm -f exec
