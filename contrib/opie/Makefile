##
# Makefile.source and Makefile: Directions for building and installing OPIE.
#
# %%% portions-copyright-cmetz-96
# Portions of this software are Copyright 1996-1999 by Craig Metz, All Rights
# Reserved. The Inner Net License Version 2 applies to these portions of
# the software.
# You should have received a copy of the license with this software. If
# you didn't get a copy, you may request one from <license@inner.net>.
#
# Portions of this software are Copyright 1995 by Randall Atkinson and Dan
# McDonald, All Rights Reserved. All Rights under this copyright are assigned
# to the U.S. Naval Research Laboratory (NRL). The NRL Copyright Notice and   
# License Agreement applies to this software.   
#
#	History:
#
#	Modified by cmetz for OPIE 2.4. Add libmissing to include header path.
#		Renamed realclean to distclean. Added opieauto rules. Made
#		system program install more tolerant of non-existent files.
#	Modified by cmetz for OPIE 2.31. Moved logwtmp.o into libopie.
#	Modified by cmetz for OPIE 2.3. Removed manual config -- it's
#		Autoconf or bust. Replaced user configuration options
#		with options.h. Eliminated unused variables. Pass down
#		$(DEBUG) instead of several other variables to the
#		subdirs. Extended/standard key file support. Added
#		dependencies on subdir files. Made opietest call silent.
#		Removed opie-md4, opie-md5, and key aliases. Removed
#		test target. Make uninstall remove man page aliases.
#	Modified by cmetz for OPIE 2.22. Removed  ${LIBOBJDIR}lstat$U.o from MISSING for
#		Autoconf target. Re-ordered LFLAGS because some ld's won't
#		include libmissing properly if it's not at the end.
#       Modified by cmetz for OPIE 2.21. Added getusershell.o to IRIX
#               missing functions.
#       Modified by cmetz for OPIE 2.2. Added NEW_PROMPTS definition.
#               Added MISSING and new flags-passing for libmissing.
#               Quote MISSING or lose. Update TEST target for FTPD
#               variable. Removed line formatting for compile commands
#               since macro expansion confuses the issue anyway.
#               Added targets for opieserv. Added targets for opietest.
#               Removed obselete options.h target. Swapped libmissing
#               and libopie. Updated manual config options. Added more
#               explanatory text. Fixed uses of old SYSV and BSD4_3
#               symbols.
#       Modified at NRL for OPIE 2.2: Renamed LDFLAGS setting to LIBS,
#               renamed LDFLAGS in targets to LFLAGS. Added targets for
#               libopie and libmissing directories. Got rid of PROTOTYPES.
#               Added opiegen. Fixed RANLIB Autoconf target. 
#       Modified at NRL for OPIE 2.11: Fixed fatal mistype of Autoconf.
#	Modified at NRL for OPIE 2.1: Changed targets to reflect source
#		file name changes. Changed explanation and flags for static
#		linking. Changed opieinfo target. Removed WHOAMI. Added
#		Autoconf targets. Changed if conditionals to use test
#               instead of [. Changed SU_DIR to SU to help autoconf.
#               Changed FTPDIR and FTPDNAME to FTPD to help autoconf.
#               Changed HP-UX to HP-UX9 and HP-UX10. Make uninstall
#               target depend on config. HPUX *is* no longer necessary, but
#               something does have to be there. Sub in Autoconf gcc.
#       Modified at NRL for OPIE 2.04: Re-worded explanation of SU_STAR_CHECK.
#       Modified at NRL for OPIE 2.02: Added SU_STAR_CHECK flag.
#       Modified at NRL for OPIE 2.01: Test target makes opiesu and opielogin 
#               setuid. install target clears that. uninstall target needs to
#               remove the opiekey symlinks. opieinfo target needs to 
#               substitute for $(EXISTS). ifdefs target needs to check for 
#               starting hash. $(LFLAGS) and -o should be at the end of all 
#               link commands to spoon-feed drain bamaged link editors. Added
#               A/UX defaults.
#	Modified heavily at NRL for OPIE 2.0.
#	Written at Bellcore for the S/Key Version 1 software distribution
#		(Makefile).

#============================================================================
# CONFIGURATION PARAMETERS -- CHANGE THESE TO SUIT YOUR MACHINE

# Shell to use for make(1)
# It's usually a good idea to leave this as-is. On some systems, ksh or bash
# may be necessary
SHELL=/bin/sh

# OWNER is the username who should own the OPIE binaries.
# GROUP is the groupname associated with the OPIE binaries.
#
OWNER=0
GROUP=bin

