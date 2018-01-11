# Makefile autoconfigured for ...
# Mac OS X system on Wed Jan 10 17:17:55 MST 2018



MFLAGS=
LFLAGS=
CC=cc
LD=ld
SHELL=/bin/sh
INSTALLER=cp
CFLAGS= -DBYTESWAPPED -O -DNeXT -DADDRINPACK -DUSEDIRENT -I/Users/cwbetts/makestuff/CAP/tmpBuild 
LWFLAGS=
I=/Users/cwbetts/makestuff/CAP/tmpBuild
CAPLIB=/Users/cwbetts/makestuff/CAP/tmpBuild/lib/libcap.a
DESTDIR=/Users/cwbetts/makestuff/CAP/tmpBuild/bin

# for other libraries (like BSD on hpux)
SLIB=

# See README file for notes about defines
# Valid: SFLOWQ=[1,2,3,4,5,6,7,8]
# Valid: IDLESTUFF, NO_STRUCT, NOACCT, CAPPRINTERS=location
PAPFLAGS=-DMACUSER -DIDLESTUFF -DCAPPRINTERS=\"/Users/cwbetts/makestuff/CAP/tmpBuild/etc/cap.printers\"
PAPBANNER=-DCHARGEBANNER

# USEVPRINTF - use vprintf in logging
#VPRINTF=-DUSEVPRINTF
# If you have Transcript from Adobe for your laserWriter and want to
#  print text files, uncomment the next line and set the location properly
# WPSTEXT=-DPSTEXT=\"/usr/local/lib/ps/pstext\"

# This is if you have transcript and and want page reversal if possible
# WPSREVERSE=-DPSREVERSE=\"/usr/local/lib/ps/psrv\"

all:	papif papof

papif:	papif.o $(O)
	${CC} ${LFLAGS} -o papif papif.o $(O) $(CAPLIB) ${SLIB}

papif.o: papif.c
	${CC} ${CFLAGS} ${VPRINTF} ${PAPBANNER} ${PAPFLAGS} ${LWFLAGS} \
		${WPSTEXT} ${WPSREVERSE} -c papif.c




papof.o: papof.c
	${CC} -c ${CFLAGS} ${PAPBANNER} papof.c

papof:	papof.o
	${CC} ${LFLAGS} -o papof papof.o ${SLIB}


clean:
	-rm -f papif papof *.o

spotless:
	-rm -f papif papof *.o *.orig Makefile makefile


install: papif papof
	-strip papif papof
	${INSTALLER} papif papof $(DESTDIR)


dist:
	@cat todist
