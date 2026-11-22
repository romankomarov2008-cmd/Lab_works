#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter a number n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Wrong input\n");
        return 1;
    }

    FILE *file = fopen("file.txt", "r");
    FILE *file2 = fopen("file2.txt", "w");

    if (file == NULL || file2 == NULL) {
        printf("Error opening file\n");
        if (file) fclose(file);
        if (file2) fclose(file2);
        return 1;
    }

    int number;
    int max_val;
    int count = 0;

    while (fscanf(file, "%d", &number) == 1) {
        if (count == 0) {
            max_val = number;
        } else if (number > max_val) {
            max_val = number;
        }
        count++;

        if (count == n) {
            fprintf(file2, "%d\n", max_val);
            count = 0;
        }
    }

    if (count > 0) {
        fprintf(file2, "%d\n", max_val);
    }
    fclose(file);
    fclose(file2);

    printf("Done\n");
    return 0;
}
