dnl#	@(#)configure.ac	8.134 (Berkeley) 10/15/96

dnl# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.70])
AC_INIT([Nvi],[8],[])
AC_CONFIG_SRCDIR([../common/main.c])
AC_CONFIG_HEADERS([config.h])

dnl# Configure setup.
AC_PROG_INSTALL()
AC_CANONICAL_HOST
AC_ARG_PROGRAM()
AM_INIT_AUTOMAKE([foreign])
AM_MAINTAINER_MODE
AM_DEP_TRACK

dnl# If the user wants a debugging environment, set OPTFLAG now.  (Some
dnl# compilers won't mix optimizing and debug flags.)
AC_MSG_CHECKING([if --enable-debug option specified])
AC_ARG_ENABLE([debug],
	[AS_HELP_STRING([--enable-debug],[Build a debugging version.])],
	[vi_cv_debug="yes"],[vi_cv_debug="no"])
if test "x${vi_cv_debug}" = "xyes"; then
	AC_DEFINE([DEBUG])
	OPTFLAG=${OPTFLAG-"-g"}
	no_op_OPTFLAG=${no_op_OPTFLAG-"-g"}
fi
AC_MSG_RESULT([${vi_cv_debug}])

dnl# This is where we handle stuff that autoconf can't handle.
dnl# XXX
dnl# Don't override anything if it's already set from the environment.

dnl# Compiler, preprocessor and load flags.
dnl# AUX:	-ZP disables _BSD_SOURCE et al, but enables POSIX at link time.
dnl# LynxOS:	We check for gcc 2.x or better, the gcc 1 that was shipped with
dnl#		LynxOS historically wasn't good enough.
AC_SUBST([CPPFLAGS])
case "${host_os}" in
aix3.2.5)  OPTFLAG=${OPTFLAG-"-O"};;
aix4.1*)   CFLAGS=${CFLAGS-"-qstrict"}
	   OPTFLAG=${OPTFLAG-"-O3"};;
aux*)	   CPPFLAGS=${CPPFLAGS-"-ZP -D_BSD_SOURCE -D_SYSV_SOURCE -D_AUX_SOURCE"}
	   LDFLAGS=${LDFLAGS-"-ZP"}
	   OPTFLAG=${OPTFLAG-"-O"};;
bsd4.4)    OPTFLAG=${OPTFLAG-"-O2"};;
irix6*)	   OPTFLAG=${OPTFLAG-"-O2"};;
irix*)	   OPTFLAG=${OPTFLAG-"-O2"};;
nextstep3) CPPFLAGS=${CPPFLAGS-"-w -pipe -posix"}
	   LDFLAGS=${LDFLAGS-"-posix"}
	   OPTFLAG=${OPTFLAG-"-O9"};;
osf*)	   CFLAGS=${CFLAGS-"-Olimit 1000"};;
solaris*)  no_op_OPTFLAG=${no_op_OPTFLAG-""};;
sunos*)	   no_op_OPTFLAG=${no_op_OPTFLAG-""};;
darwin*)   CPPFLAGS=${CPPFLAGS-"-w -pipe"}
esac

dnl# The default compiler is cc.
AC_SUBST([CC_DEFAULT])
CC_DEFAULT=${CC_DEFAULT-cc}
AC_PROG_CC
AC_PROG_CPP
AC_PROG_LN_S

dnl# The default OPTFLAG is -O
AC_SUBST([OPTFLAG])
OPTFLAG=${OPTFLAG-"-O"}

dnl# The SunOS/Solaris compiler can't optimize vi/v_txt.c; the symptom is
dnl# that the command 35i==<esc> turns into an infinite loop.
AC_SUBST([no_op_OPTFLAG])
no_op_OPTFLAG=${no_op_OPTFLAG-"$OPTFLAG"}

dnl Libraries.
case "$host_os" in
bsdi2.1)   LIBS=${LIBS-"-lipc"};;
dgux*)	   LIBS=${LIBS-"-ldgc"};;
irix6*)	   LIBS=${LIBS-"-lbsd"};;
irix*)	   LIBS=${LIBS-"-lc_s -lbsd"};;
isc*)	   LIBS=${LIBS-"-lcposix -linet"};;
netbsd1*)  LIBS=${LIBS-"-lcrypt"};;
ptx*)	   LIBS=${LIBS-"-lseq -linet -lsocket"};;
sco3.2*)   LIBS=${LIBS-"-lsocket"};;
sinix*)	   LIBS=${LIBS-"-lelf -lc"};;
solaris*)  LIBS=${LIBS-"-lsocket -lnsl -ldl"}
	   RLIBS=yes;;
