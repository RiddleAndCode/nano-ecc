CFLAGS = -g -Wall -Werror

all: speedtest verify_ecdh verify_ecdsa

ecc.o: ../inc/ecc.c ../inc/ecc.h
	$(CC) $(CFLAGS) -c -o ecc.o ../inc/ecc.c

%.o: %.c ../inc/ecc.h
	$(CC) -c $(CFLAGS) $< -o $@

speedtest: speedtest.o ecc.o
	$(CC) -o speedtest speedtest.o ecc.o

verify_ecdh: verify_ecdh.o testlib.o ecc.o
	$(CC) -o verify_ecdh verify_ecdh.o testlib.o ecc.o

verify_ecdsa: verify_ecdsa.o testlib.o ecc.o
	$(CC) -o verify_ecdsa verify_ecdsa.o testlib.o ecc.o

clean:
	rm -f *.o speedtest verify_ecdh verify_ecdsa
