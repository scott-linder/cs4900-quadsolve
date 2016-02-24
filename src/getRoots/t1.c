/*
* t1.c
* Unit tests for quad_roots() 
* solves a * x^2 + b x + c = 0
*   for the roots
* x1 and x2
* *
* This uses the qsolve_sqrt() which calls the system sqrt()
*/

#include <stdlib.h>
#include "../cunit/cunit.h"
#include "../quadTypes.h"
#include "../numRoots/numRoots.h"
#include "getRoots.h"

int main()
{
    Coef coefs;			// a, b and c for the quadratic eqaution
    Root roots;			// Root struct with x1 and x1
    int num, ret;		// return value from numRoots and getRoots
    // double  a, b, c; 	// scratch variables
    double x1, x2;		// scratch variables


    cunit_init();

    //  A bad unit tet
    coefs.a = 1.0;
    coefs.b = 2.0;
    coefs.c = 1.0;

    num = numRoots(coefs);
    ret = getRoots(coefs, num, &roots);
    assert_eq("ret", ret, 2);
    assert_feq("x1", roots.x1, -2.0);
    assert_feq("x2", roots.x2, -2.0);

    // A bad unit test, wrong order
    // (x - x1)*(x - x2) = 0
    x1 = 3.1;
    x2 = 3.3;
    coefs.a = 1.0;
    coefs.b = -x1 + -x2;
    coefs.c = x1 * x2;
    num = numRoots(coefs);
    ret = getRoots(coefs, num, &roots);
    assert_eq("ret", ret, 2);
    assert_feq("x1", roots.x1, x1);
    assert_feq("x2", roots.x2, x2);

    // A bad unit test, need to allow for round off!
    // (x - x1)*(x - x2) = 0
    x1 = 3.1;
    x2 = 3.3;
    coefs.a = 1.0;
    coefs.b = -x1 + -x2;
    coefs.c = x1 * x2;
    num = numRoots(coefs);
    ret = getRoots(coefs, num, &roots);
    assert_eq("ret", ret, 2);
    assert_feq("x1", roots.x1, x2);
    assert_feq("x2", roots.x2, x1);

    // A "good" unit test, need to allow for round off!
    // getRoots() passes this one. ;-)
    // This allows about one base 10 least significant digit of error
    // (x - x1)*(x - x2) = 0
    x1 = 3.1;
    x2 = 3.3;
    coefs.a = 1.0;
    coefs.b = -x1 + -x2;
    coefs.c = x1 * x2;
    num = numRoots(coefs);
    ret = getRoots(coefs, num, &roots);
    assert_eq("ret", ret, 2);
    assert_feqrerr("x1", roots.x1, x2, 10.0 * cunit_dmacheps);
    assert_feqrerr("x2", roots.x2, x1, 10.0 * cunit_dmacheps);
    exit(0);
}
