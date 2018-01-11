# Makefile autoconfigured for ...
# Mac OS X system on Wed Jan 10 17:17:55 MST 2018



MFLAGS=
LFLAGS=
CC=cc
LD=ld
SHELL=/bin/sh
INSTALLER=cp
CFLAGS= -DBYTESWAPPED -O -DNeXT -DADDRINPACK -DUSEDIRENT -I/Users/cwbetts/makestuff/CAP/tmpBuild  
NBPFLAGS=
I=/Users/cwbetts/makestuff/CAP/tmpBuild
LIBCAP=libcap.a
DESTDIR=/Users/cwbetts/makestuff/CAP/tmpBuild/lib
AUTHCONFIG=\"/etc/cap.auth\"

LIBABSRCS=abatp.c abddp.c abmisc.c abnbp.c abauxddp.c abauxnbp.c \
	abpap.c abpapc.c abpaps.c abpp.c abqueue.c abasp.c \
	abzip.c abversion.c atalkdbm.c absched.c abkip.c \
	authenticate.c ablog.c scandir.c
LIBABOBJS=abatp.o abmisc.o abzip.o abversion.o absched.o \
	abpap.o abpapc.o abpaps.o abpp.o abqueue.o abasp.o \
	authenticate.o ablog.o scandir.o

# LABOBJ defines the various low level delivery mechanisms
#   default: abkip.o abddp.o abnbp.o atalkdbm.o
#   with UAB: abmkip.o abddp.o abnbp.o atalkdbm.o
#   for A/UX: abauxddp.o abauxnbp.o
#   for EtherTalk: abetalk.o abddp.o abnbp.o atalkdbm.o
LAPOBJ=abkip.o abddp.o abnbp.o atalkdbm.o

# USEVPRINTF - use vprintf in logging
LOGDEFS=

DEPENDS=$I/netat/appletalk.h $I/netat/aberrors.h $I/netat/abqueue.h

all: $(LIBCAP)

$(LIBCAP):	$(LIBABOBJS) $(LAPOBJ)
	ar rv $(LIBCAP) $(LIBABOBJS) $(LAPOBJ)

clean:
	-rm -f *.o *.a core

spotless:
	-rm -f *.o *.a *.orig core Makefile makefile

install:	$(LIBCAP)
	${INSTALLER} $(LIBCAP) $(DESTDIR)
	(cd $(DESTDIR);ranlib $(LIBCAP))

dist:
	@cat todist

lint:	$(LIBABSRCS)
	lint $(LIBABSRCS)

abetalk.o:
	(cd ../../support/ethertalk; make abetalk.o)
	mv ../../support/ethertalk/abetalk.o abetalk.o

abmkip.o:       abkip.c		${DEPENDS} $I/netat/abnbp.h $I/netat/compat.h
	cp abkip.c abmkip.c
	${CC} ${CFLAGS} -DUAB_MKIP -c abmkip.c
	/bin/rm abmkip.c

atalkdbm.o:     atalkdbm.c	${DEPENDS}
	${CC} ${CFLAGS} -DTAB=\"/Users/cwbetts/makestuff/CAP/tmpBuild/etc/atalk.local\" -DETAB=\"/Users/cwbetts/makestuff/CAP/tmpBuild/etc/etalk.local\" \
		-DCONFIGDIR=\"/Users/cwbetts/makestuff/CAP/tmpBuild/etc\" -c atalkdbm.c

authenticate.o:	authenticate.c	${DEPENDS}
	${CC} ${CFLAGS} -DAUTHCONFIG=${AUTHCONFIG} -c authenticate.c

ablog.o:	ablog.c		${DEPENDS}
	${CC} ${CFLAGS} ${LOGDEFS} -c ablog.c

abnbp.o:        abnbp.c		${DEPENDS} $I/netat/abnbp.h
	${CC} ${CFLAGS} ${NBPFLAGS} -c abnbp.c

abkip.o:        abkip.c		${DEPENDS} $I/netat/abnbp.h $I/netat/compat.h
abddp.o:        abddp.c		${DEPENDS} cap_conf.h 
abatp.o:        abatp.c		${DEPENDS} abatp.h 
abatpaux.o:     abatpaux.c	${DEPENDS} abatp.h
abasp.o:        abasp.c		${DEPENDS} abasp.h 
abpap.o:        abpap.c		${DEPENDS} abpap.h cap_conf.h
abpapc.o:       abpapc.c	${DEPENDS} abpap.h cap_conf.h 
abpaps.o:       abpaps.c	${DEPENDS} abpap.h cap_conf.h 
abzip.o:	abzip.c		${DEPENDS}
abmisc.o:       abmisc.c	${DEPENDS}
abpp.o:         abpp.c		${DEPENDS}
abversion.o:	abversion.c	${DEPENDS}
abauxddp.o:	abauxddp.c	${DEPENDS} cap_conf.h
abauxnbp.o:	abauxnbp.c	${DEPENDS} $I/netat/abnbp.h
absched.o:	absched.c	${DEPENDS} $I/netat/compat.h
atalkdbm.o:     atalkdbm.c	${DEPENDS} $I/netat/compat.h atalkdbm.h
abqueue.o:      abqueue.c       $I/netat/abqueue.h 