# Where should the OPIE standard and extended databases be stored?
#
# Some sites might want to put this elsewhere. If you want to use an old
# S/Key database, you should create a link from /etc/skeykeys to /etc/opiekeys.
KEY_FILE=/etc/opiekeys

# Are we debugging?
#
# The first line will build a normal version of OPIE. You should use it.
#
# The second is for brave souls porting OPIE to a new system or trying to
# debug it and should definitely NOT be used to build a production copy
# of OPIE. 
#
# The third is the above using nifty heap debugger called "Electric Fence".
DEBUG=-O
#DEBUG=-DDEBUG=1 -g
#DEBUG=-DDEBUG=1 -g -lefence

# These parameters are determined by Autoconf and are probably correct.
# If OPIE doesn't build or work right, try tweaking these.
CC=gcc
YACC=bison -y
FTPD=
LIBS=
OPTIONS=-DHAVE_CONFIG_H
EXISTS=-e
MKDIR=mkdir -p
CHOWN=/usr/sbin/chown
LOCALBIN=/usr/local/bin
LOCALMAN=/usr/local/share/man
SU=/usr/bin/su
ALT_SU=
LOGIN=/usr/bin/login
LOCK_DIR=/etc/opielocks
OPIEAUTO=

BACKUP=opie.old

CFLAGS=$(DEBUG) -Ilibmissing

LFLAGS=-Llibopie -Llibmissing -lopie $(LIBS) -lmissing -lopie
LDEPS=libmissing/libmissing.a libopie/libopie.a

all:	client server

ifdefs:	
	egrep '^#*if*def' *.c *.h | cut -f2 -d: | sort | uniq

client: libopie/libopie.a libmissing/libmissing.a opietest-passed opiekey opiegen $(OPIEAUTO)

client-install: client
	@echo "Installing OPIE client software..."
	@echo "Copying OPIE key-related files"
	@if test ! -d $(LOCALBIN); then $(MKDIR) $(LOCALBIN); chmod 755 $(LOCALBIN); fi 
	@cp opiekey $(OPIEAUTO) $(LOCALBIN)
	@$(CHOWN) $(OWNER) $(LOCALBIN)/opiekey
	@if test ! -z "$(OPIEAUTO)"; then $(CHOWN) $(OWNER) $(LOCALBIN)/opieauto; fi
	@chgrp $(GROUP) $(LOCALBIN)/opiekey
	@echo "Changing file permissions"
	@chmod 0511 $(LOCALBIN)/opiekey
	@if test ! -z "$(OPIEAUTO)"; then chmod 0511 $(LOCALBIN)/opieauto; fi
	@echo "Symlinking aliases to opiekey"
	@-ln -s $(LOCALBIN)/opiekey $(LOCALBIN)/otp-md4
	@-ln -s $(LOCALBIN)/opiekey $(LOCALBIN)/otp-md5
	@echo "Installing manual pages"
	@-for i in otp-md4 otp-md5; do ln -s opiekey.1 $(LOCALMAN)/man1/$$i.1; done
	@if test ! -d $(LOCALMAN)/man1; then $(MKDIR) $(LOCALMAN)/man1; chmod 755 $(LOCALMAN)/man1; fi; cp opiekey.1 $(LOCALMAN)/man1/opiekey.1; $(CHOWN) $(OWNER) $(LOCALMAN)/man1/opiekey.1; chgrp $(GROUP) $(LOCALMAN)/man1/opiekey.1; chmod 644 $(LOCALMAN)/man1/opiekey.1

server:	libopie/libopie.a libmissing/libmissing.a opietest-passed opielogin opiesu opiepasswd opieinfo opieftpd opieserv

