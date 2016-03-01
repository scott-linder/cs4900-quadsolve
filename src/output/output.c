/**
 * @file output.c
 * @date Feb 29, 2016
 * @brief Output to user.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Output a string.
 *
 * @return True on success, false on failure.
 */
bool output(char *s)
{
	puts(s);
	return true;
}
