/*INCLUDES*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpfr.h>
#include "quadTypes.h"
#include "input/input.c"
#include "roots/numRoots/numRoots.c"
#include "roots/getRoots/getRoots.c"
#include "output/output.c"


/*Functions*/
int main()
{
	int rootNum =0;
	Coef coef;
	Root root;
	getInput(&coef);
	rootNum = numRoots(coef);
	getRoots(coef, rootNum, &root);
	printRoots(rootNum, root);
}

