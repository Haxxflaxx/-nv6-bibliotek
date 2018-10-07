# Jonas Svensson, 700707-5679


.PHONY: lib
lib:
	cd libresistance;make lib

.PHONY: all
all: electrotest

electrotest: electrotest.c Makefile lib
	gcc -Wall -o electrotest electrotest.c -Ilibresistance/ -Llibresistance/ -lresistance -Wl,-rpath,libresistance/

install:
	cp electrotest /usr/bin/
	cp lib*/*.so /usr/lib/
