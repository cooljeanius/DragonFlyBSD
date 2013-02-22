#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([mtree])
AC_CONFIG_SRCDIR([compare.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PATH_PROG([BSDMAKE], [bsdmake])
AC_PATH_PROG([BMAKE], [bmake])
AC_PATH_PROG([MTREE], [mtree], [], [$PATH:/usr/sbin])
if test "x$BSDMAKE" = "x"; then
    AC_MSG_ERROR([bsdmake not found])
fi

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lmd':
AC_CHECK_LIB([md], [main])
# FIXME: Replace `main' with a function in `-lcrypto':
AC_CHECK_LIB([crypto], [main])

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([err.h errno.h fcntl.h fts.h md5.h openssl/md5.h sha.h openssl/sha.h ripemd.h openssl/ripemd.h stdint.h stdio.h stdlib.h string.h sys/param.h sys/stat.h sys/time.h time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_UID_T
AC_TYPE_MODE_T
AC_TYPE_OFF_T
AC_TYPE_SIZE_T
AC_CHECK_TYPES([intmax_t])
AC_CHECK_TYPES([uintmax_t])
AC_CHECK_TYPES([uintptr_t])
# The following is from m4/visibility.m4, which is originally from gettext
gl_VISIBILITY

AC_ARG_ENABLE(werror,
  AS_HELP_STRING([--enable-werror], [treat compile warnings as errors]),
  [case "${enableval}" in
     yes | y) ERROR_ON_WARNING="yes" ;;
     no | n)  ERROR_ON_WARNING="no" ;;
     *) AC_MSG_ERROR(bad value ${enableval} for --enable-werror) ;;
   esac])

WERROR_CFLAGS=""
if test "${ERROR_ON_WARNING}" = yes ; then
    WERROR_CFLAGS="-Werror"
fi
WARN_CFLAGS=""
if test "x${build_warnings}" != x -a "x$GCC" = xyes
then
    AC_MSG_CHECKING(compiler warning flags)
    # Separate out the -Werror flag as some files just cannot be
    # compiled with it enabled.
    for w in ${build_warnings}; do
	case $w in
	-Werr*) WERROR_CFLAGS=-Werror ;;
	*) # Check that GCC accepts it
	    saved_CFLAGS="$CFLAGS"
	    CFLAGS="$CFLAGS $w"
	    AC_TRY_COMPILE([],[],WARN_CFLAGS="${WARN_CFLAGS} $w",)
	    CFLAGS="$saved_CFLAGS"
	esac
    done
    AC_MSG_RESULT(${WARN_CFLAGS} ${WERROR_CFLAGS})
fi
AC_SUBST(WARN_CFLAGS)
AC_SUBST(WERROR_CFLAGS)

# Checks for library functions.
AC_FUNC_CHOWN
AC_FUNC_MALLOC
AC_CHECK_FUNCS([bzero getcwd gethostname getwd lchown mkdir strchr strdup strerror strpbrk strtol strtoul])

AC_OUTPUT
