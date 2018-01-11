# Makefile autoconfigured for ...
# Mac OS X system on Wed Jan 10 17:17:55 MST 2018



MFLAGS=
LFLAGS=
CC=cc
LD=ld
SHELL=/bin/sh
INSTALLER=cp
CFLAGS= -DBYTESWAPPED -O -DNeXT -DADDRINPACK -DUSEDIRENT -I/Users/cwbetts/makestuff/CAP/tmpBuild  
SDESTDIR=/Users/cwbetts/makestuff/CAP/tmpBuild/bin
UDESTDIR=/Users/cwbetts/makestuff/CAP/tmpBuild/bin
ETCDIR=/Users/cwbetts/makestuff/CAP/tmpBuild/etc
CAPLIB=/Users/cwbetts/makestuff/CAP/tmpBuild/lib/libcap.a
I=/Users/cwbetts/makestuff/CAP/tmpBuild
# for other libraries (like BSD on hpux)
SLIB=

ATISPROGS=atis
PROGS=${ATISPROGS} 

# aufs.c definitions: USEVPRINTF - use vprintf in logging
#ATISDEFS=-DUSEVPRINTF

# Make sure to define needgetopt if your system doesnt have it or
# just set GETOPT=att_getopt.o (or to a getopt of your own liking)
GETOPT=att_getopt.o

all:	${PROGS}

atis:	atis.o nisaux.o ${GETOPT}
	${CC} ${LFLAGS} -o atis atis.o nisaux.o ${GETOPT} ${CAPLIB} ${SLIB}

atis.o:	$I/netat/abnbp.h
	${CC} ${CFLAGS} ${ATISDEFS} -DETCDIR=\"${ETCDIR}\" -c atis.c

nisaux.o: $I/netat/abnbp.h

att_getopt.c:
	ln -s ../extras/att_getopt.c

install: ${PROGS}
	-strip ${PROGS}
	-mkdir ${SDESTDIR} ${UDESTDIR}
	${INSTALLER} ${PROGS} ${SDESTDIR}

clean:
	-rm -f atis *.o core att_getopt.c *~

spotless:
	-rm -f atis *.o *.orig core att_getopt.c *~ Makefile makefile

dist:
	@cat todist

