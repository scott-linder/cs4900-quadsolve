#include <stdio.h>
#include <math.h>

/*
 * Reference: http://bose.physics.ucdavis.edu/quadratic.pdf
 * Reference: https://en.wikipedia.org/wiki/Quadratic_equation
 */

int main(void) {
    double a, b, c, d;

    printf("a? ");
    scanf("%lf", &a);
    printf("b? ");
    scanf("%lf", &b);
    printf("c? ");
    scanf("%lf", &c);
    d = b*b - 4.0 * a * c;
    if (d > 0) {
        printf("two real roots\n");
        double r1 = (-b + sqrt(d)) / (2.0 * a);
        double r2 = (-b - sqrt(d)) / (2.0 * a);
        printf("%f\n", r1);
        printf("%f\n", r2);
    } else if (d == 0) {
        printf("one real root\n");
        double r = (-b) / (2.0 * a);
        printf("%f\n", r);
    } else {
        printf("two complex roots\n");
        double n = (-b) / (2.0 * a);
        double i = sqrt(-d) / (2.0 * a);
        printf("%f + %fi\n", n, i);
        printf("%f - %fi\n", n, i);
    }
}
