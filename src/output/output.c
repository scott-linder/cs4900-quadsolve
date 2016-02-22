/*prints the number of roots as well as the roots themself*/
int printRoots(int numRoots, Root root)
{
	if(numRoots==0){
		printf("This is a Single/Double root\n");
		printf("The root is: %lf\n",root.x1);
	}else if(numRoots ==1){
		printf("There are 2 real roots\n");
		printf("The first root is: %lf\n",root.x1);
		printf("The second root is: %lf\n",root.x2);
	}else{
		printf("There are no real roots\n");

	}
	return 0;
}