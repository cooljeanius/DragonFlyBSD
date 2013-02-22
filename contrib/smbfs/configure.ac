#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([smbfs], [1.4], [bp@freebsd.org])
AC_CONFIG_SRCDIR([include/cflib.h])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_MAKE_SET
AC_PATH_PROG([BSDMAKE], [bsdmake])
AC_PATH_PROG([BMAKE], [bmake])

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lsmb':
AC_CHECK_LIB([smb], [main])

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([arpa/inet.h fcntl.h locale.h mach/mach.h netdb.h netinet/in.h stdlib.h string.h strings.h sys/ioctl.h sys/mount.h sys/param.h sys/socket.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_UID_T
AC_TYPE_INT64_T
AC_TYPE_OFF_T
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_FORK
AC_FUNC_MALLOC
AC_CHECK_FUNCS([bzero endpwent gethostbyname gethostname getpass inet_ntoa isascii memset realpath select setlocale socket strcasecmp strchr strdup strerror strncasecmp strtol strtoul])

AC_CONFIG_FILES([config.mk])
AC_OUTPUT
