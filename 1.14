#include <stdio.h>

int main() {
    double a, t, v;
    double dist, time_to_speed;

    printf("Enter acceleration (a): ");
    scanf("%lf", &a);
    printf("Enter time (t): ");
    scanf("%lf", &t);
    printf("Enter velocity (v): ");
    scanf("%lf", &v);

    if (a <= 0) {
        printf("Error! Acceleration must be greater than zero!\n");
        return 1;
    }

    dist = (a / t * t) / 2.0;
    time_to_speed = v / a;

    printf("\n--- results ---\n");
    printf("distance: %.2f\n", dist);
    printf("time at which the speed v will be reached: %.2f\n", time_to_speed);
    return 0;
}
