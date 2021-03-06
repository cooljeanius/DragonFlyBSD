dnl# configure.ac: Input for Autoconf
dnl#
dnl# %%% portions-copyright-cmetz-96
dnl Portions of this software are Copyright 1996-1999 by Craig Metz, All Rights
dnl Reserved. The Inner Net License Version 2 applies to these portions of
dnl the software.
dnl You should have received a copy of the license with this software. If
dnl you didn't get a copy, you may request one from <license@inner.net>.
dnl
dnl Portions of this software are Copyright 1995 by Randall Atkinson and Dan
dnl McDonald, All Rights Reserved. All Rights under this copyright are assigned
dnl to the U.S. Naval Research Laboratory (NRL). The NRL Copyright Notice and
dnl License Agreement applies to this software.   
dnl
dnl	History:
dnl
dnl	Modified by cmetz for OPIE 2.4. Add --enable-opieauto option. Check
dnl	     for ut_id and ut_syslen. Make disable-wtmp disable wtmp not utmp.
dnl	     Define HAVE_foo if foo is found by the libmissing function check.
dnl	     Added checks for libmissing functions that were there but never
dnl	     actually checked for and therefore available.
dnl	Modified by cmetz for OPIE 2.32. Substitute default for LOCK_DIR.
dnl	     Fix the --disable-user-locking bug. AC_DEFINE variables to 1.
dnl          Really check for ut_host.
dnl	Modified by cmetz for OPIE 2.31. Put back manual utmp[x]/wtmp[x]
dnl          checks -- too many OSs can't be trusted to tell us where they are.
dnl	     Check for sys/select.h. Spell endutent right. Replace strtoul()
dnl	     if needed. Removed duplicate check for sysconf. Added check for
dnl          SunOS C2 shadow passwords (may need more work). Replace
dnl          setutent. Added options to disable use of utmp/wtmp. Replace
dnl          seteuid and setegid. Check for usleep. Moved options.h options
dnl          here as enable/disable options.
dnl     Modified by cmetz for OPIE 2.3. Removed redundant memset/memcpy.
dnl	     Changed ls -g test around. Changed logindevperm/fbtab defines.
dnl	     Added check for /etc/environment and /etc/src.sh. Check for
dnl          /var/adm/sulog. Check for {get,put}utxline, provide libmissing
dnl          versionf of {get,put}utline. Added --enable option for anonymous
dnl          FTP. Got rid of a few unneeded checks. Check for functions only
dnl	     used by libmissing only if the replacement function that needs
dnl	     them is itself needed.
dnl	Modified by cmetz for OPIE 2.22. Check for Solaris drain bamaged ls.
dnl          Check for setlogin(). Removed duplicate checks for some funcs.
dnl     Modified by cmetz for OPIE 2.21. Filename must be in utmp[x]/wtmp[x]
dnl          defines.
dnl     Modified by cmetz for OPIE 2.2. Misc changes. Changed for libmissing
dnl          support and building its target object list. Changed to support
dnl          FUNCTION declaration et al. Added a LOT of checks and a LOT of
dnl          fixes.
dnl	Created at NRL for OPIE 2.1.

AC_PREREQ([2.70])
AC_INIT([opie],[2.4],[license@inner.net])
AC_CONFIG_SRCDIR([README])
AC_CONFIG_HEADERS([config.h])
AC_ARG_ENABLE([access-file],
              [AS_HELP_STRING([--enable-access-file=FILENAME],
                              [Enable the OPIE access file FILENAME])],
              [AC_DEFINE_UNQUOTED([PATH_ACCESS_FILE],["${enable_access_file}"])
               echo "Using the access file in ${enable_access_file} -- don't say we didn't warn you!"])
ACCESS_FILE="${enable_access_file}"
AC_SUBST([ACCESS_FILE])
AC_ARG_ENABLE([server-md4],
              [AS_HELP_STRING([--enable-server-md4],
                              [Use MD4 instead of MD5 for the server])],
              [AC_DEFINE([MDX],[4])],[AC_DEFINE([MDX],[5])])dnl

