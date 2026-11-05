#include <stdio.h>
#include <math.h>

int main() {
    double eps = 1e-6;
    printf("Enter precision: ");
    if (scanf("%lf", &eps) != 1 || eps <= 0) {
        printf("incorrect input.\n");
        return 1;
    }

    double pi = 2.0;
    double prev_pi;
    long long i = 1;

    do {
        prev_pi = pi;
        double term;

        if (i % 2 != 0) {
            term = (double)(i + 1) / i;
        } else {
            term = (double)i / (i + 1);
        }

        pi *= term;
        i++;
    } while (fabs(pi - prev_pi) >= eps);

    printf("pi = %lf\n", pi);
    printf("Real value of pi = %lf\n", M_PI);
    printf("Number of iterations: %lld\n", i);

    return 0;
}

