dnl# configure.ac                                  -*- Autoconf -*-
dnl# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.70])
AC_INIT([Dragonfly-BSD],[VERSION],[BUG-REPORT-ADDRESS])
AC_CONFIG_SRCDIR([bin/cat/cat.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AC_CANONICAL_HOST
AC_CANONICAL_TARGET
AC_USE_SYSTEM_EXTENSIONS
AM_INIT_AUTOMAKE([foreign])
AM_MAINTAINER_MODE
AM_SANITY_CHECK
AC_SEARCH_LIBS([strerror],[cposix])
AM_SET_LEADING_DOT
AC_EXEEXT

# Checks for programs.
AC_PROG_CXX
AC_PROG_AWK
AC_PROG_YACC
AC_PROG_CC
AC_PROG_CPP
AC_PROG_LEX
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
# AX_* macros require the autoconf-archive package
AX_CHECK_GNU_MAKE
AC_PATH_PROG([BSDMAKE],[bsdmake])
AC_PATH_PROG([BMAKE],[bmake])
AC_PROG_OBJC
AC_PROG_RANLIB

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lalias':
AC_CHECK_LIB([alias],[main])
# FIXME: Replace `main' with a function in `-larchive':
AC_CHECK_LIB([archive],[main])
# FIXME: Replace `main' with a function in `-latm':
AC_CHECK_LIB([atm],[main])
# FIXME: Replace `main' with a function in `-lbfd':
AC_CHECK_LIB([bfd],[main])
# FIXME: Replace `main' with a function in `-lbluetooth':
AC_CHECK_LIB([bluetooth],[main])
# FIXME: Replace `main' with a function in `-lbsdxml':
AC_CHECK_LIB([bsdxml],[main])
# FIXME: Replace `main' with a function in `-lbz2':
AC_CHECK_LIB([bz2],[main])
# FIXME: Replace `main' with a function in `-lc':
AC_CHECK_LIB([c],[main])
# FIXME: Replace `main' with a function in `-lc_r':
AC_CHECK_LIB([c_r],[main])
# FIXME: Replace `main' with a function in `-lc_rtld_pic':
AC_CHECK_LIB([c_rtld_pic],[main])
# FIXME: Replace `main' with a function in `-lc_s':
AC_CHECK_LIB([c_s],[main])
# FIXME: Replace `main' with a function in `-lcalendar':
AC_CHECK_LIB([calendar],[main])
# FIXME: Replace `main' with a function in `-lcam':
AC_CHECK_LIB([cam],[main])
# FIXME: Replace `main' with a function in `-lcompat':
AC_CHECK_LIB([compat],[main])
# FIXME: Replace `main' with a function in `-lcrypt':
AC_CHECK_LIB([crypt],[main])
# FIXME: Replace `main' with a function in `-lcrypto':
AC_CHECK_LIB([crypto],[main])
# FIXME: Replace `main' with a function in `-lcryptsetup':
AC_CHECK_LIB([cryptsetup],[main])
# FIXME: Replace `main' with a function in `-lcsh':
AC_CHECK_LIB([csh],[main])
# FIXME: Replace `main' with a function in `-lcurses':
AC_CHECK_LIB([curses],[main])
# FIXME: Replace `main' with a function in `-ld':
AC_CHECK_LIB([d],[main])
# FIXME: Replace `main' with a function in `-ldecnumber':
AC_CHECK_LIB([decnumber],[main])
# FIXME: Replace `main' with a function in `-ldevattr':
AC_CHECK_LIB([devattr],[main])
# FIXME: Replace `main' with a function in `-ldevinfo':
AC_CHECK_LIB([devinfo],[main])
# FIXME: Replace `main' with a function in `-ldevmapper':
AC_CHECK_LIB([devmapper],[main])
# FIXME: Replace `main' with a function in `-ldevstat':
AC_CHECK_LIB([devstat],[main])
# FIXME: Replace `main' with a function in `-ldialog':
AC_CHECK_LIB([dialog],[main])
# FIXME: Replace `main' with a function in `-ldm':
AC_CHECK_LIB([dm],[main])
# FIXME: Replace `main' with a function in `-ldmsg':
AC_CHECK_LIB([dmsg],[main])
# FIXME: Replace `main' with a function in `-ledit':
AC_CHECK_LIB([edit],[main])
# FIXME: Replace `main' with a function in `-levtr':
AC_CHECK_LIB([evtr],[main])
# FIXME: Replace `main' with a function in `-lfetch':
AC_CHECK_LIB([fetch],[main])
# FIXME: Replace `main' with a function in `-lfsid':
AC_CHECK_LIB([fsid],[main])
# FIXME: Replace `main' with a function in `-lgdb':
AC_CHECK_LIB([gdb],[main])
# FIXME: Replace `main' with a function in `-lgen':
AC_CHECK_LIB([gen],[main])
# FIXME: Replace `main' with a function in `-lhammer':
AC_CHECK_LIB([hammer],[main])
# FIXME: Replace `main' with a function in `-liberty':
AC_CHECK_LIB([iberty],[main])
# FIXME: Replace `main' with a function in `-linet':
AC_CHECK_LIB([inet],[main])
# FIXME: Replace `main' with a function in `-lipsec':
AC_CHECK_LIB([ipsec],[main])
# FIXME: Replace `main' with a function in `-lipx':
AC_CHECK_LIB([ipx],[main])
# FIXME: Replace `main' with a function in `-lkcore':
AC_CHECK_LIB([kcore],[main])
# FIXME: Replace `main' with a function in `-lkernel32':
AC_CHECK_LIB([kernel32],[main])
# FIXME: Replace `main' with a function in `-lkiconv':
AC_CHECK_LIB([kiconv],[main])
# FIXME: Replace `main' with a function in `-lkinfo':
AC_CHECK_LIB([kinfo],[main])
# FIXME: Replace `main' with a function in `-lkvm':
AC_CHECK_LIB([kvm],[main])
# FIXME: Replace `main' with a function in `-ll':
AC_CHECK_LIB([l],[main])
# FIXME: Replace `main' with a function in `-lldns':
AC_CHECK_LIB([ldns],[main])
# FIXME: Replace `main' with a function in `-lluks':
AC_CHECK_LIB([luks],[main])
# FIXME: Replace `main' with a function in `-llvm':
AC_CHECK_LIB([lvm],[main])
# FIXME: Replace `main' with a function in `-llzma':
AC_CHECK_LIB([lzma],[main])
# FIXME: Replace `main' with a function in `-lm':
AC_CHECK_LIB([m],[main])
# FIXME: Replace `main' with a function in `-lmagic':
AC_CHECK_LIB([magic],[main])
# FIXME: Replace `main' with a function in `-lmd':
AC_CHECK_LIB([md],[main])
# FIXME: Replace `main' with a function in `-lncp':
AC_CHECK_LIB([ncp],[main])
# FIXME: Replace `main' with a function in `-lncurses':
AC_CHECK_LIB([ncurses],[main])
# FIXME: Replace `main' with a function in `-lncursesw':
AC_CHECK_LIB([ncursesw],[main])
# FIXME: Replace `main' with a function in `-lnet':
AC_CHECK_LIB([net],[main])
# FIXME: Replace `main' with a function in `-lnetgraph':
AC_CHECK_LIB([netgraph],[main])
# FIXME: Replace `main' with a function in `-lnsl':
AC_CHECK_LIB([nsl],[main])
# FIXME: Replace `main' with a function in `-lnsl_s':
AC_CHECK_LIB([nsl_s],[main])
# FIXME: Replace `main' with a function in `-lopcodes':
AC_CHECK_LIB([opcodes],[main])
# FIXME: Replace `main' with a function in `-lopie':
AC_CHECK_LIB([opie],[main])
# FIXME: Replace `main' with a function in `-lpam':
AC_CHECK_LIB([pam],[main])
# FIXME: Replace `main' with a function in `-lpanel':
AC_CHECK_LIB([panel],[main])
# FIXME: Replace `main' with a function in `-lpcap':
AC_CHECK_LIB([pcap],[main])
# FIXME: Replace `main' with a function in `-lplot':
AC_CHECK_LIB([plot],[main])
# FIXME: Replace `main' with a function in `-lprop':
AC_CHECK_LIB([prop],[main])
# FIXME: Replace `main' with a function in `-lpthread':
AC_CHECK_LIB([pthread],[main])
# FIXME: Replace `main' with a function in `-lpuffs':
AC_CHECK_LIB([puffs],[main])
# FIXME: Replace `main' with a function in `-lradius':
AC_CHECK_LIB([radius],[main])
# FIXME: Replace `main' with a function in `-lreadline':
AC_CHECK_LIB([readline],[main])
# FIXME: Replace `main' with a function in `-lresolv':
AC_CHECK_LIB([resolv],[main])
# FIXME: Replace `main' with a function in `-lrpc':
AC_CHECK_LIB([rpc],[main])
# FIXME: Replace `main' with a function in `-lrpclib':
AC_CHECK_LIB([rpclib],[main])
# FIXME: Replace `main' with a function in `-lrpcsvc':
AC_CHECK_LIB([rpcsvc],[main])
# FIXME: Replace `main' with a function in `-lrt':
AC_CHECK_LIB([rt],[main])
# FIXME: Replace `main' with a function in `-lsbuf':
AC_CHECK_LIB([sbuf],[main])
# FIXME: Replace `main' with a function in `-lsdp':
AC_CHECK_LIB([sdp],[main])
# FIXME: Replace `main' with a function in `-lsmb':
AC_CHECK_LIB([smb],[main])
# FIXME: Replace `main' with a function in `-lsocket':
AC_CHECK_LIB([socket],[main])
# FIXME: Replace `main' with a function in `-lsocks':
AC_CHECK_LIB([socks],[main])
# FIXME: Replace `main' with a function in `-lssh':
AC_CHECK_LIB([ssh],[main])
# FIXME: Replace `main' with a function in `-lssl':
AC_CHECK_LIB([ssl],[main])
# FIXME: Replace `main' with a function in `-lstand':
AC_CHECK_LIB([stand],[main])
# FIXME: Replace `main' with a function in `-lsun':
AC_CHECK_LIB([sun],[main])
# FIXME: Replace `main' with a function in `-ltacplus':
AC_CHECK_LIB([tacplus],[main])
# FIXME: Replace `main' with a function in `-ltcplay':
AC_CHECK_LIB([tcplay],[main])
# FIXME: Replace `main' with a function in `-ltermcap':
AC_CHECK_LIB([termcap],[main])
# FIXME: Replace `main' with a function in `-lulsock':
AC_CHECK_LIB([ulsock],[main])
# FIXME: Replace `main' with a function in `-lusb':
AC_CHECK_LIB([usb],[main])
# FIXME: Replace `main' with a function in `-lusbhid':
AC_CHECK_LIB([usbhid],[main])
# FIXME: Replace `main' with a function in `-lutil':
AC_CHECK_LIB([util],[main])
# FIXME: Replace `main' with a function in `-lvgl':
AC_CHECK_LIB([vgl],[main])
# FIXME: Replace `main' with a function in `-lwrap':
AC_CHECK_LIB([wrap],[main])
# FIXME: Replace `main' with a function in `-ly':
AC_CHECK_LIB([y],[main])
# FIXME: Replace `main' with a function in `-lyp':
AC_CHECK_LIB([yp],[main])
# FIXME: Replace `main' with a function in `-lypclnt':
AC_CHECK_LIB([ypclnt],[main])
# FIXME: Replace `main' with a function in `-lz':
AC_CHECK_LIB([z],[main])

# Checks for header files.
AC_PATH_X
AC_HEADER_RESOLV
AC_HEADER_MAJOR
AC_HEADER_STDBOOL dnl# also "_CHECK"s it
AC_CHECK_HEADERS([OS.h argz.h arpa/inet.h fcntl.h fenv.h float.h inttypes.h \
                  langinfo.h libintl.h limits.h locale.h mach/mach.h malloc.h \
                  memory.h mntent.h mnttab.h netdb.h netinet/in.h nl_types.h \
                  nlist.h paths.h sgtty.h shadow.h stddef.h stdint.h \
                  stdio_ext.h stdlib.h string.h strings.h sys/acl.h \
                  sys/file.h sys/fs/s5param.h sys/fs_types.h sys/fstyp.h \
                  sys/ioctl.h sys/mntent.h sys/mount.h sys/param.h \
                  sys/socket.h sys/statfs.h sys/statvfs.h sys/systeminfo.h \
                  sys/time.h sys/timeb.h sys/vfs.h syslog.h termio.h \
                  termios.h unistd.h utime.h utmp.h utmpx.h values.h wchar.h \
                  wctype.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_UID_T
AC_C_INLINE
AC_TYPE_INT8_T
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_MODE_T
AC_FUNC_OBSTACK
AC_TYPE_OFF_T
AC_TYPE_PID_T
AC_C_RESTRICT
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_CHECK_MEMBERS([struct stat.st_blksize])
AC_STRUCT_ST_BLOCKS
AC_CHECK_MEMBERS([struct stat.st_rdev])
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
AC_STRUCT_TIMEZONE
AC_TYPE_UINT8_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_CHECK_TYPES([ptrdiff_t])dnl

# Checks for library functions.
AC_FUNC_ALLOCA
AC_FUNC_CHOWN
AM_GNU_GETTEXT([external])
AC_FUNC_ERROR_AT_LINE
AC_FUNC_FORK
AC_FUNC_FSEEKO
AC_FUNC_GETGROUPS
AC_FUNC_LSTAT dnl# also checks if it "_FOLLOWS_SLASHED_SYMLINK"
AC_FUNC_MALLOC
AC_FUNC_MBRTOWC
AC_FUNC_MKTIME
AC_FUNC_MMAP
AC_FUNC_REALLOC
AC_FUNC_STRCOLL
AC_FUNC_STRERROR_R
AC_FUNC_STRNLEN
AC_FUNC_STRTOD
AC_FUNC_WAIT3
AC_CHECK_FUNCS([__fpending alarm atexit btowc bzero clock_gettime doprnt dup2 \
                endgrent endpwent fchdir fdatasync fesetround floor ftime \
                ftruncate getcwd getdelim gethostbyaddr gethostbyname \
                gethostname getmntinfo getpagesize getpass getspnam \
                gettimeofday getusershell hasmntopt inet_ntoa isascii \
                iswprint lchown localeconv localtime_r mblen mbrlen memchr \
                memmove mempcpy memset mkdir mkfifo modf munmap nl_langinfo \
                pathconf pow pstat_getdynamic putenv re_comp realpath regcmp \
                regcomp resolvepath rint rmdir rpmatch select setenv \
                sethostname setlocale socket sqrt stime stpcpy strcasecmp \
                strchr strcspn strdup strerror strncasecmp strndup strpbrk \
                strrchr strspn strstr strtol strtoul strtoull strtoumax \
                strverscmp sysinfo tzset uname utime utmpname utmpxname \
                wcwidth])dnl

# Output.
AC_CONFIG_FILES([Automakefile build-aux/Makefile po/Makefile.in])
AC_CONFIG_SUBDIRS([contrib/bmake
                   contrib/expat
                   contrib/gdb-7/gdb
                   contrib/lvm2/dist
                   contrib/nvi/build
                   contrib/opie
                   contrib/smbfs])
AC_OUTPUT