AC_ARG_ENABLE([user-locking],
              [AS_HELP_STRING([--disable-user-locking],
                              [Disable user locking])
dnl# since we are sticking two help strings in a single argument here, this
dnl# next line needs to be left-aligned to display properly:
AS_HELP_STRING([--enable-user-locking[=DIR]],
               [Put user lock files in DIR [/etc/opielocks]])],[],[])
if test "x${enable_user_locking}" != "xno";
then
  if test -z "${enable_user_locking}"
  then
    AC_DEFINE([OPIE_LOCK_DIR],["/etc/opielocks"])
    LOCK_DIR="/etc/opielocks"
  else
    AC_DEFINE_UNQUOTED([OPIE_LOCK_DIR],["${enable_user_locking}"])
    LOCK_DIR="${enable_user_locking}"
  fi
fi
AC_SUBST([LOCK_DIR])dnl

AC_ARG_ENABLE([retype],
              [AS_HELP_STRING([--enable-retype],
                          [Ask users to re-type their secret pass phrases])],
              [AC_DEFINE([RETYPE],[1])])
AC_ARG_ENABLE([su-star-check],
              [AS_HELP_STRING([--enable-su-star-check],
                              [Refuse to switch to disabled accounts])],
              [AC_DEFINE([SU_STAR_CHECK],[1])])
AC_ARG_ENABLE([new-prompts],
              [AS_HELP_STRING([--disable-new-prompts],
                      [Use more compatible (but less informative) prompts])],
              [],[AC_DEFINE([NEW_PROMPTS],[1])])
AC_ARG_ENABLE([insecure-override],
              [AS_HELP_STRING([--enable-insecure-override],
                              [Allow users to override insecure checks])],
              [AC_DEFINE([INSECURE_OVERRIDE],[1])])
AC_ARG_ENABLE([anonymous-ftp],
              [AS_HELP_STRING([--enable-anonymous-ftp],
                              [Enable anonymous FTP support])],
              [AC_DEFINE([DOANONYMOUS],[1])dnl
  ## (useless line starting with spaces in case line-eating behavior changes)
echo "enabling anonymous FTP support in ftp -- don't say we didn't warn you!"])
AC_ARG_ENABLE([utmp],[AS_HELP_STRING([--disable-utmp],[Disable utmp logging])], 
              [AC_DEFINE([DISABLE_UTMP],[1])dnl
               echo "disabling utmp logging"])
AC_ARG_ENABLE([wtmp],[AS_HELP_STRING([--disable-wtmp],[Disable wtmp logging])], 
              [AC_DEFINE([DISABLE_WTMP],[1])dnl
               echo "disabling wtmp logging"])
AC_ARG_ENABLE([opieauto],
              [AS_HELP_STRING([--enable-opieauto],
                              [Enable support for opieauto])],
              [AC_DEFINE([OPIEAUTO],[1])dnl
               OPIEAUTO=opieauto; echo "enabling opieauto support"])
AC_SUBST([OPIEAUTO])dnl

dnl# Checks for programs.
AC_PROG_CC
AC_PROG_CPP
AC_PROG_LN_S
AC_PROG_RANLIB
AC_PROG_YACC

AC_USE_SYSTEM_EXTENSIONS
AC_SEARCH_LIBS([strerror],[cposix])dnl

dnl# We'd put PATH in these checks, but it turns out that autoconf doesn't
dnl# work as documented when it comes to the colon separator...

AC_PATH_PROG([CHOWN],[chown],[/bin/chown],
             [/usr/bin /bin /usr/sbin /sbin /usr/etc /etc])

AC_PATH_PROG([SU],[su],[/bin/su],[/usr/bin /bin])
AC_PATH_PROG([ALT_SU],[su],[],[/usr/sbin /sbin])

AC_PATH_PROG([BASHDB],[bashdb],[sh],
             [/usr/bin /bin /opt/local/bin /opt/sw/bin /usr/local/bin])

AC_PATH_PROG([SCHEME],[scheme],[],[/usr/lib/iaf/scheme])
AC_PATH_PROG([LOGIN],[login],[/bin/login],[/usr/bin /bin])

