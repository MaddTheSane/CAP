# Makefile autoconfigured for ...
# Mac OS X system on Wed Jan 10 17:38:55 MST 2018



MFLAGS=
LFLAGS=
CC=cc
LD=ld
SHELL=/bin/sh
INSTALLER=cp
CFLAGS= -DBYTESWAPPED -O -DNeXT -DADDRINPACK -DUSEDIRENT -I/Users/cwbetts/makestuff/CAP/tmpBuild 
I=/Users/cwbetts/makestuff/CAP/tmpBuild
O=

# Valid: SFLOWQ=[1,2,3,4,5,6,7,8]
LWFLAGS=

# location of cap.printers file
CAPPRINTERS=-DCAPPRINTERS=\"/Users/cwbetts/makestuff/CAP/tmpBuild/etc/cap.printers\"

# Make sure to define needgetopt if your system doesnt have it
GETOPT=att_getopt.o

ATISPROGS=atistest
PROGS=lwpr tlw atlook atlooklws atpinger iwpr isrv ash \
	instappl getzones papstatus ${ATISPROGS}

DESTDIR=/Users/cwbetts/makestuff/CAP/tmpBuild/bin
CAPLIB=/Users/cwbetts/makestuff/CAP/tmpBuild/lib/libcap.a
AFPLIB=/Users/cwbetts/makestuff/CAP/tmpBuild/lib/libafpc.a /Users/cwbetts/makestuff/CAP/tmpBuild/lib/libafp.a

# for other libraries (like BSD on hpux)
SLIB=

all:	${PROGS}

atistest:	atistest.o ${O}
	${CC} ${LFLAGS} -o atistest atistest.o ${O} ${CAPLIB} ${SLIB}

getzones:	getzones.o ${O}
	${CC} ${LFLAGS} -o getzones getzones.o ${O} ${CAPLIB} ${SLIB}

papstatus:	papstatus.o ${O}
	${CC} ${LFLAGS} -o papstatus papstatus.o ${O} ${CAPLIB} ${SLIB}

papstatus.o:	papstatus.c
	${CC} ${CFLAGS} ${LWFLAGS} ${CAPPRINTERS} -c papstatus.c

ash.o:	ash.c
	${CC} ${CFLAGS}  -c ash.c

ash:	ash.o ${CAPFILES}
	${CC} ${LFLAGS} -o ash ash.o ${CAPFILES} ${AFPLIB} ${CAPLIB} ${SLIB}

instappl: instappl.o $(GETOPT)
	${CC} ${LFLAGS} -o instappl instappl.o $(GETOPT) ${SLIB}

# iwpr and lwpr share sources...
iwpr:	iwpr.o $(O) ${GETOPT}
	${CC} ${LFLAGS} -o iwpr iwpr.o ${GETOPT} $(O) $(CAPLIB) ${SLIB}

lwpr:	lwpr.o $(O) ${GETOPT}
	${CC} ${LFLAGS} -o lwpr lwpr.o ${GETOPT} $(O) $(CAPLIB) ${SLIB}

lwpr.o: lwpr.c
	${CC} ${CFLAGS} ${LWFLAGS} ${CAPPRINTERS} -c lwpr.c

iwpr.o:	lwpr.c
	cp lwpr.c iwpr.c
	${CC} ${CFLAGS} ${LWFLAGS} -c -DIMAGEWRITER iwpr.c
	rm iwpr.c

isrv:	isrv.o $(O)
	${CC} $(LFLAGS) -o isrv isrv.o $(O) $(CAPLIB) ${SLIB}

isrv.o:	isrv.c
	${CC} ${CFLAGS} -c isrv.c

tlw:	tlw.o $(O) ${GETOPT}
	${CC} ${LFLAGS} -o tlw tlw.o $(O) ${GETOPT} $(CAPLIB) ${SLIB}

tlw.o:	tlw.c
	${CC} ${CFLAGS} ${LWFLAGS} ${CAPPRINTERS} -c tlw.c

#
# atlook, atlooklw, and atpinger all have a common source
#
atlook:	atlook.o ${GETOPT} $(O)
	${CC} ${LFLAGS} -o atlook atlook.o $(O) ${GETOPT} $(CAPLIB) ${SLIB}

# copy because some machines won't do it right o.w.
atlooklws.o: atlook.c
	cp atlook.c atlooklws.c
	${CC} ${CFLAGS} -c -DATLOOKLWS atlooklws.c
	rm atlooklws.c
	
atlooklws:	atlooklws.o ${GETOPT} ${O}
	${CC} ${LFLAGS} -o atlooklws atlooklws.o ${GETOPT} $(O) $(CAPLIB) ${SLIB}

atpinger.o: atlook.c
	cp atlook.c atpinger.c
	${CC} ${CFLAGS} -c -DATPINGER atpinger.c
	rm atpinger.c

atpinger:	atpinger.o $(O) ${GETOPT}
	${CC} ${LFLAGS} -o atpinger atpinger.o ${GETOPT} $(O) $(CAPLIB) ${SLIB}

att_getopt.c:
	ln -s ../extras/att_getopt.c

install: ${PROGS}
	-strip ${PROGS}
	${INSTALLER} ${PROGS} ${DESTDIR}

clean:
	-rm -f ${PROGS} *.o core make.log err *~ att_getopt.c

spotless:
	-rm -f ${PROGS} *.o *.orig core make.log err *~ att_getopt.c
	-rm -f Makefile makefile

cleanexe:
	-rm -f ${PROGS}

dist:
	@cat todist
