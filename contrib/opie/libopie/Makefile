##
# Makefile.in/Makefile: Directions for building libopie.
#
# %%% copyright-cmetz-96
# This software is Copyright 1996-2001 by Craig Metz, All Rights Reserved.
# The Inner Net License Version 3 applies to this software.
# You should have received a copy of the license with this software. If
# you didn't get a copy, you may request one from <license@inner.net>.
#
#	History:
#
#	Modified by cmetz for OPIE 2.4. Add libmissing to include header path.
#		Use ar 'cr' instead of 'r'. Renamed realclean to distclean.
#	Modified by cmetz for OPIE 2.31. Added logwtmp.o
#       Created by cmetz for OPIE 2.3 using old Makefiles as a guide.

OBJS=md4c.o md5c.o atob8.o btoa8.o btoh.o challenge.o getsequence.o hash.o hashlen.o keycrunch.o lock.o lookup.o newseed.o parsechallenge.o passcheck.o passwd.o randomchallenge.o readpass.o unlock.o verify.o version.o btoe.o accessfile.o generator.o insecure.o getutmpentry.o readrec.o writerec.o login.o open.o logwtmp.o # sha.o

CC=gcc
CFLAGS=$(CFL) -I.. -I../libmissing
TARGET=libopie.a

all: $(TARGET)

$(TARGET): $(OBJS)
	ar cr $(TARGET) $(OBJS)
	ranlib $(TARGET)

clean:
	-rm -f $(OBJS) $(TARGET)

realclean: distclean

distclean: clean
	-rm -f *~ core* "\#*\#" *.o *.a Makefile
