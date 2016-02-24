/*INCLUDES*/
#include <stdlib.h>
#include "quad_types.h"
#include "input/input.h"
#include "num_roots/num_roots.h"
#include "get_roots/get_roots.h"
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
	rootNum = num_roots(coef);
	get_roots(coef, rootNum, &root);
	buffer = formatter(rootNum, root);
	output(buffer);
	free(buffer);
}

