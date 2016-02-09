/*INCLUDES*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpfr.h>

typedef struct {
  mpfr_t	a;
  mpfr_t	b;
  mpfr_t	c;
} Coef;

typedef struct {
  double	x1;
  double	x2;
} Root;

/*PROTOTYPES*/
int numRoots(Coef coef);
int getRoots(Coef coef,int numRoots, Root * root);
int getInput(Coef *coef);
int initInput(Coef *coef, double aIn, double bIn, double cIn);
int printRoots(int numRoots, Root root);

/*Functions*/
int main()
{
	
	int rootNum =0;
	Coef *coef= malloc(sizeof(*coef));
	Root *root = malloc(sizeof(*root));
    getInput(coef);
	rootNum = numRoots(*coef);
	getRoots(*coef,rootNum, root);
	printRoots(rootNum, *root);
}

int getInput(Coef *coef)
{
	double aIn,bIn,cIn;
	printf("Enter a value for a: ");
	scanf("%lf",&aIn);
	printf("Enter a value for b: ");
	scanf("%lf", &bIn);
	printf("Enter a value for c: ");
	scanf("%lf", &cIn);
	printf("Your Equation: (%lf)x^2+(%lf)x+(%lf)\n",aIn,bIn,cIn );
	initInput(coef, aIn, bIn, cIn);
	return 1;
}

int initInput(Coef *coef, double aIn, double bIn, double cIn)
{
	mpfr_init2(coef->a, 1000);
    mpfr_init2(coef-> b, 1000);
    mpfr_init2(coef-> c, 1000);
	mpfr_init_set_d(coef->a, aIn, MPFR_RNDN);
	mpfr_init_set_d(coef->b, bIn, MPFR_RNDN);
	mpfr_init_set_d(coef->c, cIn, MPFR_RNDN);	
	return 1;
}

/* Roots takes the three input value and using the disciminate (b^2-4ac)
* it determines how many roots this quadratic has. It will return 0 if double root,
* return 1 if two real roots, and -1 if no real roots.
*/
int numRoots(Coef coef)
{
	int retVal =0;
	mpfr_t b2,disc,ac;
	mpfr_init2(b2, 1000);
	mpfr_init2(disc, 1000);
	mpfr_init2(ac, 1000);
	/*Start Math Functions*/
	mpfr_pow_ui(b2, coef.b, 2, MPFR_RNDN); /*get b^2 for discriminate*/
	mpfr_mul(ac, coef.a, coef.c, MPFR_RNDN); /*get ac for discriminate*/
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

/*calculates the roots for the given quadratic equation
* puts the results in the root structure
*/
int getRoots(Coef coef,int numRoots, Root *root)
{
	mpfr_t root1,root2,temp, disc;
	mpfr_init2(root1, 1000);
	mpfr_init2(root2, 1000);
	mpfr_init2(temp, 1000);
	mpfr_init2(disc, 1000);
	if(numRoots==0){
		mpfr_mul_ui(root1, coef.a, 2,MPFR_RNDN);
		mpfr_div(root1,coef.b,root1,MPFR_RNDN);
		mpfr_mul_si(root1,root1,-1,MPFR_RNDN);
		root->x1 = mpfr_get_d(root1,MPFR_RNDN);
	}else if(numRoots==1){ //-b+-sqrt(b2-4ac)/2a
		mpfr_mul(temp, coef.a, coef.c, MPFR_RNDN);
		mpfr_mul_ui(temp, temp, 4, MPFR_RNDN);
		mpfr_pow_ui(disc, coef.b, 2,MPFR_RNDN);
		mpfr_sub(disc, disc, temp, MPFR_RNDN);
		mpfr_sqrt(disc,disc,MPFR_RNDN);
		mpfr_mul_si(temp,coef.b,-1,MPFR_RNDN);
		mpfr_add(root1,temp,disc,MPFR_RNDN);
		mpfr_sub(root2,temp,disc,MPFR_RNDN); /*numerator finished*/
		mpfr_mul_ui(temp, coef.a, 2, MPFR_RNDN);
		mpfr_div(root1,root1,temp,MPFR_RNDN);
		mpfr_div(root2,root2,temp,MPFR_RNDN);
		root->x1 = mpfr_get_d(root1,MPFR_RNDN);
		root->x2 = mpfr_get_d(root2,MPFR_RNDN);
	}else{

	}
	return 0;
}
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