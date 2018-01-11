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
PROGS=
POBJS=
ETCDIR=/Users/cwbetts/makestuff/CAP/tmpBuild/etc
CAPLIB=/Users/cwbetts/makestuff/CAP/tmpBuild/lib/libcap.a
SLIB=

LIBABSRCS=abelap.c ethertalk.c ../uab/aarp.c ../uab/hash.c
LIBABOBJS=abelap.o ethertalk.o aarp.o hash.o

#
# abetalk.o provides EtherTalk support for CAP
#
all: ${PROGS}

abetalk.o: ${LIBABOBJS} ${POBJS} aarpd_clnt.o aarpd_xdr.o aarpd.h
	ld -r -o abetalk.o ${LIBABOBJS} ${POBJS} aarpd_clnt.o aarpd_xdr.o

aarpd:	aarpd.o aarpd_svc.o aarpd.h
	${CC} ${LFLAGS} -o aarpd aarpd.o aarpd_svc.o ${CAPLIB} ${SLIB}

aarptest: aarptest.o aarpd.h
	${CC} ${LFLAGS} -o aarptest aarptest.o ${CAPLIB} ${SLIB}

rtmptest: rtmptest.o aarpd.h
	${CC} ${LFLAGS} -o rtmptest rtmptest.o ${CAPLIB} ${SLIB}

rangetest: rangetest.o aarpd.h
	${CC} ${LFLAGS} -o rangetest rangetest.o ${CAPLIB} ${SLIB}

aarpd.o: aarpd.c aarpd.h

abelap.o: abelap.c

ethertalk.o: ethertalk.c ../uab/ethertalk.h

snitp.o: snitp.c ../uab/proto_intf.h

sdlpi.o.o: sdlpi.o.c ../uab/proto_intf.h

# explict command because on pyramid we don't want -q for this
senetp.o: senetp.c ../uab/proto_intf.h


aarpd_clnt.o: aarpd_clnt.c aarpd.h

aarpd_svc.o: aarpd_svc.c aarpd.h

aarpd_xdr.o: aarpd_xdr.c aarpd.h

aarp.o: ../uab/aarp.c ../uab/hash.h ../uab/proto_intf.h \
    ../uab/ethertalk.h ../uab/aarp_defs.h ../uab/aarp.h
	${CC} $(CFLAGS) -DAARPD -c ../uab/aarp.c

hash.o: ../uab/hash.c ../uab/hash.h
	${CC} $(CFLAGS) -c ../uab/hash.c

aarptest.o: aarptest.c aarpd.h

rtmptest.o: rtmptest.c aarpd.h

install: ${PROGS}.install

.install:

aarpd.install: aarpd
	-strip aarpd
	${INSTALLER} aarpd ${DESTDIR}

clean:
	rm -f *.o core aarpd aarptest rtmptest

spotless:
	rm -f *.o *.orig core aarpd aarptest rtmptest Makefile makefile
