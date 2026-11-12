#include <stdio.h>

int main() {
    int n;
    double a = 1.0;
    double coeff = 1.0;
    double sum = 0.0;

    printf("Enter value of n: ");
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("Wrong input\n");
        return 1;
    }

    for (int k = 1; k <= n; k++) {
        a = k * a + 1.0 / k;
        coeff = coeff * 2.0 / k;
        sum = coeff * a;
    }

    printf("The sum S_%d = %.6lf\n", n, sum);
}


