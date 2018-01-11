# Makefile autoconfigured for ...
# Mac OS X system on Wed Jan 10 17:17:55 MST 2018



MFLAGS=
LFLAGS=
CC=cc
LD=ld
SHELL=/bin/sh
INSTALLER=cp
I=/Users/cwbetts/makestuff/CAP/tmpBuild
HFILES = aberrors.h abqueue.h appletalk.h afp.h afpcmd.h afpc.h \
	 compat.h sysvcompat.h macfile.h abnbp.h fcntldomv.h afppass.h

install: $(HFILES)
	-mkdir $I/netat
	cp $(HFILES) $I/netat

dist:
	@cat todist

clean:

spotless:
	-rm -f *.orig Makefile makefile
