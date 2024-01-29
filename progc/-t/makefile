
all : exec-t

tess.o :  fullgc-t.c headers.h
	gcc -c fullgc-t.c -o tss.o
	gcc tss.o -o full-t

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
