dnl#
dnl# RCSid:
dnl#	$Id: configure.ac,v 1.45 2012/06/20 22:43:41 sjg Exp $
dnl#
dnl# Process this file with autoconf to produce a configure script
dnl#
AC_PREREQ([2.70])
AC_INIT([bmake],[20120620],[sjg@NetBSD.org])
AC_CONFIG_SRCDIR([arch.c])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([foreign])
AM_MAINTAINER_MODE
AM_SANITY_CHECK

dnl#
AC_ARG_WITH([defshell],
[AS_HELP_STRING([--with-defshell=SHELL],[use SHELL by default - must be sh compatible, use sh or ksh to pick the internal definitions])],
[case "${withval}" in
yes)   AC_MSG_ERROR(bad value ${withval} given for bmake DEFSHELL) ;;
no)    ;;
*)     case "$with_defshell" in
       sh)  DEFSHELL_INDEX=DEFSHELL_INDEX_SH;;	# it's the default anyway
       ksh) DEFSHELL_INDEX=DEFSHELL_INDEX_KSH;;
       csh) DEFSHELL_INDEX=DEFSHELL_INDEX_CSH;;	# kidding right?
       *)   defshell_path=$with_defshell;;	# better be sh compatible!
       esac
       ;;
       esac])
dnl#
use_meta=yes
AC_ARG_WITH([meta],
[AS_HELP_STRING([--without-meta],[disable use of meta-mode])],
[case "${withval}" in
yes|no) use_meta=${withval};;
*) AC_MSG_ERROR([bad value ${withval} given for meta]) ;;
esac])
dnl#
AC_ARG_WITH([filemon],
[AS_HELP_STRING([--with-filemon=path/filemon.h],
                [indicate path to filemon.h for meta-mode])],
[case "/${withval}" in
/no|*/filemon.h) filemon_h="${withval}";;
*/filemon*) filemon_h="${withval}/filemon.h";;
*) AC_MSG_ERROR([bad value ${withval} given for filemon]) ;;
esac],
[
OS=`uname -s`
for d in "/usr/include/dev/filemon" "${prefix}/include/dev/filemon" "${srcdir}/filemon" "${srcdir}/../filemon" "${srcdir}/../../sys/dev/filemon"
do
	for x in "/${OS}" ""
	do
		filemon_h="${d}${x}/filemon.h"
		test -s "${filemon_h}" && break
	done
	test -s "${filemon_h}" && break
done
test -s "${filemon_h:-/dev/null}" || filemon_h=no
])
dnl# echo "Note: use_meta=${use_meta} filemon_h=${filemon_h}" >&6
case "${use_meta}" in
yes)
	case "${filemon_h}" in
	*.h) echo "Using: filemon=${filemon_h}" >&6;;
	esac
	;;
esac
dnl#
dnl# Check for OS problems
dnl# Solaris's signal.h only privides sigset_t etc if one of
dnl# _EXTENSIONS_ _POSIX_C_SOURCE or _XOPEN_SOURCE are defined.
dnl# The later two seem to cause more problems than they solve so if we
dnl# see _EXTENSIONS_ we use it.
AC_USE_SYSTEM_EXTENSIONS

dnl# Checks for programs.
AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_GCC_TRADITIONAL
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AC_PROG_LN_S
dnl# AX_* macros require the autoconf-archive package
AX_CHECK_GNU_MAKE
AC_PATH_PROG([BSDMAKE],[bsdmake])
AC_PATH_PROG([BMAKE],[bmake])dnl

dnl# Executable suffix - normally empty; .exe on os2.
AC_EXEEXT
AC_SUBST([ac_exe_suffix])dnl

dnl#
dnl# Check if /bin/sh will pass .MAKE.LEVEL
echo ${ECHO_N} "checking if sh will pass .MAKE. variables... ${ECHO_C}" >&6
ok=`env .MAKE.LEVEL=1 /bin/sh -c env | grep LEVEL=`
case "${ok}" in
"") echo "no" >&6; CPPFLAGS="${CPPFLAGS} -DNEED_MAKE_LEVEL_SAFE";;
*) echo "yes" >&6;;
esac

dnl#
dnl# AC\_C\_CROSS would have gone here
dnl#

