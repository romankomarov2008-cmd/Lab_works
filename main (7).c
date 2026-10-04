#include <stdio.h>
#include <math.h>

double exp_tailor(double x, double epsilon);
double term = 1, int k = 1;
y = term;
while (fabs(term) >= epsilon) {
    term = term * x/k;
    y += term; k++;

}
return y;
