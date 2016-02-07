/*INCLUDES*/
#include <stdio.h>
#include <math.h>
#include <mpfr.h>

/*PROTOTYPES*/
int roots(mpfr_t a, mpfr_t b, mpfr_t c);


/*Functions*/
int main()
{
	double aIn,bIn,cIn;
	int root =0;
	mpfr_t a, b, c;
    mpfr_init2(a, 1000);
    mpfr_init2(b, 1000);
    mpfr_init2(c, 1000);
	printf("Enter a value for a: ");
	scanf("%lf",&aIn);
	mpfr_init_set_d(a, aIn, MPFR_RNDN);
	printf("Enter a value for b: ");
	scanf("%lf", &bIn);
	mpfr_init_set_d(b, bIn, MPFR_RNDN);
	printf("Enter a value for c: ");
	scanf("%lf", &cIn);
	mpfr_init_set_d(c, cIn, MPFR_RNDN);
	printf("Your Equation: (%lf)x^2+(%lf)x+(%lf)\n",aIn,bIn,cIn );
	root = roots(a,b,c);
	if(root ==0)printf("DOUBLE ROOT\n");
	if(root ==1)printf("TWO REAL ROOTS\n");
	if(root ==-1)printf("NO REAL ROOTS\n");
}

/* Roots takes the three input value and using the disciminate (b^2-4ac)
* it determines how many roots this quadratic has. It will return 0 if double root,
* return 1 if two real roots, and -1 if no real roots.
*/
int roots(mpfr_t a, mpfr_t b, mpfr_t c)
{
	int retVal =0;
	mpfr_t b2,disc,ac;
	mpfr_init2(b2, 1000);
	mpfr_init2(disc, 1000);
	mpfr_init2(ac, 1000);
	/*Start Math Functions*/
	mpfr_pow_ui(b2, b, 2, MPFR_RNDN); /*get b^2 for discriminate*/
	mpfr_mul(ac, a, c, MPFR_RNDN); /*get ac for discriminate*/
	mpfr_mul_ui(ac,ac,4,MPFR_RNDN);/*get 4ac for discriminate*/
	mpfr_sub(disc,b2,ac,MPFR_RNDN);/*get discriminate*/
	/*Comparisons*/
	if(mpfr_cmp_ui(disc,0)==0){
		retVal =0;
	}else if(mpfr_cmp_ui(disc,0)>0){
		retVal =1;
	}else{
		retVal =-1;
	}
	return retVal;
}