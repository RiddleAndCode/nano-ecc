CFLAGS = -g -Wall -Werror -fPIC
CC = gcc
LD = ld
all: nano_ecc

ecc.o: ../src/ecc.c ../inc/ecc.h
	$(CC) $(CFLAGS) -c -o ecc.o ../src/ecc.c

*.o: *.c 
	$(CC) -c $(CFLAGS) $< -o $@

nano_ecc: nano_ecc_wrap.o ecc.o
	$(LD) -shared -belf64-x86-64 -o libjnano_ecc.so nano_ecc_wrap.o ecc.o 
	javac *.java

clean:
	rm -f *.o *.class *.so
