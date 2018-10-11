# Daniel Arnqvist, 890410-4877

.PHONY: lib
lib: libpower.so

libpower.so: power.c power.h
	gcc -c -fPIC power.c
	gcc -shared -fPIC -o libpower.so power.o

.PHONY: test
test: power

power: libpower.so power.h test.c
	gcc -Wall -o power test.c -L. -lpower

.PHONY: clean
clean:
	rm -f power *.o *.so