if test ! -z "${SCHEME}";
then
	LOGIN="${SCHEME}";
fi

AC_PATH_PROG([FTPD],[ftpd],[],
             [/usr/libexec /usr/etc /etc /usr/sbin /sbin /usr/lbin])
AC_PATH_PROG([INFTPD],[in.ftpd],[],
             [/usr/libexec /usr/etc /etc /usr/sbin /sbin /usr/lbin])

if test -z "${FTPD}"
then
	if test ! -z "${INFTPD}"
	then
		FTPD="${INFTPD}"
	fi
fi

AC_MSG_CHECKING([for default PATH entries])
default_path=""
save_IFS="${IFS}"
IFS=" "
for i in /usr/bin /bin /usr/ucb /usr/sbin /usr/bsd /sbin /usr/bin/X11 /etc /usr/local/X11/bin /usr/X11R6/bin /your-system-is-broken
do
	IFS=":"
	for j in $PATH
	do
		if test "${i}" = "${j}"
		then
			if test -d "${i}"
			then
				if test -z "${default_path}"
				then
					default_path="${i}"
				else
					default_path="${default_path}:${i}"
				fi
			fi
		fi
	done
	IFS=" "
done
IFS="${save_IFS}"
AC_DEFINE_UNQUOTED([DEFAULT_PATH],["${default_path}"])
AC_MSG_RESULT([${default_path}])

AC_MSG_CHECKING([for test -e flag])
if sh config.testeflag
then
	result=yes
	EXISTS="-e"
else
	result=no
	EXISTS="-f"
fi
AC_SUBST([EXISTS])
AC_MSG_RESULT([${result}])

AC_MSG_CHECKING([for mkdir -p flag])
if test -d config.tmpdir
then
	rmdir config.tmpdir/foo/bar >/dev/null 2>/dev/null
	rmdir config.tmpdir/foo >/dev/null 2>/dev/null
	rmdir config.tmpdir >/dev/null 2>/dev/null
fi

result=no
if mkdir -p config.tmpdir/foo/bar >/dev/null 2>/dev/null
then
	if test -d config.tmpdir
	then
		if test -d config.tmpdir/foo
		then
			if test -d config.tmpdir/foo/bar
			then
				result=yes
				rmdir config.tmpdir/foo/bar >/dev/null 2>/dev/null
			fi
			rmdir config.tmpdir/foo >/dev/null 2>/dev/null
		fi
		rmdir config.tmpdir >/dev/null 2>/dev/null
	fi
fi

if test "${result}" = yes
then
	MKDIR="mkdir -p"
else
	MKDIR="mkdir"
fi
AC_SUBST([MKDIR])
AC_MSG_RESULT([${result}])

AC_MSG_CHECKING(for ls group field)
lsg=`/bin/ls -ldg / | wc -w | awk '{print $1}'`;
ls=`/bin/ls -ld / | wc -w | awk '{print $1}'`;
result="no"
if test $ls = 9;
then
	result="yes"
else
	if test "$ls" = 8 -a "$lsg" = 9;
	then
		result="yes, with -g"
		AC_DEFINE(HAVE_LS_G_FLAG)
	fi
fi
AC_MSG_RESULT($result)

dnl Checks for various system characteristics
AC_MSG_CHECKING(for /etc/default/login)
if test $EXISTS /etc/default/login
then
	result=yes
	AC_DEFINE(HAVE_ETC_DEFAULT_LOGIN)
else
	result=no
fi
AC_MSG_RESULT($result)

AC_MSG_CHECKING(for /etc/securetty)
if test $EXISTS /etc/securetty
then
	result=yes
	AC_DEFINE(HAVE_SECURETTY)
else
	result=no
fi
AC_MSG_RESULT($result)

AC_MSG_CHECKING(for /etc/logindevperm)
if test $EXISTS /etc/logindevperm
then
	AC_MSG_RESULT(yes)
	AC_DEFINE(HAVE_LOGIN_PERMFILE, "/etc/logindevperm")
