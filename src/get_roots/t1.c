#include <stdlib.h>
#include <stdbool.h>
#include "../cunit/cunit.h"
#include "../quad_types.h"
#include "../num_roots/num_roots.h"
#include "get_roots.h"

int main()
{
	Coef coefs;
	Root roots;
	int num, ret;
	double x1, x2;

	cunit_init();

	x1 = 3.3;
	x2 = 3.1;
	coefs.a = 1.0;
	coefs.b = -x1 + -x2;
	coefs.c = x1 * x2;
	num = num_roots(coefs);
	ret = get_roots(coefs, num, &roots);
	assert_eq("ret", ret, true);
	assert_feqrerr("x1", roots.x1, x1, 10.0 * cunit_dmacheps);
	assert_feqrerr("x2", roots.x2, x2, 10.0 * cunit_dmacheps);
}
