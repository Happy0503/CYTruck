
all : exec-t

full-t.o :  fullgc-t.c headers.h
	gcc -c fullgc-t.c -o full-t.o
	gcc full-t.o -o full-t

full-s.o : fullgc-s.c headers.h
	gcc -c fullgc-s.c -o full-s.o
	gcc full-s.o -o full-s

idavl.o : idavl.c headers.h
	gcc -c idavl.c -o idavl.o

test.o : test.c idavl.c headers.h
	gcc -c test.c -o test.o

progc-t.o : progc-t.c test.c
	gcc -c progc-t.c -o progc-t.o

exec-t : test.o progc-t.o idavl.o
	gcc idavl.o test.o progc-t.o -o exec-t

clean :
	rm -f *.o
	rm -f exec-t
	rm -f full-t
