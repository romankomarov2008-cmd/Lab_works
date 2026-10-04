#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    double r, R;
    double r0, R0, volume;

    printf("Enter the inner radius of a torus (r): ");
    if (scanf("%lf", &r) != 1 || r <= 0) {
        printf("Error! Radius must be over zero\n");
        return 1;
    }

    printf("Enter the outer radius of the torus (R): ");
    if (scanf("%lf", &R) != 1 || R <= r) {
        printf("Error! Outer radius must be greater than inner.\n");
        return 1;
    }

    R0 = (R + r) / 2.0;
    r0 = (R - r) / 2.0;

    volume = 2.0 * pow(M_PI, 2) * R0 * pow(r0, 2);

    printf("\nResults:\n");
    printf("Radius of the tube (r0): %.4f\n", r0);
    printf("Radius of inner circle (R0): %.4f\n", R0);
    printf("Volume of the torus (V): %.4f\n", volume);

    return 0;
}
