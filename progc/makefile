all : d2 l t s


d2.o : prog_d2.c headers_d2.h
	gcc -c prog_d2.c -o d2.o

l.o : prog_l.c headers_l.h
	gcc -c prog_l.c -o l.o

t.o : prog_t.c headers_t_s.h
	gcc -c prog_t.c -o t.o

s.o : prog_s.c headers_t_s.h
	gcc -c prog_s.c -o s.o


d2 : d2.o
	gcc d2.o -o d2

l : l.o
	gcc l.o -o l

t : t.o
	gcc t.o -o t

s : s.o
	gcc s.o -o s


clean :
	rm -f *.o
	rm -f d2
	rm -f l
	rm -f t
	rm -f s
