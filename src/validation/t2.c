#include <stdlib.h>
#include "../quad_types.h"
#include "../cunit/cunit.h"
#include "input_val.h"

int main()
{
	Coef coefs;
	int ret;
	char *input = "1 a 1";
	cunit_init();
	ret = input_val(&coefs, input);
	assert_eq("ret", ret, 0);
}
