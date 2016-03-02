/**
 * @file sqrt.c
 * @date Feb 29, 2016
 * @brief Calculate square root.
 */

#include <math.h>
#include <stdio.h>
#include "../quad_types.h"

/**
 * @brief Calculate square root.
 *
 * @param x Value to calculate square root of. Must be non-negative and finite.
 *
 * @return Square root of x, or -1.0 on failure.
 */
double qsolve_sqrt(double x)
{
	#ifdef Logging
		FILE * logFile;
		logFile = fopen("log.txt","a");
		fprintf(logFile, "\tPassed to qsolve_sqrt():\n");
		fprintf(logFile, "\t\tx: %lf\n",x);
		fclose(logFile);
	#endif

	double sqt = 0;
	/* input validation */
	if (!isfinite(x) || x < 0)
		return -1.0;
	
	sqt = sqrt(x);

	#ifdef Logging
		logFile = fopen("log.txt","a");
		fprintf(logFile, "\tReturned from qsolve_sqrt():\n");
		fprintf(logFile, "\t\tsqt: %lf\n",sqt);
		fclose(logFile);
	#endif

	return sqt;
}
