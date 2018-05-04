default: makekeys
all: default

makekeys.o: makekeys.c ../inc/ecc.h
	gcc -I.. -g -o makekeys.o -c makekeys.c

makekeys: makekeys.o
	mkdir -p ../bin
	gcc -o ../bin/makekeys makekeys.o -L../lib -lnano_ecc

clean:
	rm -f ecc.o makekeys.o ../bin/makekeys

.PHONY: default all clean
