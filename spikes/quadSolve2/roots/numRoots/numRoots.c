/* Roots takes the three input value and using the disciminate (b^2-4ac)
* it determines how many roots this quadratic has. It will return 0 if double root,
* return 1 if two real roots, and -1 if no real roots.
*/
int numRoots(Coef coef)
{
	int retVal = 0;
	double disc = 0;
	/*Start Math Functions*/
	disc = (pow(coef.b, 2)) - (4 * coef.a * coef.c);
	/*Comparisons*/
	if(disc == 0){
		retVal =0;
	}else if(disc > 0){
		retVal = 1;
	}else{
		retVal = -1;
	}
	return retVal;
}