# Jonas Svensson, 700707-5679

.PHONY : lib
lib: libresistance.so

libresistance.so: Makefile resistance.c resistance.h
	gcc -c -fPIC resistance.c
	gcc -shared -fPIC -o libresistance.so resistance.o

.PHONY : test
test: resistance

resistance: Makefile libresistance.so resistance.h test.c
	gcc -Wall -o resistance test.c -L. -lresistance -Wl,-rpath,.

.PHONY : clean
clean :
	rm -f resistance *.o *.so *~

