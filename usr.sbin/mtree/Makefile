#	From: @(#)Makefile	8.1 (Berkeley) 6/6/93
# $FreeBSD: src/usr.sbin/mtree/Makefile,v 1.15.2.5 2001/09/24 15:44:22 ru Exp $
# $DragonFly: src/usr.sbin/mtree/Makefile,v 1.2 2003/06/17 04:29:57 dillon Exp $

.PATH: ${.CURDIR}/../../usr.bin/cksum

PROG=	mtree
MAN=	mtree.8
SRCS=	compare.c crc.c create.c excludes.c misc.c mtree.c spec.c verify.c

.if defined(BOOTSTRAPPING)
.PATH: ${.CURDIR}/../../lib/libc/gen
SRCS+=	strtofflags.c
.else
CFLAGS= -Wno-error
CPPFLAGS+= -I/opt/local/include/openssl
.if defined(LIBMD)
DPADD=	${LIBMD}
LDADD=	-lmd
.else
LDADD= -lcrypto
.endif
.endif

.include <bsd.prog.mk>
