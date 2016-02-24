CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic
LDFLAGS = -lm

getRoots.o: getRoots.c

t1: t1.c ../cunit/cunit.o ../numRoots/numRoots.o ../sqrt/sqrt.o getRoots.o

t2: t2.c ../cunit/cunit.o ../numRoots/numRoots.o ../sqrt/mock_sqrt.o getRoots.o

.PHONY: clean
clean:
	rm getRoots.o
