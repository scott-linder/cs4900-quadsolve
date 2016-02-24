/*INCLUDES*/
#include <stdlib.h>
#include "quadTypes.h"
#include "input/input.h"
#include "numRoots/numRoots.h"
#include "getRoots/getRoots.h"
#include "output/output.h"
#include "formatter/formatter.h"

/*Functions*/
int main()
{
	int rootNum =0;
	Coef coef;
	Root root;
	char *buffer;
	getInput(&coef);
	rootNum = numRoots(coef);
	getRoots(coef, rootNum, &root);
	buffer = formatter(rootNum, root);
	output(buffer);
	free(buffer);
}

