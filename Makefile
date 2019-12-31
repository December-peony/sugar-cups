SOURCES = sugar.c check.c Gui.c convert.c
OBJS    = ${SOURCES:.c=.o}
CFLAGS  = `pkg-config --cflags gtk+-3.0` 
LDADD   = `pkg-config --libs gtk+-3.0` 
CC      = gcc
PACKAGE = sugar

all : ${OBJS}
	${CC} -o ${PACKAGE} ${OBJS} ${LDADD}

.c.o:
	${CC} ${CFLAGS} -c $<
