##########################################################
# Created by: rashmi                                  #
# Created on: Friday 02 December 2022 02:06:54 PM IST #
##########################################################


SRCDIR = ../src
INCLUDEDIR = ../include
OBJDIR = ../obj
BINDIR = ../bin
CFLAGS = -c -g -Wall -I${INCLUDEDIR}


all:
	gcc ${CFLAGS}  ${SRCDIR}/menu.c -o ${OBJDIR}/menu.o
	gcc ${CFLAGS}  ${SRCDIR}/list.c -o ${OBJDIR}/list.o
	gcc ${CFLAGS}  ${SRCDIR}/main.c -o ${OBJDIR}/main.o
	gcc ${CFLAGS}  ${SRCDIR}/utility.c -o ${OBJDIR}/utility.o
	gcc ${CFLAGS}  ${SRCDIR}/linkedList.c -o ${OBJDIR}/linkedList.o
	gcc ${OBJDIR}/main.o ${OBJDIR}/utility.o ${OBJDIR}/linkedList.o ${OBJDIR}/menu.o ${OBJDIR}/list.o -o ${BINDIR}/spm.bin

clean:

	rm ${OBJDIR}/main.o ${OBJDIR}/utility.o ${OBJDIR}/linkedList.o ${OBJDIR}/menu.o ${OBJDIR}/list.o :${BINDIR}/spm.bin


#################### End of Makefile #####################

