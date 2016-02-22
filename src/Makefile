CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic
LDLIBS = -lm

quadmain: quadmain.c getRoots/getRoots.o numRoots/numRoots.o input/input.o output/output.o

clean:
	rm ./quadmain
	cd getRoots; make clean
	cd numRoots; make clean
	cd input; make clean
	cd output; make clean
