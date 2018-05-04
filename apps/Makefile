default: makekeys
all: default

ecc.o: ../src/ecc.c ../inc/ecc.h
	gcc -g -o ecc.o -c ../src/ecc.c

makekeys.o: makekeys.c ../inc/ecc.h
	gcc -I.. -g -o makekeys.o -c makekeys.c

makekeys: ecc.o makekeys.o
	gcc -o makekeys makekeys.o ecc.o

clean:
	rm -f ecc.o makekeys.o makekeys

.PHONY: default all clean
