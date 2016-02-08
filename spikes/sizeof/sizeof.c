#include <stdio.h>
#include <float.h>
int main(void) {
    printf("sizeof(float)=%zu\n", sizeof(float));
    printf("sizeof(double)=%zu\n", sizeof(double));
    printf("sizeof(long double)=%zu\n", sizeof(long double));
    printf("FLT_DIG=%u\n", FLT_DIG);
    printf("DBL_DIG=%u\n", DBL_DIG);
    printf("LDBL_DIG=%u\n", LDBL_DIG);
}
