CC      = gcc

CFLAGS  = -Wall -Wextra
CFLAGS += -g

ATM: ATM.c
	${CC} ${CFLAGS} -o ATM ATM.c

.PHONY: all clean realclean
