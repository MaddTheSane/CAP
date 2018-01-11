# Makefile autoconfigured for ...
# Mac OS X system on Wed Jan 10 17:38:55 MST 2018



MFLAGS=
LFLAGS=
CC=cc
LD=ld
SHELL=/bin/sh
INSTALLER=cp
CFLAGS= -DBYTESWAPPED -O -DNeXT -DADDRINPACK -DUSEDIRENT -I/Users/cwbetts/makestuff/CAP/tmpBuild  
DESTDIR=/Users/cwbetts/makestuff/CAP/tmpBuild/lib
OSDEFS= -DNOFLOCK -DNOLOCKF
LIBAFP=libafp.a
I=/Users/cwbetts/makestuff/CAP/tmpBuild
DES=../../extras

LIBAFPSRCS=afperr.c afpcmd.c afppacks.c afposlock.c afppass.c \
	afpidaufs.c afpidclnt.c afpidgnrl.c
LIBAFPOBJS=afperr.o afpcmd.o afppacks.o afposlock.o des.o afppass.o \
	afpidaufs.o afpidclnt.o afpidgnrl.o

$(LIBAFP):	$(LIBAFPOBJS)
	ar rv  $(LIBAFP) $(LIBAFPOBJS)

des.o: ${DES}/des.c
	(cd ${DES}; make des.o)
	cp ${DES}/des.o .

clean:
	-rm -f ${LIBAFPOBJS} ${LIBAFP} core *~

spotless:
	-rm -f ${LIBAFPOBJS} ${LIBAFP} core *~ *.orig Makefile makefile

install:	$(LIBAFP)
	${INSTALLER} $(LIBAFP) $(DESTDIR)
	ranlib $(DESTDIR)/$(LIBAFP)

dist:
	@cat todist

lint:	$(LIBAFPSRCS)
	lint $(LIBAFPSRCS)

afposlock.o:	afposlock.c
	${CC} ${OSDEFS} ${CFLAGS} -c afposlock.c

# Dependencies
afpcmd.o:       afpcmd.c	$I/netat/appletalk.h $I/netat/aberrors.h \
				$I/netat/abqueue.h $I/netat/sysvcompat.h \
				$I/netat/afp.h $I/netat/afpcmd.h 
afperr.o:       afperr.c        $I/netat/appletalk.h \
				$I/netat/aberrors.h $I/netat/abqueue.h \
				$I/netat/sysvcompat.h $I/netat/afp.h 
afppacks.o:     afppacks.c      $I/netat/appletalk.h \
				$I/netat/aberrors.h $I/netat/abqueue.h \
				$I/netat/sysvcompat.h $I/netat/afp.h \
				$I/netat/afpcmd.h 
afposlock.o:    afposlock.c	$I/netat/appletalk.h $I/netat/aberrors.h \
				$I/netat/abqueue.h $I/netat/sysvcompat.h \
				$I/netat/afp.h $I/netat/afpcmd.h

afpidaufs.o:	afpidaufs.c afpidaufs.h afpidnames.h
afpidclnt.o:	afpidclnt.c afpidaufs.h afpidnames.h
afpidgnrl.o:	afpidgnrl.c afpidaufs.h afpidnames.h
afppass.o:	afppass.c	$I/netat/afppass.h
