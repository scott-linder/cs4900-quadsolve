/**
 * @file get_roots.c
 * @date Feb 29, 2016
 * @brief Calculate quadratic roots.
 */

#include <math.h>
#include <stdbool.h>
#include "../quad_types.h"
#include "../sqrt/sqrt.h"

/**
 * @brief Calculates the roots for the given quadratic equation puts the
 * results in the root structure.
 *
 * @param coef Coefficients to caluclate the roots of.
 * @param num_roots Number of real roots.
 * @param root Out parameter to write the values of the roots into.
 *
 * @return True on success, false on error.
 */
bool get_roots(Coef coef, int num_roots, Root * root)
{
	/* input validation */
	if (!(isfinite(coef.a) && isfinite(coef.b) && isfinite(coef.c)))
		return false;

	double sroot;
	if (num_roots == 1) {
		/* -b/2a */
		root->x1 = (-coef.b) / (2 * coef.a);
	} else if (num_roots == 2) {
		/* -b+-sqrt(b2-4ac)/2a */
		sroot = qsolve_sqrt((pow(coef.b, 2)) - (4 * coef.a * coef.c));
		if (sroot < 0)
			return false;
		root->x1 = (-coef.b + sroot) / (2 * coef.a);
		root->x2 = (-coef.b - sroot) / (2 * coef.a);
	}
	return true;
}
