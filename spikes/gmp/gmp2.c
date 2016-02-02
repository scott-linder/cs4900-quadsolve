/* 
*CS4900
*Basically the same as the MPFR as it is built on this, slightly different functions
*Internet suggests mpfr as it is more accurate than gmp by itself
*Floating point functions for GMP can be found https://gmplib.org/manual/Floating_002dpoint-Functions.html
*/
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(void)
{
mpf_t x, y,z;
mpf_init2(x,256);           
mpf_init2(y, 256);     /* precision at least 256 bits */
mpf_init2(z,256);
mpf_set_str(x,"123.45",10);
mpf_set_str(y,"321.789",10);
mpf_add(z,x,y);
mpf_out_str (stdout, 10, 8, x);
printf(" + ");
mpf_out_str (stdout, 10, 8, y);
printf(" = ");
mpf_out_str (stdout, 10, 8, z);
printf("\n");
mpf_clear(x);
mpf_clear(y);
mpf_clear(z);

}