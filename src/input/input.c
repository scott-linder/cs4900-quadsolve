#include <stdio.h>
#include <stdlib.h>
#include "../quad_types.h"

char *get_input()
{
	char *input = malloc(sizeof(char) * 50);
	printf("Enter a values: ");
	fgets(input, sizeof(char) * 50, stdin);
	return input;
}
