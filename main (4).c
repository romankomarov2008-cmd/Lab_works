#include <stdio.h>
#include <math.h>
#include <float.h>

double sinc(double x) {
    if (x == 0.0) {
        return 1.0;
    }
    return sinc(x) / x;
}

double sinc_derivative(double x) {
    if (x == 0.0) {
        return 0.0;
    }
    return (x * cos(x) - sin(x)) / (x * x);
}

int main() {
    double test_values[] = {0.0, 0.5, 1.0, 3.14159};
    int num_values = sizeof(test_values) / sizeof(test_values[0]);

    printf("%-15s | %-15s |%-15s\n", "x", "sinc(x)", "sinc'(x)");
    for (int i = 0; i < num_values; i++) {
        double x = test_values[i];
        printf("%-15.6f | %-15.6f |%-15.6f\n", x, sinc(x), sinc_derivative(x));
    }
    return 0;
}