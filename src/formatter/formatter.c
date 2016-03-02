/**
 * @file formatter.c
 * @date Feb 29, 2016
 * @brief Output formatting.
 */

#include <stdio.h>
#include <stdlib.h>
#include "../quad_types.h"

#define BUFF 128

/**
 * @brief Prints the number of roots as well as the roots themself
 *
 * @param num_roots Number of real roots.
 * @param root The values of the real roots.
 *
 * @return The formatted string, or NULL on error.
 */
char *formatter(int num_roots, Root root)
{
	#ifdef Logging
		FILE * logFile;
		logFile = fopen("log.txt","a");
		fprintf(logFile, "\nPassed parameters to formatter():\n");
		fprintf(logFile, "\tnum_roots = %d Root.x1: %lf Root.x2: %lf\n",
			num_roots,root.x1, root.x2);
		fclose(logFile);
	#endif

	/* input validation */
	if (num_roots < 0 || num_roots > 2)
		return NULL;

	char *buffer = malloc(BUFF * sizeof(char));
	if (num_roots == 1) {
		sprintf(buffer,
			"This is a Single/Double root\nThe root is: %lf",
			root.x1);
	} else if (num_roots == 2) {
		sprintf(buffer,
			"There are 2 real roots\nThe first root is: %lf\nThe second root is: %lf",
			root.x1, root.x2);
	} else {
		sprintf(buffer, "There are no real roots");
	}

	#ifdef Logging
		logFile = fopen("log.txt","a");
		fprintf(logFile, "Return value from formatter():\n");
		fprintf(logFile, "\tBuffer: %s\n",buffer);
		fclose(logFile);
	#endif

	return buffer;
}
