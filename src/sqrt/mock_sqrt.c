/**
 * @file mock_sqrt.c
 * @date Feb 29, 2016
 * @brief Mocking of qsolve_sqrt function.
 *
 * First call setup_mock_sqrt()
 *
 * Then run the code to be tested.
 *
 * Then call check_mock_sqrt()
 *
 * Finally call teardown_mock_sqrt()
 */

#include <math.h>
#include "mock_sqrt.h"
#include "sqrt.h"

static double x = -1.0;		//< actual arguement passed to qsolve_sqrt()
static double ex = -1.0;	//< expected argument x to qsolve_sqrt()
static double eps = -1.0;	//< absolute error allowed in x
static double sqrtx = -1.0;	//< result to return fomr qsolve_sqrt(), sqrt(x)
static int count = 0;		//< actual count of calls to qsolve_sqrt() made
static int flag = -1;

/**
 * @brief Setup to use the mock qsolve_sqrt
 *
 * @param lx Expected x
 * @param lsqrtx Result to return from mock qsolve_sqrt
 * @param leps Absolute error to allow
 */
void setup_mock_sqrt(double lx, double lsqrtx, double leps)
{
	ex = lx;
	eps = leps;
	sqrtx = lsqrtx;
	count = 0;
	flag = 0;
}

double qsolve_sqrt(double lx)
{
	if (fabs(ex - lx) > eps) {
		flag = 1;
	}
	x = lx;
	count++;
	return sqrtx;
}

/**
 * @brief Check if calls to the mock qsolve_sqrt were correct.
 *
 * @param lcount Out parameter to receive number of calls.
 * @param lx Out parameter to receive actual x.
 *
 * @return 0 if x is correct and count is 1, or 1 otherwise.
 */
int check_mock_sqrt(int *lcount, double *lx)
{
	int ret;
	*lcount = count;
	*lx = x;
	if ((flag == 0) && (count == 1)) {
		ret = 0;
	} else {
		ret = 1;
	}
	return ret;
}

/**
 * @brief Tear down use of mock qsolve_sqrt.
 */
void teardown_mock_sqrt()
{
	x = -1.0;
	ex = -1.0;
	eps = -1.0;
	sqrtx = -1.0;
	count = 0;
	flag = -1;
}
