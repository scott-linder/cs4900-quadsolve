CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic
LDLIBS = -lm

quadmain: quadmain.c get_roots/get_roots.o formatter/formatter.o num_roots/num_roots.o input/input.o output/output.o sqrt/sqrt.o

.PHONY: format
format:
	find . \( -name '*.c' -o -name '*.h' \) -execdir indent -linux "{}" \;
	find . \( -name '*.c~' -o -name '*.h~' \) -execdir rm "{}" \;

.PHONY: clean
clean:
	-rm ./quadmain
	cd get_roots; make clean
	cd num_roots; make clean
	cd input; make clean
	cd output; make clean
	cd formatter; make clean
