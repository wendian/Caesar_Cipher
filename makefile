CC = gcc
CFLAGS = -D_REENTRANT
LDFLAGS = -lpthread

cth: cth.c
	${CC} -o cth cth.c ${LDFLAGS}

caesar: caesar.c
	${CC} -o caesar caesar.c

clean:
	rm cth caesar

