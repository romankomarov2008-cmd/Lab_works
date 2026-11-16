//
// Created by Роман on 15.11.2026.
//

#ifndef UNTITLED20_SEMINAR_H
#define UNTITLED20_SEMINAR_H

#define MAX_STR 100

typedef struct {
    char subject[MAX_STR];
    char teacher[MAX_STR];
    char group[20];
    char dayOfWeek[20];
    char timeRange[20];
    int room;
} Seminar;

void inputSeminar(Seminar *seminar);
void printSeminar(Seminar *seminar);

#endif //UNTITLED20_SEMINAR_H
