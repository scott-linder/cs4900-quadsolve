#include <stdio.h>
#include <math.h>

/*
 * Reference: http://bose.physics.ucdavis.edu/quadratic.pdf
 */

int main(void) {
    double a, b, c, r1, r2;

    printf("a? ");
    scanf("%lf", &a);
    printf("b? ");
    scanf("%lf", &b);
    printf("c? ");
    scanf("%lf", &c);
    r1 = (-b + sqrt(b*b - 4.0 * a * c)) / (2 * a);
    r2 = (-b - sqrt(b*b - 4.0 * a * c)) / (2 * a);
    printf("%f\n", r1);
    printf("%f\n", r2);
}
