#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "student.h"
#include "stack.h"


void* infoOutput(void*);
void* saveToBinary(void*);

void* studentInit(void *surname, void *name, void *sex, int age, int group, float mathMark, float physicsMark, float chemistryMark) {
    struct Student* result = (struct Student*)malloc(sizeof(struct Student));
    if (result == NULL) {
        printf("Ошибка выделения памяти для студента.\n");
        return NULL;
    }

    if (surname != NULL)
        result->surname = strdup((char*)surname);
    else
        result->surname = NULL;

    if (name != NULL)
        result->name = strdup((char*)name);
    else
        result->name = NULL;

    if (sex != NULL)
        result->sex = strdup((char*)sex);
    else
        result->sex = NULL;

    result->age = age;
    result->group = group;
    result->mathMark = mathMark;
    result->physicsMark = physicsMark;
    result->chemistryMark = chemistryMark;
    result->infoOutput = infoOutput;
    result->saveToBinary = saveToBinary;
    return result;
}

void* infoOutput(void* student) {
    if (student == NULL) {
        perror("Ошибка: передан нулевой указатель на студента");
        return NULL;
    }
    
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

void* saveToBinary(void* student) {
    if (student == NULL) {
        perror("Ошибка: передан нулевой указатель на студента");
        return NULL;
    }

    struct Student* _student = (struct Student*)student;
    FILE* fp = fopen("data.bin", "ab");

    if (fp == NULL) {
        perror("Ошибка при открытии файла!");
        return NULL;
    }

    int surnameSize = strlen(_student->surname);
    int nameSize = strlen(_student->name);
    int sexSize = strlen(_student->sex);

    fwrite(&surnameSize, sizeof(int), 1, fp);
    fwrite(_student->surname, sizeof(char), surnameSize, fp);
    fwrite(&nameSize, sizeof(int), 1, fp);
    fwrite(_student->name, sizeof(char), nameSize, fp);
    fwrite(&sexSize, sizeof(int), 1, fp);
    fwrite(_student->sex, sizeof(char), sexSize, fp);
    fwrite(&_student->age, sizeof(int), 1, fp);
    fwrite(&_student->group, sizeof(int), 1, fp);
    fwrite(&_student->mathMark, sizeof(float), 1, fp);
    fwrite(&_student->physicsMark, sizeof(float), 1, fp);
    fwrite(&_student->chemistryMark, sizeof(float), 1, fp);


    fclose(fp);

    return NULL;
}
