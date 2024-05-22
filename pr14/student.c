#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "stack.h"

void* infoOutput(void*);
void* saveToTxt(void*);

void* studentInit(void *surname, void *name, void *sex, int age, int group, float mathMark, float physicsMark, float chemistryMark) {
    struct Student* result = (struct Student*)malloc(sizeof(struct Student));
    if (result == NULL) {
        printf("Ошибка выделения памяти для студента.\n");
        return NULL;
    }

    result->surname = strdup((char*)surname);
    result->name = strdup((char*)name);
    result->sex = strdup((char*)sex);
    result->age = age;
    result->group = group;
    result->mathMark = mathMark;
    result->physicsMark = physicsMark;
    result->chemistryMark = chemistryMark;
    result->infoOutput = infoOutput;
    result->saveToTxt = saveToTxt;
    return result;
}

void* infoOutput(void* student) {
    struct Student* s = (struct Student*)student;
    printf("Фамилия: %s\n", s->surname);
    printf("Имя: %s\n", s->name);
    printf("Пол: %s\n", s->sex);
    printf("Возраст: %d\n", s->age);
    printf("Группа: %d\n", s->group);
    printf("Отметка по математике: %.1f\n", s->mathMark);
    printf("Отметка по физике: %.1f\n", s->physicsMark);
    printf("Отметка по химии: %.1f\n", s->chemistryMark);
    printf("\n");
    return NULL;
}

void* saveToTxt(void* student) {
    struct Student* _student = (struct Student*)student;

    FILE* in = fopen("data.txt", "a");
    if (in == NULL) {
        perror("Ошибка открытия файла");
        return NULL;
    }

    fprintf(in, "%s %s %s %d %d %.1f %.1f %.1f\n", _student->surname, _student->name, _student->sex, _student->age, _student->group, _student->mathMark, _student->physicsMark, _student->chemistryMark);
    fclose(in);

    return NULL;
}