dnl# Checks for header files.
dnl# autoupdate says:
dnl# The preprocessor macro `STDC_HEADERS' is obsolete.
dnl# Except in unusual embedded environments, you can safely include all
dnl# ISO C90 headers unconditionally.
# Autoupdate added the next few lines to ensure that your configure
# script's behavior did not change.  They are probably safe to remove.
AC_CHECK_INCLUDES_DEFAULT
if test "x${EGREP}" = "x"; then
  test -z "${EGREP}"
  AC_PROG_EGREP
fi
AC_HEADER_SYS_WAIT
AC_HEADER_DIRENT
dnl# Keep this list sorted:
AC_CHECK_HEADERS([ \
	ar.h \
	err.h \
	fcntl.h \
	inttypes.h \
	limits.h \
	paths.h \
	poll.h \
	ranlib.h \
	stddef.h \
	sdlib.h \
	string.h \
	strings.h \
	sys/file.h \
	sys/ioctl.h \
	sys/mman.h \
	sys/param.h \
	sys/select.h \
	sys/socket.h \
	sys/time.h \
	sys/uio.h \
	unistd.h \
	utime.h \
	])dnl

dnl# Both *BSD and Linux have sys/cdefs.h, most do not.
dnl# If it is missing, we add -I${srcdir}/missing to CFLAGS
dnl# also if sys/cdefs.h does not have __RCSID we need to use ours
dnl# but we need to include the host's one too *sigh*
AC_CHECK_HEADER([sys/cdefs.h],
[echo ${ECHO_N} "checking whether sys/cdefs.h is compatible... ${ECHO_C}" >&6
AC_EGREP_CPP([yes_this_is_compatible],
	[#include <sys/cdefs.h>
	#ifdef __RCSID
	yes_this_is_compatible
	#endif
	],
[echo "yes" >&6],
[echo "no" >&6; CPPFLAGS="${CPPFLAGS} -I`cd ${srcdir}/missing && pwd` -DNEED_HOST_CDEFS_H"])],
[CPPFLAGS="${CPPFLAGS} -I`cd ${srcdir}/missing && pwd`"])dnl

dnl# Checks for typedefs, structures, and compiler characteristics.
dnl# AX_* macros require the autoconf-archive package
AX_C___ATTRIBUTE__
AC_C_BIGENDIAN
AC_C_CONST
AC_TYPE_OFF_T
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_UINT32_T
AC_CHECK_DECLS([sys_siglist])
if test "x${ac_cv_have_decl_sys_siglist}" != "xyes"; then
  test -n "${ac_cv_have_decl_sys_siglist}" && unset ac_cv_have_decl_sys_siglist
  AC_CHECK_DECLS([sys_siglist],[],[],[#include <signal.h>
/* NetBSD declares sys_siglist in unistd.h.  */
#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif
])
fi
AC_CHECK_HEADERS_ONCE([sys/time.h])
if test "x${ac_cv_header_sys_time_h}" = "xyes"; then
  AC_DEFINE([TIME_WITH_SYS_TIME],[1],[Define to 1 if you can safely include
	     both <sys/time.h> and <time.h>.  This macro is obsolete.])
fi
AC_STRUCT_TM

dnl# Checks for library functions.
AC_FUNC_LSTAT_FOLLOWS_SLASHED_SYMLINK
AC_FUNC_MALLOC
AC_FUNC_MMAP
AC_FUNC_REALLOC
AC_FUNC_STRTOD
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
dnl# end what used to be AC\_TYPE\_SIGNAL
AC_FUNC_FORK
AC_FUNC_VPRINTF
AC_FUNC_WAIT3
dnl# Keep this list sorted:
AC_CHECK_FUNCS([ \
	dup2 \
	err \
	errx \
	getcwd \
	getenv \
	getopt \
	gettimeofday \
	getwd \
	killpg \
	lstat \
	memset \
	mmap \
	munmap \
	putenv \
	realpath \
	regcomp \
	select \
	setenv \
	setpgid \
	setsid \
	sigaction \
	sigvec \
	snprintf \
	strchr \
	strcspn \
	strerror \
	strftime \
	strrchr \
	strsep \
	strspn \
	strstr \
	strtod \
	strtol \
	strtoul \
	uname \
	unsetenv \
	utime \
	vsnprintf \
	wait3 \
	wait4 \
	waitpid \
	warn \
	warnx \
	])dnl