else
	AC_MSG_RESULT(no)

	AC_MSG_CHECKING(for /etc/fbtab)
	if test $EXISTS /etc/fbtab
	then
		result=yes
		AC_DEFINE(HAVE_LOGIN_PERMFILE, "/etc/fbtab")
	else
		result=no
	fi
	AC_MSG_RESULT($result)
fi

AC_MSG_CHECKING(for /etc/environment)
if test $EXISTS /etc/environment
then
	AC_MSG_RESULT(yes)
	AC_DEFINE(HAVE_LOGIN_ENVFILE, "/etc/environment")
else
	AC_MSG_RESULT(no)

	AC_MSG_CHECKING(for /etc/src.sh)
	if test $EXISTS /etc/src.sh
	then
		result=yes
		AC_DEFINE(HAVE_LOGIN_ENVFILE, "/etc/src.sh")
	else
		result=no
	fi
	AC_MSG_RESULT($result)
fi

AC_MSG_CHECKING(for /etc/shadow)
if test $EXISTS /etc/shadow
then
	result=yes
	AC_DEFINE(HAVE_ETC_SHADOW)
else
	AC_MSG_RESULT(no)

	AC_MSG_CHECKING(for /etc/security/passwd.adjunct)
	if test $EXISTS /etc/security/passwd.adjunct
	then
		result=yes
		AC_DEFINE(HAVE_SUNOS_C2_SHADOW)
		LIBOBJS="$LIBOBJS getspnam.o endspent.o"
	else
		result=no
	fi
fi
AC_MSG_RESULT($result)

AC_MSG_CHECKING(for /var/adm/sulog)
if test $EXISTS /var/adm/sulog
then
	result=yes
	AC_DEFINE(HAVE_SULOG)
else
	result=no
fi
AC_MSG_RESULT($result)

AC_MSG_CHECKING(mail spool location)
mail_spool=""
for i in /var/mail /usr/mail /var/spool/mail /usr/spool/mail
do
	if test -d $i
	then
		mail_spool="$i"
	fi
done
if test -z "$mail_spool"
then
	result="not found"
else
	result="$mail_spool"
	AC_DEFINE_UNQUOTED(PATH_MAIL, "$mail_spool")
fi
AC_MSG_RESULT($result)

AC_MSG_CHECKING(where your system puts the utmp file)
utmp_path=""
for i in /var/run /var/adm /usr/adm /etc
do
	if test $EXISTS $i/utmp
	then
		utmp_path="$i"
	fi
done
if test -z "$utmp_path"
then
	result="not found"
else
	result="$utmp_path"
	AC_DEFINE_UNQUOTED(PATH_UTMP_AC, "$utmp_path/utmp")
fi
AC_MSG_RESULT($result)

AC_MSG_CHECKING(where your system puts the utmpx file)
utmp_path=""
for i in /var/run /var/adm /usr/adm /etc
do
	if test $EXISTS $i/utmp
	then
		utmp_path="$i"
	fi
done
if test -z "$utmp_path"
then
	result="not found"
	AC_DEFINE_UNQUOTED(PATH_UTMP_AC, "$utmp_path/utmpx")
fi
AC_MSG_RESULT($result)

AC_MSG_CHECKING(where your system puts the wtmp file)
wtmp_path=""
for i in /var/run /var/log /var/adm /usr/adm /etc
do
	if test $EXISTS $i/wtmp
	then
		wtmp_path="$i"
	fi
done
if test -z "$wtmp_path"
then
	result="not found"
else
	result="$wtmp_path"
	AC_DEFINE_UNQUOTED(PATH_WTMP_AC, "$wtmp_path/wtmp")
fi
AC_MSG_RESULT($result)

AC_MSG_CHECKING(where your system puts the wtmpx file)
wtmpx_path=""
for i in /var/run /var/log /var/adm /usr/adm /etc
do
	if test $EXISTS $i/wtmpx
	then
		wtmpx_path="$i"
	fi
done
if test -z "$wtmpx_path"
then
	result="not found"
else
	result="$wtmpx_path"
	AC_DEFINE_UNQUOTED(PATH_WTMPX_AC, "$wtmpx_path/wtmpx")
fi
AC_MSG_RESULT($result)

