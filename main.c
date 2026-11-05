#include <stdio.h>

int main() {
    double x;
    int k;

    printf("Enter a value for x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Wrong input\n");
        return 1;
    }

    printf("Enter a value for k: ");
    if (scanf("%d", &k) != 1 || k < 1) {
        printf("Wrong input\n");
        return 1;
    }

    double x_power = 1.0;
    for (int i = 1; i < k; i++) {
        x_power *= x;
    }

    double x_k = x_power / k;

    printf("element x_%d = %lf\n", k, x_k);
    return 0;
}
