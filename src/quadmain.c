 /*INCLUDES*/
#include <stdlib.h>
#include "quad_types.h"
#include "input/input.h"
#include "validation/input_val.h"
#include "num_roots/num_roots.h"
#include "get_roots/get_roots.h"
#include "output/output.h"
#include "formatter/formatter.h"
/*Functions*/
int main()
{
	int rootNum = 0;
	Coef coef;
	Root root;
	char *buffer;
	char *input;
	input = get_input(&coef);
	if (!input_val(&coef, input)) {
		output("invalid input");
		exit(1);
	}
	rootNum = num_roots(coef);
	get_roots(coef, rootNum, &root);
	buffer = formatter(rootNum, root);
	output(buffer);
	free(input);
	free(buffer);
}