server-install: server
	@echo "Installing OPIE server software..."
	@echo "Copying OPIE user programs"
	@if test ! -d $(LOCALBIN); then $(MKDIR) $(LOCALBIN); chmod 755 $(LOCALBIN); fi 
	@cp opiepasswd opieinfo $(LOCALBIN)
	@echo "Changing ownership"
	@$(CHOWN) $(OWNER) $(LOCALBIN)/opiepasswd $(LOCALBIN)/opieinfo
	@chgrp $(GROUP) $(LOCALBIN)/opiepasswd $(LOCALBIN)/opieinfo
	@echo "Changing file permissions"
	@chmod 0555 $(LOCALBIN)/opieinfo
	@chmod 4511 $(LOCALBIN)/opiepasswd
	@echo "Installing OPIE system programs..."
	@if test ! -z $(LOGIN); \
	then \
		if test ! $(EXISTS) $(LOGIN).$(BACKUP); \
		then \
			echo "Renaming existing $(LOGIN) to $(LOGIN).$(BACKUP)"; \
			mv $(LOGIN) $(LOGIN).$(BACKUP); \
			echo "Clearing permissions on $(LOGIN)"; \
			chmod 0 $(LOGIN).$(BACKUP); \
		fi; \
		echo "Copying OPIE login to $(LOGIN)"; \
		cp opielogin $(LOGIN); \
		echo "Changing ownership of $(LOGIN)"; \
		$(CHOWN) $(OWNER) $(LOGIN); \
		chgrp $(GROUP) $(LOGIN); \
		echo "Changing file permissions of $(LOGIN)"; \
		chmod 4111 $(LOGIN); \
	fi
	@if test ! -z $(SU); \
	then \
		if test ! $(EXISTS) $(SU).$(BACKUP); \
		then \
			echo "Renaming existing $(SU) to $(SU).$(BACKUP)"; \
			mv $(SU) $(SU).$(BACKUP); \
			echo "Clearing permissions on $(SU)"; \
			chmod 0 $(SU).$(BACKUP); \
		fi; \
		echo "Copying OPIE su to $(SU)"; \
		cp opiesu $(SU); \
		echo "Changing ownership of $(SU)"; \
		$(CHOWN) $(OWNER) $(SU); \
		chgrp $(GROUP) $(SU); \
		echo "Changing file permissions of $(SU)"; \
		chmod 4111 $(SU); \
	fi
	@if test ! -z $(ALT_SU); \
	then \
		if test ! $(EXISTS) $(ALT_SU).$(BACKUP); \
		then \
			echo "Renaming existing $(ALT_SU) to $(ALT_SU).$(BACKUP)"; \
			mv $(ALT_SU) $(ALT_SU).$(BACKUP); \
			echo "Clearing permissions on $(ALT_SU)"; \
			chmod 0 $(ALT_SU).$(BACKUP); \
		fi; \
		echo "Copying OPIE su to $(ALT_SU)"; \
		cp opiesu $(ALT_SU); \
		echo "Changing ownership of $(ALT_SU)"; \
		$(CHOWN) $(OWNER) $(ALT_SU); \
		chgrp $(GROUP) $(ALT_SU); \
		echo "Changing file permissions of $(ALT_SU)"; \
		chmod 4111 $(ALT_SU); \
	fi
	@if test ! -z $(FTPD); \
	then \
		if test ! $(EXISTS) $(FTPD).$(BACKUP); \
		then \
			echo "Renaming existing $(FTPD) to $(FTPD).$(BACKUP)"; \
			mv $(FTPD) $(FTPD).$(BACKUP); \
			echo "Clearing permissions on $(FTPD).$(BACKUP)"; \
			chmod 0 $(FTPD).$(BACKUP); \
		fi; \
		echo "Copying OPIE ftp daemon to $(FTPD)"; \
		cp opieftpd $(FTPD); \
		echo "Changing ownership of $(FTPD)"; \
		$(CHOWN) $(OWNER) $(FTPD); \
		chgrp $(GROUP) $(FTPD); \
		echo "Changing file permissions of $(FTPD)"; \
		chmod 0100 $(FTPD); \
	fi
	@echo "Making sure OPIE database file exists";
	@touch $(KEY_FILE)
	@echo "Changing permissions of OPIE database file"
	@chmod 0644 $(KEY_FILE)
	@echo "Changing ownership of OPIE database file"
	@$(CHOWN) $(OWNER) $(KEY_FILE)
	@chgrp $(GROUP) $(KEY_FILE)
	@-if test ! -z "$(LOCK_DIR)"; then echo "Creating OPIE lock directory"; mkdir $(LOCK_DIR); $(CHOWN) 0 $(LOCK_DIR); chgrp 0 $(LOCK_DIR); chmod 0700 $(LOCK_DIR); fi;
	@-if test ! -z "$(ACCESS_FILE)"; then echo "Creating OPIE access file (don't say we didn't warn you)"; touch $(ACCESS_FILE); $(CHOWN) 0 $(ACCESS_FILE); chgrp 0 $(ACCESS_FILE); chmod 0444 $(ACCESS_FILE); fi;
	@echo "Installing manual pages"
	@if test ! -d $(LOCALMAN); then $(MKDIR) $(LOCALMAN); chmod 755 $(LOCALMAN); fi
	@for i in 1 4 5 8; do for j in *.$$i; do if test ! -d $(LOCALMAN)/man$$i; then $(MKDIR) $(LOCALMAN)/man$$i; chmod 755 $(LOCALMAN)/man$$i; fi; cp $$j $(LOCALMAN)/man$$i/$$j; $(CHOWN) $(OWNER) $(LOCALMAN)/man$$i/$$j; chgrp $(GROUP) $(LOCALMAN)/man$$i/$$j; chmod 644 $(LOCALMAN)/man$$i/$$j; done; done
	@echo "REMEMBER to run opiepasswd on your users immediately."