wgs*)	   LIBS=${LIBS-"-lnsl"};;
esac

dnl A/UX has a broken getopt(3), strpbrk(3).
case "$host_os" in
aux*)	   LIBOBJS="getopt.o strpbrk.o $LIBOBJS";;
esac

dnl Ultrix has a broken POSIX.1 VDISABLE value.
case "$host_os" in
ultrix*)   AC_DEFINE(HAVE_BROKEN_VDISABLE);;
esac

dnl The user may have additional CPP information.
CPPFLAGS="$ADDCPPFLAGS $CPPFLAGS"

dnl The user may have additional load line information.
LDFLAGS="$ADDLDFLAGS $LDFLAGS"

dnl The user may have additional library information.
LIBS="$ADDLIBS $LIBS"

dnl Check to see if it's going to work.
AM_SANITY_CHECK

dnl Checks for programs.
PATH="${PATH}:/usr/bin:/usr/sbin:/sbin:/etc:/usr/etc:/usr/lib:/usr/ucblib:"

dnl Check for the shell path.
AC_PATH_PROG(vi_cv_path_shell, sh, no)
if test "$vi_cv_path_shell" = no; then
	echo "Fatal error: the shell utility not found."
	exit 1
fi

dnl Check for the sendmail path.
AC_PATH_PROG(vi_cv_path_sendmail, sendmail, no)
if test "$vi_cv_path_sendmail" = no; then
	echo "WARNING: The sendmail utility was not found!"
	echo "WARNING: Users will not be told of saved files."
fi

dnl Check for the perl5/perl path.
AC_SUBST(vi_cv_path_perl)
AC_PATH_PROGS(vi_cv_path_perl, perl5 perl, no)

dnl Check for the "preserve" path.
dnl Historically, nvi has used /var/tmp/vi.recover.  The Linux filesystem
dnl standard (FSSTND) uses /var/preserve; we add the vi.recover directory
dnl beneath it so that we don't have name collisions with other editors.
dnl Other systems have /var/preserve as well, so we test first for an already
dnl existing name, and then use the first one that's writeable.
AC_SUBST(vi_cv_path_preserve)
AC_MSG_CHECKING(for preserve directory)
AC_CACHE_VAL(vi_cv_path_preserve, [dnl
	dirlist="/var/preserve /var/tmp /usr/tmp"
	vi_cv_path_preserve=no
	for i in $dirlist; do
		if test -d $i/vi.recover; then
			vi_cv_path_preserve=$i/vi.recover
			break;
		fi
	done
	if test "$vi_cv_path_preserve" = no; then
		for i in $dirlist; do
			if test -d $i -a -w $i; then
				vi_cv_path_preserve=$i/vi.recover
				break;
			fi
		done

	fi])
if test "$vi_cv_path_preserve" = no; then
	echo "Fatal error: no writeable preserve directory found."
	exit 1
fi
AC_MSG_RESULT($vi_cv_path_preserve)

dnl Check for programs used for installation
AC_PATH_PROG(vi_cv_path_chmod, chmod, missing_chmod)
AC_PATH_PROG(vi_cv_path_cp, cp, missing_cp)
AC_PATH_PROG(vi_cv_path_ln, ln, missing_ln)
AC_PATH_PROG(vi_cv_path_mkdir, mkdir, missing_mkdir)
AC_PATH_PROG(vi_cv_path_rm, rm, missing_rm)
AC_PATH_PROG(vi_cv_path_strip, strip, missing_strip)

dnl Checks for libraries.
dnl Find the X libraries and includes.
AC_PATH_X
AC_SUBST(XINCS)
if test "$no_x" != yes; then
	if test "X$x_libraries" != "X"; then
		if test "X$RLIBS" = "Xyes"; then
			XLIBS="-R$x_libraries -L$x_libraries $XLIBS"
		else
			XLIBS="-L$x_libraries $XLIBS"
		fi
	fi
	XLIBS="$XLIBS -lX11"
	if test "X$x_includes" != "X"; then
		XINCS="-I$x_includes"
	fi
fi

