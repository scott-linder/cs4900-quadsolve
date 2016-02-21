/*calculates the roots for the given quadratic equation
* puts the results in the root structure
*/
int getRoots(Coef coef,int numRoots, Root *root)
{
	double root1, root2;
	if(numRoots==0){ //-b/2a
		root->x1 = (-coef.b)/(2*coef.a);
	}else if(numRoots==1){ //-b+-sqrt(b2-4ac)/2a
		root1 = (-coef.b + sqrt((pow(coef.b, 2))-(4 * coef.a * coef.c)))/(2 * coef.a);
		root2 = (-coef.b - sqrt((pow(coef.b, 2))-(4 * coef.a * coef.c)))/(2 * coef.a);
		root->x1 = root1;
		root->x2 = root2;
	}else{
	}
	return 0;
}