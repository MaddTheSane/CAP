# Makefile autoconfigured for ...
# Mac OS X system on Wed Jan 10 17:17:55 MST 2018



MFLAGS=
LFLAGS=
CC=cc
LD=ld
SHELL=/bin/sh
INSTALLER=cp
CFLAGS= -DBYTESWAPPED -O -DNeXT -DADDRINPACK -DUSEDIRENT -I/Users/cwbetts/makestuff/CAP/tmpBuild 
DESTDIR=/Users/cwbetts/makestuff/CAP/tmpBuild/bin
CAPLIB=/Users/cwbetts/makestuff/CAP/tmpBuild/lib/libcap.a
I=/Users/cwbetts/makestuff/CAP/tmpBuild
LFLAGS=
O=

PROGS=iwif

all:	${PROGS}

iwif:	iwif.o $(O)
	${CC} ${LFLAGS} -o iwif iwif.o

des.o:	des.c
	${CC} ${CFLAGS} -c des.c

install: ${PROGS}
	-strip ${PROGS}
	${INSTALLER} ${PROGS} ${DESTDIR}

clean:
	-rm -f ${PROGS} *.o core make.log err *~

spotless:
	-rm -f ${PROGS} *.o *.orig core make.log err *~ Makefile makefile

cleanexe:
	-rm -f ${PROGS}

dist:
	@cat todist
