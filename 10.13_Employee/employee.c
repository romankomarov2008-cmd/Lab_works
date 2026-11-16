#include <stdio.h>
#include <string.h>
#include "employee.h"

void printEmployee(const Employee *emp) {
    printf("%-15s %-12s | Gender: %-8s | Birth date: %02d.%02d.%04d | Position: %s\n",
        emp->surname,
        emp->name,
        emp->gender,
        emp->birth_date.day,
        emp->birth_date.month,
        emp->birth_date.year,
        emp->position);
}

void printAllEmployees(const Employee P[], int n) {
    printf("---The list of employees are (%d) ---\n");
    for (int i = 0; i < n; i++) {
        printf("%2d. ", i + 1);
        printEmployee(&P[i]);
    }
    printf("\n");
}

void FindMostCommonPosition(const Employee P[], int n) {
    printf("--- а) Most common position: ---\n");
    if (n <= 0) {
        printf("Empty array.\n\n");
        return;
    }
}

int max_count = 0;
int best_index = 0;
int n;
for (int i = 0; i < n; i++) {
    int count = 0;
    for (int j = 0; j < n; j++) {
        if (strcmp(P[i].position, P[j].position) == 0) {
            count++;
        }
    }
    if (count > max_count) {
        max_count = count;
        best_index = i;
    }

    printf("Position: \"%s\"(Number of employees): %d\n\n", P[best_index].position, max_count);
}

void findSameName(const Employee P[], int N) {
    printf("---b) Employees with same name: ---\n");
    int found_any = 0;

    for (int i = 0; i < N; i++) {
        int already_checked = 0;
        for (int k = 0; k < i; k++) {
            if (strcmp(P[i].name, P[k].name) == 0) {
                already_checked = 1;
                break;
            }
        }
        if (already_checked) continue;
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (strcmp(P[i].name, P[j].name) == 0) {
                count++;
            }
        }
        if (count > 1) {
            found_any = 1;
            printf("Name \"%s\" (%d people):\n", P[i].name, count);
            for (int j = 0; j < N; j++) {
                if (strcmp(P[i].name, P[j].name) == 0) {
                    printf(" * ");
                    printEmployee(&P[j]);
                }
            }
        }
    }

    if (!found_any) {
        printf("No employees with same name.\n");
    }
    printf("\n");
}

void findBySurnameLetter(const Employee P[], int N, const char *letter) {
    printf("--- c) Employees which names start with: \"%s\" ---\n", letter);
    size_t len = strlen(letter);
    int found = 0;

    for (int i = 0; i < N; i++) {
        if (strncmp(P[i].surname, letter, len) == 0) {
            printEmployee(&P[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("Employees for a letter \"%s\" not found.\n", letter);
    }
    printf("\n");
}


