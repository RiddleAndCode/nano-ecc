CFLAGS = -g -Wall -Werror -fPIC
CC = gcc
LD = ld
all: nano_ecc

ecc.o: ../inc/ecc.c ../inc/ecc.h
	$(CC) $(CFLAGS) -c -o ecc.o ../inc/ecc.c

*.o: *.c api.h
	$(CC) -c $(CFLAGS) $< -o $@

nano_ecc: nano_ecc_wrap.o api.o ecc.o
	$(LD) -shared -belf64-x86-64 -o nano_ecc.so  nano_ecc_wrap.o api.o ecc.o 

clean:
	rm -f *.o nano_ecc.so nano_ecc_wrap.c *.class
