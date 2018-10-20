# Jonas Svensson, 700707-5679


.PHONY: lib
lib:
	cd libresistance;make lib
	cd libcomponent;make lib
	cd libpower;make lib

.PHONY: all
all: RPATH_OPT = -Wl,-rpath,libresistance/ -Wl,-rpath,libcomponent/  -Wl,-rpath,libpower/
all: electrotest

electrotest: electrotest.c Makefile lib
	gcc -Wall -o electrotest electrotest.c -Ilibresistance/ -Llibresistance/ -lresistance -Ilibcomponent/ -Llibcomponent/ -lcomponent -Ilibpower/ -Llibpower/ -lpower $(RPATH_OPT)

.PHONY: install
install: RPATH_OPT =
install: electrotest lib
	cp electrotest /usr/bin/
	cp lib*/*.so /usr/lib/
