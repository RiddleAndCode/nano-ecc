CFLAGS = -g -Wall -Werror

all: nano_ecc
	make -C apps all
	make -C java all
	make -C test all

ecc.o: src/ecc.c inc/ecc.h
	$(CC) $(CFLAGS) -c -o src/ecc.o src/ecc.c

%.o: %.c ../inc/ecc.h
	$(CC) -c $(CFLAGS) $< -o $@

nano_ecc: ecc.o
	mkdir -p lib
	ar rcs lib/libnano_ecc.a src/ecc.o

clean:
	rm -f src/*.o lib/*
	make -C apps clean
	make -C java clean
	make -C test clean
