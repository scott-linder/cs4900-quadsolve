#include <stdio.h>
#include <stdlib.h>
#include "../quad_types.h"

#define BUFF 128

/*prints the number of roots as well as the roots themself*/
char* formatter(int num_roots, Root root)
{
	char* buffer = malloc(BUFF*sizeof(char));
	if(num_roots==0){
		sprintf(buffer,"This is a Single/Double root\nThe root is: %lf\n",root.x1);
	}else if(num_roots ==1){
		sprintf(buffer,"There are 2 real roots\nThe first root is: %lf\nThe second root is: %lf\n", root.x1, root.x2);
	}else{
		sprintf(buffer,"There are no real roots\n");
	}

	return buffer;
}