dnl If the user wants a Perl interpreter in nvi, load it.
AC_SUBST(shrpenv)
AC_SUBST(vi_cv_perllib)
AC_MSG_CHECKING(if --enable-perlinterp option specified)
AC_ARG_ENABLE(perlinterp,
	[  --enable-perlinterp     Include a Perl interpreter in vi.],
	[vi_cv_perlinterp="yes"], [vi_cv_perlinterp="no"])
AC_MSG_RESULT($vi_cv_perlinterp)
if test "$vi_cv_perlinterp" = "yes"; then
	if test "$vi_cv_path_perl" = no; then
		echo "Fatal error: no perl5 utility found."
		exit 1
	fi
	$vi_cv_path_perl -e 'require 5.002' || {
		echo "Fatal error: perl5 must be version 5.002 or later."
		exit 1
	}
	$vi_cv_path_perl -e 'close(STDERR);require 5.003_01' &&
	    AC_DEFINE(HAVE_PERL_5_003_01)

	eval `$vi_cv_path_perl -V:shrpenv`
	if test "X$shrpenv" = "XUNKNOWN"; then # pre 5.003_04
	    shrpenv=""
	fi
	vi_cv_perllib=`$vi_cv_path_perl -MConfig -e 'print $Config{privlib}'`
	perlcppflags=`$vi_cv_path_perl -Mlib=$srcdir -MExtUtils::Embed \
        	-e 'ccflags;perl_inc'`
	if test "X$perlcppflags" != "X"; then
		CPPFLAGS="$perlcppflags $CPPFLAGS"
	fi
	perllibs=`cd $srcdir;$vi_cv_path_perl -MExtUtils::Embed \
        	-e 'ldopts'`
	if test "X$perllibs" != "X"; then
		LIBS="$perllibs $LIBS"
	fi
	perlldflags=`cd $srcdir;$vi_cv_path_perl -MExtUtils::Embed \
        	-e 'ccdlflags'`
	if test "X$perlldflags" != "X"; then
		LDFLAGS="$perlldflags $LDFLAGS"
	fi
	LIBOBJS="perl.o perlsfio.o $LIBOBJS"
	AC_DEFINE(HAVE_PERL_INTERP)
fi

dnl If the user wants a Tk/Tcl front-end for nvi, build it.
AC_SUBST(tknvi)
AC_SUBST(TKLIBS)
AC_MSG_CHECKING(if --enable-tknvi option specified)
AC_ARG_ENABLE(tknvi,
	[  --enable-tknvi          Build a Tk/Tcl front-end for vi.],
	[vi_cv_tknvi="yes"], [vi_cv_tknvi="no"])
AC_MSG_RESULT($vi_cv_tknvi)
if test "$vi_cv_tknvi" = "yes"; then
	tknvi=tknvi
	TKLIBS="-ltk -ltcl -lm $XLIBS $LIBS"
fi

dnl If the user wants a Tk/Tcl interpreter in nvi, load it.
AC_MSG_CHECKING(if --enable-tclinterp option specified)
AC_ARG_ENABLE([tclinterp],
	[  --enable-tclinterp      Include a Tk/Tcl interpreter in vi.],
	[vi_cv_tclinterp="yes"], [vi_cv_tclinterp="no"])
AC_MSG_RESULT($vi_cv_tclinterp)
if test "$vi_cv_tclinterp" = "yes"; then
	LIBOBJS="tcl.o $LIBOBJS"
	LIBS="-ltk -ltcl -lm $XLIBS $LIBS"
	AC_DEFINE(HAVE_TCL_INTERP)
fi

dnl Make sure that we can find a Tk/Tcl library.
if test "$vi_cv_tknvi" = "yes" || test "$vi_cv_tclinterp" = "yes"; then
	AC_CHECK_LIB(tcl, main,
		[vi_cv_tkfatal="no"], [vi_cv_tkfatal="yes"], -ltk -lm)
	if test "$vi_cv_tkfatal" = "yes"; then
		echo "Fatal error: no Tk/Tcl library; see the section"
		echo "ADDING LIBRARIES AND INCLUDE FILES in the README file."
		exit 1
	fi
fi

dnl Both Tcl/Tk and Perl interpreters need the vi api code.
if test "$vi_cv_tclinterp" = yes || test "$vi_cv_perlinterp" = yes; then
	LIBOBJS="api.o $LIBOBJS"
fi

