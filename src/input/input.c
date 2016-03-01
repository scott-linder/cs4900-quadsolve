/**
 * @file input.c
 * @date Feb 29, 2016
 * @brief Prompt and accept user input.
 */

#include <stdio.h>
#include <stdlib.h>
#include "../quad_types.h"

/**
 * @brief Print a prompt and accept a line from the user.
 *
 * @return The user's inputted string.
 */
char *get_input()
{
	char *input = malloc(sizeof(char) * 50);
	printf("Enter a values: ");
	fgets(input, sizeof(char) * 50, stdin);
	return input;
}
