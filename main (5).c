#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 5
int input_array(int mas[], int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        printf("Enter a value for mas[%d]: ", i);
        if (scanf("%lf", &mas[i]) != 1) {
            printf("Wrong input. Please enter a number\n");
            return i;
        }
    }
    return i;
}
void print_array(int mas[], int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        printf("%d ", mas[i]);
    }
    printf("\n");
}
int number_of_elements_less_than_a(const int mas[], int size, double a) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (mas[i] < a) {
            count++;
        }
    }
}
void task1() {
    int mas[] = {1, 7, 2, 4, 5};

    double a;
    int k = 0;
    printf("Enter a value for a: ");
    scanf("%lf", &a);

    int realSize = sizeof(mas)/sizeof(mas[0]);

    for (int i = 0; i < SIZE; i++) {
        if (mas[i] < a) {
            printf("%d ", mas[i]);
            k++;
        }
    }
    printf("\nNumber of elements less than %g: %d\n", a, k);
    int count = number_of_elements_less_than_a(mas, realSize, a);
    printf("\nNumber of elements greater than %g(using function): %d\n", a, count);
}

int main() {
    task1();
}