AC_MSG_CHECKING(whether the system profile displays the motd)
result=no
if test ${EXISTS} /etc/profile
then
	if grep motd /etc/profile >/dev/null 2>/dev/null
	then
		result=yes
	fi
fi
if test "${result}" = yes
then
	AC_DEFINE([HAVE_MOTD_IN_PROFILE])
fi
AC_MSG_RESULT([${result}])

AC_MSG_CHECKING([whether the system profile checks for mail])
result=no
if test ${EXISTS} /etc/profile
then
	if grep 'mail\.' /etc/profile >/dev/null 2>/dev/null
	then
		result=yes
	fi
fi
if test "${result}" = yes
then
	AC_DEFINE([HAVE_MAILCHECK_IN_PROFILE])
fi
AC_MSG_RESULT([${result}])

dnl# Random checks
AC_C_CONST

AC_MSG_CHECKING(to see if your compiler can handle void arguments)
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[foo(void) { }]], [[]])],[AC_DEFINE([HAVE_VOIDARG]) AC_MSG_RESULT([yes])],[AC_MSG_RESULT([no])])

AC_MSG_CHECKING(to see if your compiler can handle void return values)
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[void foo() { }]], [[]])],[AC_DEFINE([HAVE_VOIDRET]) AC_MSG_RESULT([yes])],[AC_MSG_RESULT([no])])

AC_MSG_CHECKING(to see if your compiler can handle void pointers)
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[foo() { void *bar = (void *)0x42; bar = bar + 1; }]], [[]])],[AC_DEFINE([HAVE_VOIDPTR]) AC_MSG_RESULT([yes])],[AC_MSG_RESULT([no])])

AC_MSG_CHECKING(to see if your compiler can handle ANSI argument lists)
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[int foo(int bar, int baz) { return 0; }]], [[]])],[AC_DEFINE([HAVE_ANSIDECL]) AC_MSG_RESULT([yes])],[AC_MSG_RESULT([no])])

AC_MSG_CHECKING(to see if your compiler can handle ANSI prototypes)
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[extern int foo(int, int);]], [[]])],[AC_DEFINE([HAVE_ANSIPROTO]) AC_MSG_RESULT([yes])],[AC_MSG_RESULT([no])])

AC_MSG_CHECKING(to see if your compiler can handle ANSI variable arguments)
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <stdarg.h>
int foo(int arg, ...) {
	va_list ap;
	va_start(ap, arg);
	va_end(ap);
	return 0;
}]], [[]])],[AC_DEFINE([HAVE_ANSISTDARG]) AC_MSG_RESULT([yes])],[AC_MSG_RESULT([no])])

AC_MSG_CHECKING(to see if you have an ANSI-style sprintf)
AC_RUN_IFELSE([AC_LANG_SOURCE([[#include <stdio.h>
int main(argc, argv)
int argc;
char *argv[];
{
  char buf[5];
  int i = 2;
  i += sprintf(buf, "1234");
  return (i == 6) ? 0 : -1;
}]])],[AC_DEFINE([HAVE_ANSISPRINTF]) AC_MSG_RESULT([yes])],[AC_MSG_RESULT([no])],[AC_MSG_RESULT(no)])

dnl# Checks for libraries.
AC_CHECK_LIB([crypt],[crypt])
AC_CHECK_LIB([nsl],[gethostname])
AC_CHECK_LIB([posix],[main])
AC_CHECK_LIB([socket],[socket])

dnl# Checks for header files.
AC_HEADER_DIRENT
AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS([arpa/inet.h crypt.h fcntl.h lastlog.h limits.h netdb.h \
                  netinet/in.h paths.h pwd.h shadow.h signal.h string.h \
                  stdlib.h sys/file.h sys/ioctl.h sys/param.h sys/select.h \
                  sys/signal.h sys/socket.h sys/time.h sys/utsname.h \
                  syslog.h termios.h unistd.h utmp.h utmpx.h])

dnl# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_UID_T
AC_TYPE_OFF_T
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_CHECK_MEMBERS([struct stat.st_blksize])

