#include <stdio.h>
#include "seminar.h"

int main() {
    Seminar testSeminar = {
        "Algebra",
        "Bondarenko E.V",
        "МАТ ШІ 1",
        "Wednesday",
        "12:20 - 13:55",
        303
    };
    printf("Test Seminar\n:");
    printSeminar(&testSeminar);

    Seminar userSeminar;
    printf("Fill in the data of the new seminar\n");
    inputSeminar(&userSeminar);
    printSeminar(&userSeminar);

    return 0;
}
