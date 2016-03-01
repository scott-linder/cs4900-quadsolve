/**
 * @file num_roots.c
 * @date Feb 29, 2016
 * @brief Calculate number of real roots.
 */

#include <math.h>
#include "../quad_types.h"

/**
 * @brief Determines the number of real roots.
 *
 * Roots takes the three input value and using the disciminate (b^2-4ac) it
 * determines how many roots this quadratic has. It will return 0 if double
 * root, return 1 if two real roots, and -1 if no real roots.
 *
 * @return A non-negative number on success, or -1 on failure.
 */
int num_roots(Coef coef)
{
	/* input validation */
	if (!(isfinite(coef.a) && isfinite(coef.b) && isfinite(coef.c)))
		return -1;

	int retVal = 0;
	double disc = 0;
	/*Start Math Functions */
	disc = (pow(coef.b, 2)) - (4 * coef.a * coef.c);
	/*Comparisons */
	if (disc == 0) {
		retVal = 1;
	} else if (disc > 0) {
		retVal = 2;
	} else {
		retVal = 0;
	}
	return retVal;
}
