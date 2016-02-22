/*INCLUDES*/
#include "quadTypes.h"
#include "input/input.h"
#include "numRoots/numRoots.h"
#include "getRoots/getRoots.h"
#include "output/output.h"

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

