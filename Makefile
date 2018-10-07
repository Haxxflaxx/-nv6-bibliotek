# Jonas Svensson, 700707-5679


.PHONY: lib
lib: libresistance/libresistance.so
	cd libresistance;make

.PHONY: all
all: electrotest

electrotest: electrotest.c Makefile
	gcc -Wall -o electrotest electrotest.c -Ilibresistance/ -Llibresistance/ -lresistance -Wl,-rpath,libresistance/

install:
	cp electrotest /usr/bin/
	cp lib/* /usr/lib/
