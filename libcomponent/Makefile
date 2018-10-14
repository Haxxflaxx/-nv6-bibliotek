.PHONY : lib
lib: libcomponent.so

libcomponent.so: Makefile libcomponent.c libcomponent.h
	gcc -c -fPIC libcomponent.c
	gcc -shared -fPIC -o libcomponent.so libcomponent.o

clean:
	rm *o component
