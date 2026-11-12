#include <stdio.h>
#include <math.h>

int main() {
    double x, epsilon;
    printf("Enter a value for x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter epsilon value: ");
    if (scanf("%lf", &epsilon) != 1 || epsilon <= 0) {
        printf("Invalid input! epsilon must be over zero\n");
        return 1;
    }

    double S = 0.0;
    double a = 1.0;
    int k = 1;

    while (fabs(a) >= epsilon) {
        S += a;
        k++;
        a = a * (x * x) / ((2.0 * k - 3.0) * (2.0 * k - 2.0));
    }
    printf("\nApproximate value of cosh(%.4f) = %.10f\n", x, S);
    printf("\nExact value of cosh(%.4f) = %.10f\n", cosh(x));
    printf("\nNumber of iterations: %d\n", k - 1);
    return 0;
}