dnl# functions which we may need to provide:
AC_REPLACE_FUNCS([ \
	realpath \
	dirname \
	stresep \
	strlcpy \
	])dnl

AC_CHECK_LIB([util], [emalloc],
    [AC_CHECK_LIB([util],[erealloc],
      [AC_CHECK_LIB([util],[estrdup],
        [AC_CHECK_LIB([util],[estrndup],
	  [LIBS="${LIBS} -lutil"
	   CPPFLAGS="${CPPFLAGS} -DUSE_EMALLOC"])])])])dnl

dnl#
dnl# Structures
dnl#
AC_HEADER_STAT
AC_CHECK_MEMBERS([struct stat.st_rdev],[AC_DEFINE([HAVE_ST_RDEV],[1],
			    [Define to 1 if your `struct stat' has `st_rdev'.
			     Deprecated, use `HAVE_STRUCT_STAT_ST_RDEV'
			     instead.])])

dnl#
dnl# we want this for unit-tests/Makefile
echo ${ECHO_N} "checking if diff -u works... ${ECHO_C}" >&6
if diff -u /dev/null /dev/null > /dev/null 2>&1; then
   diff_u="-u"
   echo "yes" >&6
else
   diff_u=""
   echo "no" >&6
fi
dnl#
dnl# AC_* don't quite cut it on their own here.
dnl#
AC_CANONICAL_HOST
echo "checking for MACHINE & MACHINE_ARCH..." >&6
cat > conftest.$ac_ext <<EOF
#include "confdefs.h"
#include <sys/param.h>
#ifdef MACHINE
machine=MACHINE
#endif /* MACHINE */
#ifdef MACHINE_ARCH
machine_arch=MACHINE_ARCH
#endif /* MACHINE_ARCH */
EOF

default_machine=`(eval "${ac_cpp} conftest.${ac_ext}") 2>&5 | 
	egrep machine= | tr -d ' "'`
rm -rf conftest*
if test "${default_machine}"; then
	eval "$default_machine"
fi
machine=${machine:-`${srcdir}/machine.sh`}
machine_arch=${machine_arch:-`${srcdir}/machine.sh arch`}
echo "defaults: MACHINE=${machine}, MACHINE_ARCH=${machine_arch}" 1>&6
dnl#
dnl# now allow overrides
dnl#
AC_ARG_WITH([machine],
[AS_HELP_STRING([--with-machine=MACHINE],[explicitly set MACHINE])],
[case "${withval}" in
yes)   AC_MSG_ERROR([bad value ${withval} given for bmake MACHINE]) ;;
no)    ;;
generic) machine=`${srcdir}/machine.sh`;;
*)     machine=${with_machine};;
esac])
force_machine=""
AC_ARG_WITH([force_machine],
[AS_HELP_STRING([--with-force-machine=MACHINE],[set FORCE_MACHINE])],
[case "${withval}" in
yes)   force_machine=FORCE_;;
no)    ;;
*)     force_machine=FORCE_; machine=${with_force_machine};;
esac])
dnl#
force_machine_arch=""
AC_ARG_WITH([force_machine_arch],
[AS_HELP_STRING([--with-force-machine-arch=MACHINE],[set FORCE_MACHINE_ARCH])],
[case "${withval}" in
yes)   force_machine_arch=FORCE_;;
no)    ;;
*)     force_machine_arch=FORCE_; machine_arch=${with_force_machine};;
esac])
dnl#
AC_ARG_WITH([machine_arch],
[AS_HELP_STRING([--with-machine_arch=MACHINE_ARCH],
                [explicitly set MACHINE_ARCH])],
[case "${withval}" in
yes)   AC_MSG_ERROR([bad value ${withval} given for bmake MACHINE_ARCH]) ;;
no)    ;;
*)     machine_arch=${with_machine_arch};;
esac])
dnl#
dnl# Tell them what we ended up with
dnl#
echo "Using: ${force_machine}MACHINE=${machine}, MACHINE_ARCH=${machine_arch}" 1>&6
dnl#
dnl# Allow folk to control _PATH_DEFSYSPATH
dnl#
default_sys_path=\${prefix}/share/mk
AC_ARG_WITH([default-sys-path],
[AS_HELP_STRING([--with-default-sys-path=PATH:DIR:LIST],
       [use an explicit _PATH_DEFSYSPATH
	MAKESYSPATH is a ':' separated list of directories 
	that bmake will search for system .mk files. 
	_PATH_DEFSYSPATH is its default value.])],
[case "${withval}" in
yes)	AC_MSG_ERROR([bad value ${withval} given for bmake _PATH_DEFSYSPATH])
        ;;
no)	;;
*)	default_sys_path="${with_default_sys_path}"
	;;
esac])
dnl#
dnl# Some folk don't like this one
dnl#
AC_ARG_WITH([path-objdirprefix],
[AS_HELP_STRING([--with-path-objdirprefix=PATH],
                [override _PATH_OBJDIRPREFIX])],
[case "${withval}" in
yes) AC_MSG_ERROR([bad value ${withval} given for bmake _PATH_OBJDIRPREFIX]) ;;
no)    CPPFLAGS="${CPPFLAGS} -DNO_PATH_OBJDIRPREFIX" ;;
*)     CPPFLAGS="${CPPFLAGS} \"-D_PATH_OBJDIRPREFIX=\\\"${with_path-objdir}\\\"\"" ;;
esac])
dnl#
dnl# And this can be handy to do with out.
dnl#
AC_ARG_ENABLE([pwd-override],
[AS_HELP_STRING([--disable-pwd-override],[disable \$PWD overriding getcwd()])],
[case "${enableval}" in
yes)   ;;
no)    CPPFLAGS="${CPPFLAGS} -DNO_PWD_OVERRIDE" ;;
*)     AC_MSG_ERROR([bad value ${enableval} given for pwd-override option]) ;;
esac])
dnl#
dnl# Just for grins
dnl#
AC_ARG_ENABLE([check-make-chdir],
[AS_HELP_STRING([--disable-check-make-chdir],[disable make trying to guess 
	when it should automatically cd \${.CURDIR}])],
[case "${enableval}" in
yes)   ;;
no)    CPPFLAGS="${CPPFLAGS} -DNO_CHECK_MAKE_CHDIR" ;;
*)     AC_MSG_ERROR([bad value ${enableval} given for check-make-chdir option])
       ;;
esac])
dnl#
dnl# On non-BSD systems, bootstrap won't work without mk
dnl#
AC_ARG_WITH([mksrc],
[AS_HELP_STRING([--with-mksrc=PATH],[
                tell makefile.boot where to find mk src])],
[case "${withval}" in
""|yes|no) ;;
*) test -s ${withval}/install-mk && mksrc=${withval} ||
AC_MSG_ERROR([bad value ${withval} given for mksrc cannot find install-mk])
;;
esac
])
dnl#
dnl# Now make sure we have a value
dnl#
srcdir=`cd ${srcdir} && pwd`
for mksrc in ${mksrc} ${srcdir}/mk ${srcdir}/../mk mk
do
	test -s ${mksrc}/install-mk || continue
	mksrc=`cd ${mksrc} && pwd`
	break
done
mksrc=`echo ${mksrc} | sed "s,$srcdir,\\\${srcdir},"`
echo "Using: MKSRC=${mksrc}" 1>&6
dnl# On some systems we want a different default shell by default:
if test -x /usr/xpg4/bin/sh; then
        defshell_path=${defshell_path:-/usr/xpg4/bin/sh}
fi
if test -n "${defshell_path}"; then
	echo "Using: SHELL=${defshell_path}"  >&6
	AC_DEFINE_UNQUOTED([DEFSHELL_CUSTOM],["${defshell_path}"],
                           [Path of default shell])
fi
if test -n "${DEFSHELL_INDEX}"; then
       AC_DEFINE_UNQUOTED([DEFSHELL_INDEX],[${DEFSHELL_INDEX}],
                          [Shell spec to use by default])
fi        
dnl#
AC_SUBST([machine])dnl
AC_SUBST([force_machine])dnl
AC_SUBST([machine_arch])dnl
AC_SUBST([mksrc])dnl
AC_SUBST([default_sys_path])dnl
AC_SUBST([INSTALL])dnl
AC_SUBST([GCC])dnl
AC_SUBST([diff_u])dnl
AC_SUBST([use_meta])dnl
AC_SUBST([filemon_h])dnl

dnl# Output.
AC_CONFIG_FILES([Makefile make-bootstrap.sh build-aux/Makefile])
AC_OUTPUT

cat <<EOF

You can now run

	sh ./make-bootstrap.sh

to produce a fully functional bmake.

EOF