install: client-install server-install

uninstall:
	@echo "Un-installing OPIE..."
	@echo "Removing symlinks"
	@-for i in otp-md4 otp-md5; do rm $(LOCALBIN)/$$i; done
	@echo "Removing OPIE programs"
	@-for i in opiekey opiepasswd opieinfo; do rm $(LOCALBIN)/$$i; done
	@echo "Removing OPIE manual pages"
	@-for i in 1 4 5 8; do for j in *.$$i; do rm $(LOCALMAN)/man$$i/$$j; done; done
	@-rm $(LOCALMAN)/man1/otp-md4.1 $(LOCALMAN)/man1/otp-md5.1
	@echo "Restoring old binaries"
	@-for i in $(SU) $(ALT_SU) $(LOGIN) $(FTPD); do FILE=`basename $$i`; if test ! $(EXISTS) $$i.$(BACKUP); then echo "No $$i.$(BACKUP)! Aborting."; exit 1; else echo "Removing $$FILE"; rm $$i || true; echo "Restoring old $$FILE"; mv $$i.$(BACKUP) $$i; fi; done
	@echo "Resetting permissions"
	@chmod 4111 $(SU) $(LOGIN)
	@chmod 0100 $(FTPD)
	@if test ! -z "$(ALT_SU)"; then chmod 4111 $(ALT_SU); fi
	@echo "OPIE is now un-installed."
	@echo "Please verify by hand that this process worked."

opietest-passed:	opietest
	-./opietest && touch opietest-passed

libopie/libopie.a: libopie/*.c *.h
	(cd libopie ; $(MAKE) libopie.a CFL='$(CFLAGS) -DKEY_FILE=\"$(KEY_FILE)\"')

libmissing/libmissing.a: libmissing/*.c
	(cd libmissing ; $(MAKE) libmissing.a CFL='$(CFLAGS)')

clean:
	-rm -f *.o opiekey opiegen opielogin opiepasswd opiesu opieftpd
	-rm -f opieserv opieinfo opietest opieauto *core* opietest-passed
	-rm -f Makefile.munge configure.munger y.tab.c .gdb*
	(cd libopie ; $(MAKE) clean)
	(cd libmissing ; $(MAKE) clean)

realclean: distclean

distclean: clean
	-rm -f *~ core* "\#*\#" Makefile make.log
	-rm -f config.log config.status config.cache config.h
	(cd libopie ; $(MAKE) distclean)
	(cd libmissing ; $(MAKE) distclean)

opiekey:	opiekey.o $(LDEPS)
		$(CC) $(CFLAGS) opiekey.o $(LFLAGS) -o opiekey

opiegen:	opiegen.o $(LDEPS)
		$(CC) $(CFLAGS) opiegen.o $(LFLAGS) -o opiegen

opieserv:	opieserv.o $(LDEPS)
		$(CC) $(CFLAGS) opieserv.o $(LFLAGS) -o opieserv

opieftpd:	opieftpd.o glob.o popen.o y.tab.o $(LDEPS)
		$(CC) $(CFLAGS) opieftpd.o glob.o popen.o y.tab.o $(LFLAGS) -o opieftpd

opielogin:	opielogin.o permsfile.o $(LDEPS)
		$(CC) $(CFLAGS) opielogin.o permsfile.o $(LFLAGS) -o opielogin

opiepasswd:	opiepasswd.o $(LDEPS)
		$(CC) $(CFLAGS) opiepasswd.o $(LFLAGS) -o opiepasswd

opiesu:		opiesu.o $(LDEPS)
		$(CC) $(CFLAGS) opiesu.o $(LFLAGS) -o opiesu

y.tab.c:	ftpcmd.y
		$(YACC) ftpcmd.y

opieinfo:	opieinfo.o $(LDEPS)
		$(CC) $(CFLAGS) opieinfo.o $(LFLAGS) -o opieinfo

opietest:	opietest.o $(LDEPS)
		$(CC) $(CFLAGS) opietest.o $(LFLAGS) -o opietest

opieauto:	opieauto.o $(LDEPS)
		$(CC) $(CFLAGS) opieauto.o $(LFLAGS) -o opieauto

