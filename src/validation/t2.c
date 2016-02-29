#include <stdlib.h>
#include "../quad_types.h"
#include "../cunit/cunit.h"
#include "inputVal.h"

int main()
{
	Coef coefs;
	int ret;
	char *input = "1 a 1";
	cunit_init();
	ret = inputVal(&coefs, input);
	assert_eq("ret", ret, 0);
}
