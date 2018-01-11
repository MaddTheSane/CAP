# Makefile autoconfigured for ...
# Mac OS X system on Wed Jan 10 17:17:55 MST 2018



MFLAGS=
LFLAGS=
CC=cc
LD=ld
SHELL=/bin/sh
INSTALLER=cp
CFLAGS= -DBYTESWAPPED -O -DNeXT -DADDRINPACK -DUSEDIRENT -I/Users/cwbetts/makestuff/CAP/tmpBuild  
DESTDIR=/Users/cwbetts/makestuff/CAP/tmpBuild/lib
LIBAFPC=libafpc.a
I=/Users/cwbetts/makestuff/CAP/tmpBuild

LIBAFPCSRCS=afpc.c afpcc.c
LIBAFPCOBJS=afpc.o afpcc.o

$(LIBAFPC):	$(LIBAFPCOBJS)
	ar rv  $(LIBAFPC) $(LIBAFPCOBJS)

clean:
	-rm -f ${LIBAFPCOBJS} ${LIBAFPC} core *~

spotless:
	-rm -f ${LIBAFPCOBJS} ${LIBAFPC} core *~ *.orig Makefile makefile

install:	$(LIBAFPC)
	${INSTALLER} $(LIBAFPC) $(DESTDIR)
	ranlib $(DESTDIR)/$(LIBAFPC)

dist:
	@cat todist

lint:	$(LIBAFPCSRCS)
	lint $(LIBAFPCSRCS)

afpc.o:         afpc.c		$I/netat/appletalk.h $I/netat/aberrors.h \
				$I/netat/abqueue.h $I/netat/afpc.h 
afpcc.o:        afpcc.c		$I/netat/appletalk.h $I/netat/aberrors.h \
				$I/netat/abqueue.h $I/netat/afpc.h 
