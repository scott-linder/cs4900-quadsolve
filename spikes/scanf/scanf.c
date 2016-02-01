/*
  Code by: Ryan DePrekel
*/

#include <stdio.h>

/*
	single precision occupy 32bits of space
		1 bit for sign, 8 bits for exponent, 23 bits for fraction
	double precision occupy 64 bits of space 
		1 bit for sign, 11 bits for exponent, 52 bits for fraction

	scanf() seems to be able to read INFs and NANs into floats
	NaN example divide by zero and sqrt(-1)
	INFs and -INFs
*/
int main(int argc, char* argv[])
{
	double a, b, c;

	/* test to see if the data type double will accept +/- INFs and NANs*/
	printf("Enter a value for a: ");
	scanf("%lf",&a);
	printf("Enter a value for b: ");
	scanf("%lf", &b);
	printf("Enter a value for c: ");
	scanf("%lf", &c);
	printf("a: %lf b: %lf c: %lf\n", a, b, c);

	return 0;
}
