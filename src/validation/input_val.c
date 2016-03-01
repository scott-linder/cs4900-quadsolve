/**
 * @file input_val.c
 * @date Feb 29, 2016
 * @brief Validate user input.
 */

#include <stdio.h>
#include <stdbool.h>
#include "../quad_types.h"

/**
 * @brief Validate user input.
 *
 * @param coef Out parameter to write the user supplied values into.
 * @param input User input string.
 *
 * @return True if input is good, false if input is bad.
 */
bool input_val(Coef * coef, char *input)
{
	/* input validation */
	if (!input)
		return false;
	return sscanf(input, "%lf %lf %lf", &coef->a, &coef->b, &coef->c) == 3;
}