AC_MSG_CHECKING([for ut_pid in struct utmp])
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <sys/types.h>
#include <utmp.h>]], [[struct utmp foo; return (int)foo.ut_pid;]])],[AC_DEFINE(HAVE_UT_PID) AC_MSG_RESULT([yes])],[AC_MSG_RESULT([no])])
AC_MSG_CHECKING(for ut_type in struct utmp)
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <sys/types.h>
#include <utmp.h>]], [[struct utmp foo; return (int)foo.ut_type;]])],[AC_DEFINE(HAVE_UT_TYPE) AC_MSG_RESULT([yes])],[AC_MSG_RESULT([no])])
AC_MSG_CHECKING(for ut_name in struct utmp)
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <sys/types.h>
#include <utmp.h>]], [[struct utmp foo; return (int)foo.ut_name[0];]])],[AC_DEFINE(HAVE_UT_NAME) AC_MSG_RESULT([yes])],[AC_MSG_RESULT([no])])
AC_MSG_CHECKING(for ut_host in struct utmp)
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <sys/types.h>
#include <utmp.h>]], [[struct utmp foo; return (int)foo.ut_host[0];]])],[AC_DEFINE(HAVE_UT_HOST) AC_MSG_RESULT([yes])],[AC_MSG_RESULT([no])])
AC_MSG_CHECKING(for ut_id in struct utmp)
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <sys/types.h>
#include <utmp.h>]], [[struct utmp foo; return (int)foo.ut_id[0];]])],[AC_DEFINE(HAVE_UT_ID) AC_MSG_RESULT([yes])],[AC_MSG_RESULT([no])])
AC_MSG_CHECKING(for ut_syslen in struct utmpx)
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <sys/types.h>
#include <utmpx.h>]], [[struct utmpx foo; return (int)foo.ut_syslen;]])],[AC_DEFINE(HAVE_UTX_SYSLEN) AC_MSG_RESULT([yes])],[AC_MSG_RESULT([no])])

dnl# Checks for library functions.
dnl# begin what used to be AC\_TYPE\_SIGNAL
AC_CACHE_CHECK([return type of signal handlers],[ac_cv_type_signal],[AC_COMPILE_IFELSE(
[AC_LANG_PROGRAM([#include <sys/types.h>
#include <signal.h>
],
		 [return *(signal (0, 0)) (0) == 1;])],
		   [ac_cv_type_signal=int],
		   [ac_cv_type_signal=void])])
