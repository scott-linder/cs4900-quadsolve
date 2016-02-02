/*
*	CS4900
*	testing INF, -INF, and NAN on Sqrt function. 
*	In short sqrt does not except Inf or Nans as arguments, 
*	which makes sense since they arent actually numbers.
*	Code by Justin Lanyon
*/

#include <stdio.h>
#include <math.h>

int main ()
{
    double x =INFINITY,y = -INFINITY, z = NAN;
    printf("X = %lf\n",x);
	printf("Square root of X is %lf\n", sqrt(x));
	printf("Y = %lf\n",y);
	printf("Square root of Y is %lf\n", sqrt(y) );
	printf("Z = %lf\n",z);
	printf("Square root of Z is %lf\n", sqrt(z) );
	printf("%lf + %lf = %lf\n",x,y,(x+y)); /*Just to see*/
   
    return(0);
}
