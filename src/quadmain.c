/**
 * @file quadmain.c
 * @date Feb 29, 2016
 * @brief Coordinates all modules.
 */

#include <stdlib.h>
#include <stdio.h>
#include "quad_types.h"
#include "input/input.h"
#include "validation/input_val.h"
#include "num_roots/num_roots.h"
#include "get_roots/get_roots.h"
#include "output/output.h"
#include "formatter/formatter.h"

/**
 * @brief Entry point for program.
 *
 * Coordinates all modules.
 */
int main()
{
	#ifdef Logging
		FILE * logFile;
		logFile = fopen("log.txt","w+");
		fprintf(logFile, "----LOGFILE FOR QUADRATIC EQUATION SOLVER----\n");
		fclose(logFile);
	#endif
	int rootNum = 0;
	Coef coef;
	Root root;
	char *buffer;
	char *input;
	input = get_input();
	if (!input_val(&coef, input)) {
		output("Invalid input");
		exit(1);
	}
	#ifdef Logging
		logFile = fopen("log.txt","a");
		fprintf(logFile, "\nReturn parameters to input_val():\n");
		fprintf(logFile, "\tCoef.a: %lf Coef.b:%lf Coef.c: %lf \n"
			,coef.a,coef.b,coef.c);
		fclose(logFile);
	#endif
	rootNum = num_roots(coef);
	get_roots(coef, rootNum, &root);
	buffer = formatter(rootNum, root);
	output(buffer);
	free(input);
	free(buffer);
}
