/**
 * @file cunit.c
 * @brief Unit test framework entry point.
 *
 * Provides init function for the macros provided in `cunit.h`
 */

#include <stdio.h>
#include "cunit.h"

FILE *cunit_log; //< File to log cunit results to.
double cunit_dmacheps; //< Machine epsilon estimate.

/**
 * @brief Setup cunit; should be called before any other function or macro.
 *
 * @return 0 on success, 1 on failure.
 */
int cunit_init()
{
	double dm;
	double dmacheps = 0.5;

	cunit_log = stderr;

	while ((1.0 + (dm = dmacheps / 2.0)) != 1.0) {
		dmacheps = dm;
	}
	cunit_dmacheps = dmacheps;
	return 0;
}
