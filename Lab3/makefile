#
# Makefile for magic8 driver
# Author: Michael Kepple
# Date:   24 Apr 2013
#
PROG=	magic8
SRCS=	magic8.c

DPADD+=	${LIBCHARDRIVER} ${LIBSYS}
LDADD+=	-lchardriver -lsys

MAN=

BINDIR?= /usr/sbin

.include <minix.service.mk>
