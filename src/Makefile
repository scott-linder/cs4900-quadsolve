CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic
LDLIBS = -lm

MODS = get_roots num_roots input validation output formatter cunit sqrt

quadmain: quadmain.c get_roots/get_roots.o formatter/formatter.o \
	num_roots/num_roots.o input/input.o validation/input_val.o \
	output/output.o sqrt/sqrt.o

.PHONY: test
test:
	for mod in ${MODS}; do cd $$mod; make test; cd ..; done

.PHONY: format
format:
	find . \( -name '*.c' -o -name '*.h' \) -execdir indent -linux "{}" \;
	find . \( -name '*.c~' -o -name '*.h~' \) -execdir rm "{}" \;

.PHONY: clean
clean:
	-rm ./quadmain
	-rm ./log.txt
	for mod in ${MODS}; do cd $$mod; make clean; cd ..; done
