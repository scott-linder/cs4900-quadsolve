/*
* t2.c
* Unit tests for quad_roots()
* qsolve() solves a * x^2 + b x + c = 0
*   for the roots
* x1 and x2
*
* This uses the mock qsolve_sqrt() funcxetion in mock_sqrt.c,
* which does not call sqart()
*
* Both of trhese unit test pass. For examples, it's more fun to
* make them fail.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../cunit/cunit.h"
#include "../sqrt/mock_sqrt.h"
#include "../quad_types.h"
#include "../num_roots/num_roots.h"
#include "get_roots.h"

int main()
{
	Coef coefs;		// a, b and c for the quadratic eqaution
	Root roots;		// Root struct with x1 and x1
	int num, ret;		// return value from num_roots() and get_roots()
	double a, b, c;		// scratch variables
	double x1, x2;		// scratch variables
	int count;		// number of times the mock object qsolve_sqrt(0 is called.
	double x;		// arguement passed to qsolve_sqrt()
	char str[100];		// messsaage for assert()
	double d;		// scratch for discriminate
	double sqrtd;		// scratch for sqrt(d)

	cunit_init();

	//
	// A "good" unit test, need to allow for round off!
	// qsolve_roots() passes this one. ;-)
	// This allows about one base 10 least significant digit of error
	// (x - x1)*(x - x2) = 0
	x1 = 3.1;
	x2 = 3.3;
	a = coefs.a = 1.0;
	b = coefs.b = -x1 + -x2;
	c = coefs.c = x1 * x2;

	d = b * b - 4.0 * a * c;
	sqrtd = sqrt(d);

	setup_mock_sqrt(d, sqrtd, cunit_dmacheps * 2.0 * d);
	num = num_roots(coefs);
	ret = get_roots(coefs, num, &roots);
	assert_eq("ret", ret, true);
	assert_feqrerr("x1", roots.x1, x2, 2.0 * cunit_dmacheps * 3.3);
	assert_feqrerr("x2", roots.x2, x1, 2.0 * cunit_dmacheps * 3.1);
	ret = check_mock_sqrt(&count, &x);
	snprintf(str, 99, "count ret = %d x =%20.61e", count, x);
	assert_eq(str, ret, 0);

	exit(0);
}
