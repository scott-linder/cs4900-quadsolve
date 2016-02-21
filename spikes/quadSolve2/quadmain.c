/*INCLUDES*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpfr.h>
#include "quadHead.h"
#include "quadInclude.h"


/*Functions*/
int main()
{
	int rootNum =0;
	Coef *coef= malloc(sizeof(*coef));
	Root *root = malloc(sizeof(*root));
    getInput(coef);
	rootNum = numRoots(*coef);
	getRoots(*coef,rootNum, root);
	printRoots(rootNum, *root);
}

