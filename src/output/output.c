/**
 * @file output.c
 * @date Feb 29, 2016
 * @brief Output to user.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../quad_types.h"

/**
 * @brief Output a string.
 *
 * @return True on success, false on failure.
 */
bool output(char *s)
{
	#ifdef Logging
		FILE * logFile;
		logFile = fopen("log.txt","a");
		fprintf(logFile, "\nPassed parameters to output():\n");
		fprintf(logFile, "\ts: %s \n",s);
		fclose(logFile);
	#endif
	/* input validation */
	if (!s)
		return false;

	puts(s);
	#ifdef Logging
		logFile = fopen("log.txt","a");
		fprintf(logFile, "\nReturned parameter from output():\n");
		fprintf(logFile, "\tTRUE \n");
		fclose(logFile);
	#endif
	return true;
}
