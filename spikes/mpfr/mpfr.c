#include <stdio.h>
#include <mpfr.h>
int main(void) {
    mpfr_t x, y, z;
    mpfr_init2(x, 1000);
    mpfr_init2(y, 1000);
    mpfr_init2(z, 1000);
    printf("x=");
    mpfr_set_str(x, "123.45", 10, MPFR_RNDN);
    mpfr_out_str(stdout, 10, 5, x, MPFR_RNDN);
    printf("\ny=");
    mpfr_set_str(y, "20.2", 10, MPFR_RNDN);
    mpfr_out_str(stdout, 10, 5, y, MPFR_RNDN);
    printf("\nx+y=");
    mpfr_add(z, x, y, MPFR_RNDN);
    mpfr_out_str(stdout, 10, 5, z, MPFR_RNDN);
    printf("\n");
}
