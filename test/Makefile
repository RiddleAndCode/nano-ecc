CFLAGS = -g -Wall -Werror

all: speedtest verify_ecdh verify_ecdsa

%.o: %.c ../inc/ecc.h
	$(CC) -c $(CFLAGS) $< -o $@

speedtest: speedtest.o
	mkdir -p ../bin
	$(CC) -o ../bin/speedtest speedtest.o -L../lib -lnano_ecc

verify_ecdh: verify_ecdh.o testlib.o
	mkdir -p ../bin
	$(CC) -o ../bin/verify_ecdh verify_ecdh.o testlib.o -L../lib -lnano_ecc

verify_ecdsa: verify_ecdsa.o testlib.o 
	mkdir -p ../bin
	$(CC) -o ../bin/verify_ecdsa verify_ecdsa.o testlib.o -L../lib -lnano_ecc

clean:
	rm -f *.o ../bin/speedtest ../bin/verify_ecdh ../bin/verify_ecdsa
