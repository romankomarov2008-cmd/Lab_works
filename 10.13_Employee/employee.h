//
// Created by Роман on 15.11.2026.
//

#ifndef UNTITLED21_EMPLOYEE_H
#define UNTITLED21_EMPLOYEE_H
#define MAX_STR 64

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char surname[MAX_STR];
    char name[MAX_STR];
    char gender[16];
    Date birth_date;
    char position[MAX_STR];
} Employee;

void printEmployee(const Employee *employee);
void printAllEmployees(const Employee P[], int n);
void findMostCommonPosition(const Employee P[], int n);
void findSameName(const Employee P[], int n);
void findBySurnameLetter(const Employee P[], int n, const char *letter);


#endif //UNTITLED21_EMPLOYEE_H
