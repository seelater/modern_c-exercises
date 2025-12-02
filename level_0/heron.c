#include <stdlib.h>
#include <stdio.h>
/* lower and upper iteration limits centered around 1.0 */
static double const eps1m01 = 1.0 - 0x1P-01;
static double const eps1p01 = 1.0 + 0x1P-01;
static double const eps1m24 = 1.0 - 0x1P-24;
static double const eps1p24 = 1.0 + 0x1P-24;

int main(int argc, char* argv[argc+1]) {
    for (int i = 1; i < argc ; ++i) {
    // process args
    printf("eps1m01= %.12f\t eps1p01= %.12f\n",eps1m01, eps1p01);
        double const a = strtod(argv[i], 0); // arg - > double
        double x = 1.0;
        for (;;) { // by powers of 2
            double prod = a*x;
            printf("in x=%.12f\t,ax=%.12f\n",x, a*x);
            if (prod < eps1m01) {
                x *= 2.0;
            printf("prod < eps1m01 x=%.12f\t,ax=%.12f\n",x, a*x);
            } else if (eps1p01 < prod) {
                x *= 0.5;
            printf("prod > eps1m01 x=%.12f\t,ax=%.12f\n",x, a*x);
            } else {
                break;
            }
        }
            printf("out x=%.12f\t,ax=%.12f\n",x, a*x);
        for (;;) { // Heron approximation
            double prod = a*x;
            if ((prod < eps1m24) || (eps1p24 < prod)) {
                x *= (2.0 - prod );
            } else {
                break ;
            }
        }
        printf ("heron: a=%.5e,\tx=%.5e,\ta*x =%.12f\n",
                a, x, a*x);
    }
    return EXIT_SUCCESS;
}
