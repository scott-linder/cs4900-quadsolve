CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic
LDFLAGS = -lm

getRoots.o: getRoots.c

t1: t1.c ../cunit/cunit.o ../numRoots/numRoots.o ../sqrt/sqrt.o getRoots.o

.PHONY: clean
clean:
	rm getRoots.o
