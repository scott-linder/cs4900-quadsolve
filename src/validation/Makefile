CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic

inputVal.o: inputVal.c

t1: t1.c ../cunit/cunit.o inputVal.o

t2: t2.c ../cunit/cunit.o inputVal.o

.PHONY: clean
clean:
	-rm inputVal.o
