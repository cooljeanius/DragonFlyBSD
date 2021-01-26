#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.70])
AC_INIT([smbfs],[1.4],[bp@freebsd.org])
AC_CONFIG_SRCDIR([include/cflib.h])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_HEADERS([config.h])dnl

# Checks for programs.
AC_PROG_CC
AC_PROG_MAKE_SET
AC_PATH_PROG([BSDMAKE],[bsdmake])
AC_PATH_PROG([BMAKE],[bmake])dnl

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lsmb':
AC_CHECK_LIB([smb],[main])dnl

# Checks for header files.
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
AC_CHECK_HEADERS([arpa/inet.h fcntl.h locale.h mach/mach.h netdb.h \
                  netinet/in.h stdlib.h string.h strings.h sys/ioctl.h \
                  sys/mount.h sys/param.h sys/socket.h sys/time.h unistd.h])dnl

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_UID_T
AC_TYPE_INT64_T
AC_TYPE_OFF_T
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_FORK
AC_FUNC_MALLOC
AC_CHECK_FUNCS([bzero endpwent gethostbyname gethostname getpass inet_ntoa isascii memset realpath select setlocale socket strcasecmp strchr strdup strerror strncasecmp strtol strtoul])

# Output.
AC_CONFIG_FILES([config.mk])
AC_OUTPUT
