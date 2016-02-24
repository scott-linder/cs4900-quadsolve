CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic
LDFLAGS = -lm

get_roots.o: get_roots.c

t1: t1.c ../cunit/cunit.o ../num_roots/num_roots.o ../sqrt/sqrt.o get_roots.o

t2: t2.c ../cunit/cunit.o ../num_roots/num_roots.o ../sqrt/mock_sqrt.o get_roots.o

.PHONY: clean
clean:
	-rm get_roots.o
