#include <stdio.h>
#include "../quad_types.h"
/*returns 1 if input is good, returns 0 if input is bad*/
int inputVal(Coef * coef, char *input)
{
	int retVal = 0;
	if (sscanf(input, "%lf %lf %lf", &coef->a, &coef->b, &coef->c) == 3) {
		retVal = 1;
	} else {
		retVal = 0;
	}
	return retVal;
}
