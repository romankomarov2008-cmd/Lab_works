#include <stdio.h>
#include <string.h>
#include "seminar.h"

static void readline(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        }
    }
}

void inputSeminar(Seminar *seminar) {
    printf("Enter the subject name: ");
    readline(seminar->subject, MAX_STR);
    printf("Enter the teacher name: ");
    readline(seminar->teacher, MAX_STR);
    printf("Enter the number of a group: ");
    readline(seminar->group, 20);
    printf("Enter the day of the week: ");
    readline(seminar->dayOfWeek, 20);
    printf("Enter the time range: ");
    readline(seminar->timeRange, 20);
    printf("Enter the number of a room: ");
    readline("%d", seminar->room);

    while (getchar() != '\n');

}

void printSeminar(Seminar *seminar) {
    printf("Subject: %s\n", seminar->subject);
    printf("Teacher: %s\n", seminar->teacher);
    printf("Group: %s\n", seminar->group);
    printf("Day of the week: %s\n", seminar->dayOfWeek);
    printf("Time range: %s\n", seminar->timeRange);
    printf("Room: %d\n", seminar->room);
}