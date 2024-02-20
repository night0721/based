CC=gcc

VERSION = 1.0
PREFIX = /usr/local
MANPREFIX = ${PREFIX}/share/man

CFLAGS = -std=gnu11 -O0 -Wall

SRC = based.c
OBJ = ${SRC:.c=.o}

.c.o:
	${CC} -c ${CFLAGS} $<

based: ${OBJ}
	${CC} -o $@ ${OBJ}
	strip based

clean:
	rm -rf based

dist: based
	mkdir -p based-${VERSION}
	cp -R LICENSE Makefile README.md based.1 based based-${VERSION}
	tar -cf based-${VERSION}.tar based-${VERSION}
	gzip based-${VERSION}.tar
	rm -rf based-${VERSION}

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f based ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/based
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	sed "s/VERSION/${VERSION}/g" < based.1 > ${DESTDIR}${MANPREFIX}/man1/based.1
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/based.1

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/based\
		${DESTDIR}${MANPREFIX}/man1/based.1
all: based

.PHONY: all clean dist install uninstall based
