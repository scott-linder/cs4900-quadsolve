/**
 * @file get_roots.c
 * @date Feb 29, 2016
 * @brief Calculate quadratic roots.
 */

#include <math.h>
#include <stdio.h>
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
	#ifdef Logging
		FILE * logFile;
		logFile = fopen("log.txt","a");
		fprintf(logFile, "\nPassed parameters to get_roots():\n");
		fprintf(logFile, "\tCoef.a: %lf Coef.b:%lf Coef.c: %lf num_roots: %d\n"
			,coef.a,coef.b,coef.c,num_roots);
		fclose(logFile);
	#endif
	
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

	#ifdef Logging
		logFile = fopen("log.txt","a");
		fprintf(logFile, "Return value(s) from get_roots():\n");
		fprintf(logFile, "\tRoot.X1:%lf Root.X2:%lf\n",root->x1,root->x2);
		fclose(logFile);
	#endif

	return true;
}
