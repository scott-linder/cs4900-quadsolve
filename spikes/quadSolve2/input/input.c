int getInput(Coef *coef)
{
	printf("Enter a value for a: ");
	scanf("%lf", &coef->a);
	printf("Enter a value for b: ");
	scanf("%lf", &coef->b);
	printf("Enter a value for c: ");
	scanf("%lf", &coef->c);
	printf("Your Equation: (%lf)x^2+(%lf)x+(%lf)\n", coef->a, coef->b, coef->c);
	return 1;
}

