#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
    double r;
} Circle;

void check_circles_intersection(Circle c1, Circle c2) {
    if (c1.r <= 0 || c2.r <= 0) {
        printf("Error! Radius must be over zero\n");
        return;
    }

    double dx = c2.x - c1.x;
    double dy = c2.y - c1.y;

    double d = sqrt(dx * dx + dy * dy);

    double sum_r = c1.r + c2.r;
    double diff_r = fabs(c1.r - c2.r);

    double epsilon = 1e-9;

    if (d < epsilon && fabs(c1.r - c2.r) < epsilon) {
        printf("Circles coincide (infinite number of common points)\n");
    } else if (fabs(d - sum_r) < epsilon) {
        printf("Circles touch from the outside (1 common point)\n");
    } else if (fabs(d - diff_r) < epsilon) {
        printf("Circles touch from inside (1 common point)\n");
    } else if (d < sum_r && d > diff_r) {
        printf("Circles intersect (2 common points)\n");
    } else if (d > sum_r) {
        printf("Circles don't intersect (no common points)\n");
    } else { // d < diff_r
        printf("One circle is inside another (no intersection)\n");
    }
}

int main() {
    Circle c1, c2;

    printf("Enter x, y, radius of the first circle:\n: ");
    if (scanf("%lf %lf %lf", &c1.x, &c1.y, &c1.r) != 3) {
        printf("Wrong input\n");
        return 1;
    }

    printf("Enter x, y, radius of the second circle:\n: ");
    if (scanf("%lf %lf %lf", &c2.x, &c2.y, &c2.r) != 3) {
        printf("Wrong input\n");
        return 1;
    }

    check_circles_intersection(c1, c2);

    return 0;
}
