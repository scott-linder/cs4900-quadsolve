/**
 * @file sqrt.c
 * @date Feb 29, 2016
 * @brief Calculate square root.
 */

#include <math.h>

/**
 * @brief Calculate square root.
 *
 * @param x Value to calculate square root of. Must be non-negative and finite.
 *
 * @return Square root of x, or -1.0 on failure.
 */
double qsolve_sqrt(double x)
{
	/* input validation */
	if (!isfinite(x) || x < 0)
		return -1.0;

	return sqrt(x);
}
