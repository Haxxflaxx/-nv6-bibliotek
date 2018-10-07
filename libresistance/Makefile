# Jonas Svensson, 700707-5679

.PHONY : lib
lib: libresistance.so

libresistance.so: Makefile resistance.c resistance.h
	gcc -c -fPIC resistance.c
	gcc -shared -fPIC -o libresistance.so resistance.o

.PHONY : test
test: resistance

resistance: Makefile resistance.c resistance.h test.c
	gcc -Wall -o resistance resistance.c test.c

.PHONY : clean
clean :
	rm -f resistance *.o *.so *~

