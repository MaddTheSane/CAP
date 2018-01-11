# Makefile autoconfigured for ...
# Mac OS X system on Wed Jan 10 17:17:55 MST 2018



MFLAGS=
LFLAGS=
CC=cc
LD=ld
SHELL=/bin/sh
INSTALLER=cp


all:
	(cd cap; make)
	(cd afp; make)
	(cd afpc; make)
	

install: normal

normal:
	(cd cap; make install)
	(cd afp; make install)
	(cd afpc; make install)

xenix5:
	(cd xenix; make install)

clean:
	-(cd cap; make clean)
	-(cd afp; make clean)
	-(cd afpc; make clean)
	

spotless:
	-rm -f *.orig Makefile makefile
	-(cd cap; make spotless)
	-(cd afp; make spotless)
	-(cd afpc; make spotless)
	

dist:
	@cat todist
	@(cd cap; make dist)
	@(cd afp; make dist)
	@(cd afpc; make dist)