AC_DEFINE_UNQUOTED([RETSIGTYPE],[${ac_cv_type_signal}],
		   [Define as the return type of signal handlers
		    (`int' or `void').])
dnl# end of what used to be AC\_TYPE\_SIGNAL
AC_FUNC_CHOWN
AC_FUNC_FORK
AC_FUNC_LSTAT dnl# also checks whether it "_FOLLOWS_SLASHED_SYMLINK"
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([alarm atexit dup2 endgrent endpwent endspent fpurge ftruncate \
                getcwd getgroups gethostbyaddr gethostbyname getspnam \
                gettimeofday getttynam getusershell getutxline inet_ntoa \
                memset mkdir pututxline rmdir select setenv setgroups \
                setlogin setpriority setvbuf socket strchr strdup strerror \
                strftime strncasecmp strpbrk strrchr strtoul strstr uname \
                usleep])

dnl# Libmissing...
AC_FUNC_MEMCMP
AC_FUNC_ALLOCA
AC_REPLACE_FUNCS([getusershell sigaddset sigemptyset strerror strncasecmp])
MISSING="$LIBOBJS $ALLOCA " ;

dnl These should be simplified by a macro
AC_CHECK_FUNC([atexit],      AC_DEFINE([HAVE_ATEXIT]),      MISSING="${MISSING}atexit.o "; AC_CHECK_FUNCS(on_exit))
AC_CHECK_FUNC([endutent],    AC_DEFINE([HAVE_ENDUTENT]),    MISSING="${MISSING}endutent.o ")
AC_CHECK_FUNC([initgroups],  AC_DEFINE([HAVE_INITGROUPS]),  MISSING="${MISSING}initgroups.o ")
AC_CHECK_FUNC([memcmp],      AC_DEFINE([HAVE_MEMCMP]),      MISSING="${MISSING}memcmp.o ")
AC_CHECK_FUNC([memcpy],      AC_DEFINE([HAVE_MEMCPY]),      MISSING="${MISSING}memcpy.o "; AC_CHECK_FUNCS(bcopy))
AC_CHECK_FUNC([memset],      AC_DEFINE([HAVE_MEMSET]),      MISSING="${MISSING}memset.o "; AC_CHECK_FUNCS(bzero))
AC_CHECK_FUNC([getcwd],      AC_DEFINE([HAVE_GETCWD]),      MISSING="${MISSING}getcwd.o "; AC_CHECK_FUNCS(getwd))
AC_CHECK_FUNC([getenv],      AC_DEFINE([HAVE_GETENV]),      MISSING="${MISSING}env.o ")
AC_CHECK_FUNC([getutline],   AC_DEFINE([HAVE_GETUTLINE]),   MISSING="${MISSING}getutline.o "; AC_CHECK_FUNCS(ttyslot))
AC_CHECK_FUNC([pututline],   AC_DEFINE([HAVE_PUTUTLINE]),   MISSING="${MISSING}pututline.o "; AC_CHECK_FUNCS(ttyslot))
AC_CHECK_FUNC([setenv],      AC_DEFINE([HAVE_SETENV]),      MISSING="${MISSING}env.o ")
AC_CHECK_FUNC([setegid],     AC_DEFINE([HAVE_SETEGID]),     MISSING="${MISSING}setegid.o "; AC_CHECK_FUNCS(setregid setresgid))
AC_CHECK_FUNC([seteuid],     AC_DEFINE([HAVE_SETEUID]),     MISSING="${MISSING}seteuid.o "; AC_CHECK_FUNCS(setreuid setresuid))
AC_CHECK_FUNC([setutent],    AC_DEFINE([HAVE_SETUTENT]),    MISSING="${MISSING}setutent.o ")
AC_CHECK_FUNC([sigprocmask], AC_DEFINE([HAVE_SIGPROCMASK]), MISSING="${MISSING}sigprocmask.o "; AC_CHECK_FUNCS(sigblock sigsetmask))
AC_CHECK_FUNC([strchr],      AC_DEFINE([HAVE_STRCHR]),      MISSING="${MISSING}strchr.o "; AC_CHECK_FUNCS(index))
AC_CHECK_FUNC([strrchr],     AC_DEFINE([HAVE_STRRCHR]),     MISSING="${MISSING}strrchr.o "; AC_CHECK_FUNCS(rindex))
AC_CHECK_FUNC([strtoul],     AC_DEFINE([HAVE_STRTOUL]),     MISSING="${MISSING}strtoul.o ")
AC_CHECK_FUNC([sysconf],     AC_DEFINE([HAVE_SYSCONF]),     MISSING="${MISSING}sysconf.o "; AC_CHECK_FUNCS(getdtablesize))
AC_CHECK_FUNC([uname],       AC_DEFINE([HAVE_UNAME]),       MISSING="${MISSING}uname.o "; AC_CHECK_FUNCS(gethostname))
AC_CHECK_FUNC([unsetenv],    AC_DEFINE([HAVE_UNSETENV]),    MISSING="${MISSING}env.o ")
AC_SUBST([MISSING])dnl

dnl# (removed checks for nonstandard gettimeofday because autotools were choking on them)

# Munge out LOCALBIN and LOCALMAN in canonical (no bletch) form
AC_MSG_NOTICE([doing final output now])
if test -n "${DISPLAY}"; then unset DISPLAY; fi
if test -n "${EDITOR}"; then unset EDITOR; fi
AC_CONFIG_FILES([configure.munger libmissing/Makefile libopie/Makefile \
                 Makefile.munge:Makefile.in])
AC_OUTPUT
sleep 1
echo "done with this script; now attempting to run configure.munger"
(test -x ./configure.munger && test -n "${BASHDB}" && test -x "${BASHDB}" && ${BASHDB} ./configure.munger) || sh configure.munger
