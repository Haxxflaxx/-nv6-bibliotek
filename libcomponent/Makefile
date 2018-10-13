CC = gcc
CFLAGS = -c -Wall

all: component

component: libcomponenttest.o libcomponent.o
	$(CC) -o component libcomponenttest.o libcomponent.o

main.o: libcomponenttest.c
	$(CC) $(CFLAGS) libcomponenttest.c

libcomponent.o: libcomponent.c libcomponent.h
	$(CC) $(CFLAGS) libcomponent.c	

clean:
	rm *o component
