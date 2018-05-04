CFLAGS = -g -Wall -Werror -fPIC
CC = gcc
LD = ld
all: nano_ecc

*.o: *.c 
	$(CC) -c $(CFLAGS) $< -o $@

nano_ecc: nano_ecc.o
	$(LD) -shared -L../lib -lnano_ecc -belf64-x86-64 -o libnano_ecc.so nano_ecc.o 
	javac *.java

clean:
	rm -f *.o *.class *.so