dnl Check for the termcap/termlib library.  Compile in nvi's curses routines
dnl unless the user specifies otherwise.  These two checks must occur in the
dnl current order, and -lcurses must be loaded before -ltermcap/-ltermlib.
AC_CHECK_LIB(termlib, tgetent,
	[vi_cv_termlib=-ltermlib], [vi_cv_termlib=no])
if test "$vi_cv_termlib" = no; then
	AC_CHECK_LIB(termcap, tgetent,
		[vi_cv_termlib=-ltermcap], [vi_cv_termlib=no])
fi
if test "$vi_cv_termlib" != no; then
	LIBS="$vi_cv_termlib $LIBS"
fi
AC_SUBST(cobjs)
AC_MSG_CHECKING(if --disable-curses option specified)
AC_ARG_ENABLE(curses,
	[  --disable-curses        DON'T use the nvi-provided curses routines.],
	[vi_cv_curses="other curses"], [vi_cv_curses="bundled curses"])
AC_MSG_RESULT($vi_cv_curses)
case "$vi_cv_curses" in
"bundled curses")
	CPPFLAGS="-I\$(srcdir)/curses $CPPFLAGS"
	cobjs="\$(COBJS)";;
"other curses")
	LIBS="-lcurses $LIBS";;
esac

dnl Checks for header files.
AC_MSG_CHECKING(for sys/mman.h)
AC_CACHE_VAL(vi_cv_include_sys_mman, [dnl
AC_PREPROC_IFELSE([AC_LANG_SOURCE([[#include <sys/mman.h>]])],[vi_cv_include_sys_mman=yes],[vi_cv_include_sys_mman=no])])
if test "$vi_cv_include_sys_mman" = yes; then
	AC_DEFINE(HAVE_SYS_MMAN_H)
fi
AC_MSG_RESULT($vi_cv_include_sys_mman)

AC_MSG_CHECKING(for sys/select.h)
AC_CACHE_VAL(vi_cv_include_sys_select, [dnl
AC_PREPROC_IFELSE([AC_LANG_SOURCE([[#include <sys/select.h>]])],[vi_cv_include_sys_select=yes],[vi_cv_include_sys_select=no])])
if test "$vi_cv_include_sys_select" = yes; then
	AC_DEFINE(HAVE_SYS_SELECT_H)
fi
AC_MSG_RESULT($vi_cv_include_sys_select)

dnl Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_TYPE(ssize_t, int)
AC_C_BIGENDIAN
AC_C_CONST
AC_CHECK_MEMBERS([struct stat.st_blksize],[AC_DEFINE(HAVE_ST_BLKSIZE, 1,
			    [Define to 1 if your `struct stat' has
			     `st_blksize'.  Deprecated, use
			     `HAVE_STRUCT_STAT_ST_BLKSIZE' instead.])])
AC_TYPE_MODE_T
AC_TYPE_OFF_T
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_STRUCT_TM

dnl Checks for library functions.
  AC_CHECK_FUNCS(bsearch gethostname getopt memchr memcpy memmove memset)
AC_REPLACE_FUNCS(bsearch gethostname getopt memchr memcpy memmove memset)
  AC_CHECK_FUNCS(mkstemp mmap snprintf strdup strerror strpbrk strtol)
AC_REPLACE_FUNCS(mkstemp mmap snprintf strdup strerror strpbrk strtol)
  AC_CHECK_FUNCS(strtoul vsnprintf)
AC_REPLACE_FUNCS(strtoul vsnprintf)

AC_CHECK_FUNCS(select)
AC_CHECK_FUNCS(setenv, [need_env=no], [need_env=yes])
AC_CHECK_FUNCS(strsep, [need_strsep=no], [need_strsep=yes])
AC_CHECK_FUNCS(unsetenv,, [need_env=yes])

AC_FUNC_MMAP
AC_FUNC_FORK

dnl If we needed setenv or unsetenv, add in the clib/env.c replacement file.
if test "$need_env" = yes; then
	LIBOBJS="env.o $LIBOBJS"
fi

dnl If we need strsep, add it and define it so we get a prototype.
if test "$need_strsep" = yes; then
	LIBOBJS="strsep.o $LIBOBJS"
fi

dnl Check for fcntl/flock
dnl Use flock preferentially, since it has cleaner semantics and won't
dnl hang up the editor.
dnl XXX
dnl Ultrix has a broken fcntl, but a working flock.
dnl IRIX and DGUX have a broken flock, but working fcntl.
AC_MSG_CHECKING(for fcntl/flock)
AC_CACHE_VAL(vi_cv_lock, [dnl
	vi_cv_lock=none
	case "$host_os" in
	dgux*);;
	irix*);;
	*)
		AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <fcntl.h>]], [[flock(0, 0);]])],[vi_cv_lock=flock],[]);;
	esac
	if test "$vi_cv_lock" = none; then
		AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <fcntl.h>]], [[fcntl(0, F_SETLK, 0);]])],[vi_cv_lock=fcntl],[])
	fi])

if test "$vi_cv_lock" = flock; then
	AC_DEFINE(HAVE_LOCK_FLOCK)
fi
if test "$vi_cv_lock" = fcntl; then
	AC_DEFINE(HAVE_LOCK_FCNTL)
fi
AC_MSG_RESULT($vi_cv_lock)

dnl Check for ftruncate/chsize
AC_MSG_CHECKING(for ftruncate/chsize)
AC_CACHE_VAL([vi_cv_ftruncate], [dnl
AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <unistd.h>]], [[ftruncate(0, 0);]])],[vi_cv_ftruncate=ftruncate],[AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <unistd.h>]], [[chsize(0, 0);]])],[vi_cv_ftruncate=chsize],[vi_cv_ftruncate=no])])])
if test "$vi_cv_ftruncate" = ftruncate; then
	AC_DEFINE(HAVE_FTRUNCATE_FTRUNCATE)
fi
if test "$vi_cv_ftruncate" = chsize; then
	AC_DEFINE(HAVE_FTRUNCATE_CHSIZE)
fi
AC_MSG_RESULT($vi_cv_ftruncate)

dnl Check for the tigetstr/tigetnum functions.
AC_MSG_CHECKING(for tigetstr/tigetnum)
AC_CACHE_VAL(vi_cv_have_curses_tigetstr, [dnl
AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <curses.h>]], [[tigetstr(0);]])],[vi_cv_have_curses_tigetstr=yes],[vi_cv_have_curses_tigetstr=no])])

if test "$vi_cv_have_curses_tigetstr" = yes; then
	AC_DEFINE(HAVE_CURSES_TIGETSTR)
fi
AC_MSG_RESULT($vi_cv_have_curses_tigetstr)

dnl Check for potentially missing curses functions in system or user-specified
dnl libraries.  We also have to guess at whether the specified library is a
dnl BSD or System V style curses.  Use the newterm function, all System V
dnl curses implementations have it, none, as far as I know, of the BSD ones do.
if test "$vi_cv_curses" = "bundled curses"; then
	AC_DEFINE(HAVE_BSD_CURSES)
	AC_DEFINE(HAVE_CURSES_ADDNSTR)
	AC_DEFINE(HAVE_CURSES_IDLOK)
else
	dnl Check for the addnstr function.
	AC_MSG_CHECKING(for addnstr)
	AC_CACHE_VAL(vi_cv_have_curses_addnstr, [dnl
	AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <curses.h>]], [[addnstr(0, 0);]])],[vi_cv_have_curses_addnstr=yes],[vi_cv_have_curses_addnstr=no])])
	if test "$vi_cv_have_curses_addnstr" = yes; then
		AC_DEFINE(HAVE_CURSES_ADDNSTR)
	fi
	AC_MSG_RESULT($vi_cv_have_curses_addnstr)

	dnl Check for the beep function.
	AC_MSG_CHECKING(for beep)
	AC_CACHE_VAL(vi_cv_have_curses_beep, [dnl
	AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <curses.h>]], [[beep();]])],[vi_cv_have_curses_beep=yes],[vi_cv_have_curses_beep=no])])

	if test "$vi_cv_have_curses_beep" = yes; then
		AC_DEFINE(HAVE_CURSES_BEEP)
	fi
	AC_MSG_RESULT($vi_cv_have_curses_beep)

	dnl Check for the flash function.
	AC_MSG_CHECKING(for flash)
	AC_CACHE_VAL(vi_cv_have_curses_flash, [dnl
	AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <curses.h>]], [[flash();]])],[vi_cv_have_curses_flash=yes],[vi_cv_have_curses_flash=no])])

	if test "$vi_cv_have_curses_flash" = yes; then
		AC_DEFINE(HAVE_CURSES_FLASH)
	fi
	AC_MSG_RESULT($vi_cv_have_curses_flash)

	dnl Check for the idlok function.
	AC_MSG_CHECKING(for idlok)
	AC_CACHE_VAL(vi_cv_have_curses_idlok, [dnl
	AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <curses.h>]], [[idlok(0, 0);]])],[vi_cv_have_curses_idlok=yes],[vi_cv_have_curses_idlok=no])])

	if test "$vi_cv_have_curses_idlok" = yes; then
		AC_DEFINE(HAVE_CURSES_IDLOK)
	fi
	AC_MSG_RESULT($vi_cv_have_curses_idlok)

	dnl Check for the keypad function.
	AC_MSG_CHECKING(for keypad)
	AC_CACHE_VAL(vi_cv_have_curses_keypad, [dnl
	AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <curses.h>]], [[keypad(0, 0);]])],[vi_cv_have_curses_keypad=yes],[vi_cv_have_curses_keypad=no])])

	if test "$vi_cv_have_curses_keypad" = yes; then
		AC_DEFINE(HAVE_CURSES_KEYPAD)
	fi
	AC_MSG_RESULT($vi_cv_have_curses_keypad)

	dnl Check for the newterm function.
	AC_MSG_CHECKING(for newterm)
	AC_CACHE_VAL(vi_cv_have_curses_newterm, [dnl
	AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <curses.h>]], [[newterm(0, 0, 0);]])],[vi_cv_have_curses_newterm=yes],[vi_cv_have_curses_newterm=no])])

	if test "$vi_cv_have_curses_newterm" = yes; then
		AC_DEFINE(HAVE_CURSES_NEWTERM)
	fi
	AC_MSG_RESULT($vi_cv_have_curses_newterm)

	if test "$vi_cv_have_curses_newterm" = no; then
		AC_DEFINE(HAVE_BSD_CURSES)
	fi
fi

dnl Check for the setupterm function.  We make this check regardless of
dnl using the system library, because it may be part of the underlying
dnl termcap/termlib support, and we want to use the local one.
AC_MSG_CHECKING(for setupterm)
AC_CACHE_VAL(vi_cv_have_curses_setupterm, [dnl
AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <curses.h>]], [[setupterm(0, 0, 0);]])],[vi_cv_have_curses_setupterm=yes],[vi_cv_have_curses_setupterm=no])])

if test "$vi_cv_have_curses_setupterm" = yes; then
	AC_DEFINE(HAVE_CURSES_SETUPTERM)
fi
AC_MSG_RESULT($vi_cv_have_curses_setupterm)

dnl Some moron decided to drop off an argument from the gettimeofday call,
dnl without changing the name.
AC_MSG_CHECKING(for broken gettimeofday system call)
AC_CACHE_VAL(vi_cv_gettimeofday, [dnl
AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <sys/types.h>
#include <sys/time.h>]], [[gettimeofday(0, 0);]])],[vi_cv_gettimeofday=okay],[vi_cv_gettimeofday=broken])])

if test "$vi_cv_gettimeofday" = broken; then
	AC_DEFINE(HAVE_BROKEN_GETTIMEOFDAY)
fi
AC_MSG_RESULT($vi_cv_gettimeofday)

dnl Check for which version of openpty to use, System V or Berkeley.
AC_MSG_CHECKING(for System V pty calls)
AC_CACHE_VAL(vi_cv_sys5_pty, [dnl
AC_LINK_IFELSE([AC_LANG_PROGRAM([[]], [[grantpt(0);]])],[vi_cv_sys5_pty=yes],[vi_cv_sys5_pty=no])])

if test "$vi_cv_sys5_pty" = yes; then
	AC_DEFINE(HAVE_SYS5_PTY)
fi
AC_MSG_RESULT($vi_cv_sys5_pty)

dnl Check for the revoke system call.
AC_MSG_CHECKING(for revoke system call)
AC_CACHE_VAL(vi_cv_revoke, [dnl
AC_LINK_IFELSE([AC_LANG_PROGRAM([[]], [[revoke("a");]])],[vi_cv_revoke=yes],[vi_cv_revoke=no])])

if test "$vi_cv_revoke" = yes; then
	AC_DEFINE(HAVE_REVOKE)
fi
AC_MSG_RESULT($vi_cv_revoke)

dnl Some versions of sprintf return a pointer to the first argument instead
dnl of a character count.  We assume that the return value of snprintf and
dnl vsprintf etc. will be the same as sprintf, and check the easy one.
AC_MSG_CHECKING(for int type sprintf return value)
AC_CACHE_VAL(vi_cv_sprintf_count, [dnl
AC_RUN_IFELSE([AC_LANG_SOURCE([[main(){char buf[20]; exit(sprintf(buf, "XXX") != 3);}]])],[vi_cv_sprintf_count=yes],[vi_cv_sprintf_count=no],[])])

if test "$vi_cv_sprintf_count" = no; then
	AC_DEFINE(SPRINTF_RET_CHARPNT)
fi
AC_MSG_RESULT($vi_cv_sprintf_count)

dnl We compile in nvi's DB routines unless the user specifies otherwise.
AC_MSG_CHECKING(if --disable-db option specified)
AC_ARG_ENABLE([db],
	[  --disable-db            DON'T use the nvi-provided DB routines.],
	[vi_cv_db_lib="other DB"], [vi_cv_db_lib="bundled DB"])
AC_MSG_RESULT($vi_cv_db_lib)
case "$vi_cv_db_lib" in
"bundled DB")
	CPPFLAGS="-I\$(srcdir)/db/include $CPPFLAGS"
	LIBOBJS="\$(DBOBJS) $LIBOBJS";;
"other DB")
	;;
esac

dnl We compile in nvi's RE routines unless the user specifies otherwise.
AC_MSG_CHECKING(if --disable-re option specified)
AC_ARG_ENABLE([re],
	[  --disable-re            DON'T use the nvi-provided RE routines.],
	[vi_cv_re_lib="other RE"], [vi_cv_re_lib="bundled RE"])
AC_MSG_RESULT($vi_cv_re_lib)
case "$vi_cv_re_lib" in
"bundled RE")
	CPPFLAGS="-I\$(srcdir)/regex $CPPFLAGS"
	LIBOBJS="\$(REOBJS) $LIBOBJS";;
"other RE")
	;;
esac

dnl Check for the standard shorthand types.
AC_SUBST(u_char_decl)
AC_MSG_CHECKING(for u_char)
AC_CACHE_VAL(vi_cv_uchar, [dnl
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <sys/types.h>]], [[u_char foo;]])],[vi_cv_uchar=yes],[vi_cv_uchar=no])])

AC_MSG_RESULT($vi_cv_uchar)
if test "$vi_cv_uchar" = no; then
	u_char_decl="typedef unsigned char u_char;"
fi

AC_SUBST(u_short_decl)
AC_MSG_CHECKING(for u_short)
AC_CACHE_VAL(vi_cv_ushort, [dnl
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <sys/types.h>]], [[u_short foo;]])],[vi_cv_ushort=yes],[vi_cv_ushort=no])])

AC_MSG_RESULT($vi_cv_ushort)
if test "$vi_cv_ushort" = no; then
	u_short_decl="typedef unsigned short u_short;"
fi

AC_SUBST(u_int_decl)
AC_MSG_CHECKING(for u_int)
AC_CACHE_VAL(vi_cv_uint, [dnl
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <sys/types.h>]], [[u_int foo;]])],[vi_cv_uint=yes],[vi_cv_uint=no])])

AC_MSG_RESULT($vi_cv_uint)
if test "$vi_cv_uint" = no; then
	u_int_decl="typedef unsigned int u_int;"
fi

AC_SUBST(u_long_decl)
AC_MSG_CHECKING(for u_long)
AC_CACHE_VAL(vi_cv_ulong, [dnl
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <sys/types.h>]], [[u_long foo;]])],[vi_cv_ulong=yes],[vi_cv_ulong=no])])

AC_MSG_RESULT($vi_cv_ulong)
if test "$vi_cv_ulong" = no; then
	u_long_decl="typedef unsigned long u_long;"
fi

dnl DB/Vi use specific integer sizes.
AC_SUBST(u_int8_decl)
AC_MSG_CHECKING(for u_int8_t)
AC_CACHE_VAL(vi_cv_uint8, [dnl
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <sys/types.h>]], [[u_int8_t foo;]])],[vi_cv_uint8=yes],[AC_RUN_IFELSE([AC_LANG_SOURCE([[main(){exit(sizeof(unsigned char) != 1);}]])],[vi_cv_uint8="unsigned char"],[vi_cv_uint8=no],[])])])
AC_MSG_RESULT($vi_cv_uint8)
if test "$vi_cv_uint8" = no; then
	echo ""
	echo "Fatal error: no unsigned, 8-bit integral type."
	exit 1
fi
if test "$vi_cv_uint8" != yes; then
	u_int8_decl="typedef $vi_cv_uint8 u_int8_t;"
fi

AC_SUBST(u_int16_decl)
AC_MSG_CHECKING(for u_int16_t)
AC_CACHE_VAL(vi_cv_uint16, [dnl
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <sys/types.h>]], [[u_int16_t foo;]])],[vi_cv_uint16=yes],[AC_RUN_IFELSE([AC_LANG_SOURCE([[main(){exit(sizeof(unsigned short) != 2);}]])],[vi_cv_uint16="unsigned short"],[AC_RUN_IFELSE([AC_LANG_SOURCE([[main(){exit(sizeof(unsigned int) != 2);}]])],[vi_cv_uint16="unsigned int"],[vi_cv_uint16=no],[])],[])])])
AC_MSG_RESULT($vi_cv_uint16)
if test "$vi_cv_uint16" = no; then
	echo ""
	echo "Fatal error: no unsigned, 16-bit integral type."
	exit 1
fi
if test "$vi_cv_uint16" != yes; then
	u_int16_decl="typedef $vi_cv_uint16 u_int16_t;"
fi

AC_SUBST(int16_decl)
AC_MSG_CHECKING(for int16_t)
AC_CACHE_VAL(vi_cv_int16, [dnl
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <sys/types.h>]], [[int16_t foo;]])],[vi_cv_int16=yes],[AC_RUN_IFELSE([AC_LANG_SOURCE([[main(){exit(sizeof(short) != 2);}]])],[vi_cv_int16="short"],[AC_RUN_IFELSE([AC_LANG_SOURCE([[main(){exit(sizeof(int) != 2);}]])],[vi_cv_int16="int"],[vi_cv_int16=no],[])],[])])])
AC_MSG_RESULT($vi_cv_int16)
if test "$vi_cv_int16" = no; then
	echo
	echo "Fatal error: no signed, 16-bit integral type."
	exit 1
fi
if test "$vi_cv_int16" != yes; then
	int16_decl="typedef $vi_cv_int16 int16_t;"
fi

AC_SUBST(u_int32_decl)
AC_MSG_CHECKING(for u_int32_t)
AC_CACHE_VAL(vi_cv_uint32, [dnl
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <sys/types.h>]], [[u_int32_t foo;]])],[vi_cv_uint32=yes],[AC_RUN_IFELSE([AC_LANG_SOURCE([[main(){exit(sizeof(unsigned int) != 4);}]])],[vi_cv_uint32="unsigned int"],[AC_RUN_IFELSE([AC_LANG_SOURCE([[main(){exit(sizeof(unsigned long) != 4);}]])],[vi_cv_uint32="unsigned long"],[vi_cv_uint32=no],[])],[])])])
AC_MSG_RESULT($vi_cv_uint32)
if test "$vi_cv_uint32" = no; then
	echo ""
	echo "Fatal error: no unsigned, 32-bit integral type."
	exit 1
fi
if test "$vi_cv_uint32" != yes; then
	u_int32_decl="typedef $vi_cv_uint32 u_int32_t;"
fi

AC_SUBST(int32_decl)
AC_MSG_CHECKING(for int32_t)
AC_CACHE_VAL(vi_cv_int32, [dnl
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <sys/types.h>]], [[int32_t foo;]])],[vi_cv_int32=yes],[AC_RUN_IFELSE([AC_LANG_SOURCE([[main(){exit(sizeof(int) != 4);}]])],[vi_cv_int32="int"],[AC_RUN_IFELSE([AC_LANG_SOURCE([[main(){exit(sizeof(long) != 4);}]])],[vi_cv_int32="long"],[vi_cv_int32=no],[])],[])])])
AC_MSG_RESULT($vi_cv_int32)
if test "$vi_cv_int32" = no; then
	echo ""
	echo "Fatal error: no signed, 32-bit integral type."
	exit 1
fi
if test "$vi_cv_int32" != yes; then
	int32_decl="typedef $vi_cv_int32 int32_t;"
fi

AC_CONFIG_FILES([Makefile port.h:port.h.in
    pathnames.h:pathnames.h.in recover:recover.in])
AC_OUTPUT
