CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic

input_val.o: input_val.c

t1: t1.c ../cunit/cunit.o input_val.o

t2: t2.c ../cunit/cunit.o input_val.o

.PHONY: test
test: t1 t2
	./t1
	./t2

.PHONY: clean
clean:
	-rm input_val.o t1 t2
