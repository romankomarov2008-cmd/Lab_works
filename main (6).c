#include <stdio.h>
#include <math.h>
double exp_tailor(double x, double epsilon);
int main() {
    double x, epsilon, y;
    printf("x= "); scanf("%lf", &x);
    while (epsilon <= 0) {
        printf("epsilon= "); scanf("%lf", &epsilon);

    }
    y = exp_tailor(x, epsilon);
    printf("y= %lf %lf", y, exp(x));
}
