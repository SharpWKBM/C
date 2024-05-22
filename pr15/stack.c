#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "student.h"
#include "stack.h"


void* push_stack(void*);
void* pop_stack(void*);
void* loadFromBinary(void*);

void* stackInit(void* result) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        perror("Ошибка выделения памяти для стека");
        return NULL;
    }
    stack->head = NULL;
    stack->size = 0;
    stack->push = push_stack;
    stack->pop = pop_stack;
    stack->loadFromBinary = loadFromBinary;
    return stack;
};

void* push_stack(void* _stackElem) {
    if (_stackElem == NULL) {
        perror("Ошибка: передан нулевой указатель на элемент стека");
        return NULL;
    }
    struct StackElem* tmp = (struct StackElem*)_stackElem;
    struct Node* new_head = malloc(sizeof(struct Node));
    if (new_head == NULL) {
        perror("Ошибка выделения памяти для нового узла стека");
        return NULL;
    }

    new_head->data = *((struct Student*)tmp->elem);
    new_head->next = tmp->stack->head;
    tmp->stack->head = new_head;
    tmp->stack->size += 1;
    return NULL;
};

void* pop_stack(void* stack) {
    if (stack == NULL) {
        perror("Ошибка: передан нулевой указатель на стек");
        return NULL;
    }
    struct Stack* _stack = (struct Stack*)stack;
    if (_stack->size == 0) {
        return NULL;
    }
    struct Node* elem = _stack->head;
    struct Student* result = malloc(sizeof(struct Student));
    if (result == NULL) {
        perror("Ошибка выделения памяти для результата извлечения из стека");
        return NULL;
    }
    *result = _stack->head->data;
    _stack->head = _stack->head->next;
    _stack->size -= 1;
    free(elem);
    return result;
};

void* loadFromBinary(void* stack) {
    struct Stack* _stack = (struct Stack*)stack;
    if (stack == NULL) {
        perror("Ошибка: передан нулевой указатель на стек");
        return NULL;
    }

    FILE* fp = fopen("data.bin", "rb");
    if (fp == NULL) {
        perror("Ошибка при открытии файла для чтения");
        return NULL;
    }

    struct Student* _student = (struct Student*)studentInit(NULL, NULL, NULL, 0, 0, 0.0, 0.0, 0.0);
    if (_student == NULL) {
        perror("Ошибка выделения памяти для студента");
        fclose(fp);
        return NULL;
    }
    struct StackElem* tmpPush = (struct StackElem*)malloc(sizeof(struct StackElem));
    if (tmpPush == NULL) {
        perror("Ошибка выделения памяти для элемента стека");
        fclose(fp);
        return NULL;
    }

    tmpPush->stack = _stack;

    while(!feof(fp)) {
        int surnameSize;
        int nameSize;
        int sexSize;

        fread(&surnameSize, sizeof(int), 1, fp);
        _student->surname = calloc(surnameSize, sizeof(char));
        fread(_student->surname, sizeof(char), surnameSize, fp);

        fread(&nameSize, sizeof(int), 1, fp);
        _student->name = calloc(nameSize, sizeof(char));
        fread(_student->name, sizeof(char), nameSize, fp);

        fread(&sexSize, sizeof(int), 1, fp);
        _student->sex  = calloc(sexSize, sizeof(char));
        fread(_student->sex, sizeof(char), sexSize, fp);

        fread(&_student->age, sizeof(int), 1, fp);
        fread(&_student->group, sizeof(int), 1, fp);
        fread(&_student->mathMark, sizeof(float), 1, fp);
        fread(&_student->physicsMark, sizeof(float), 1, fp);
        fread(&_student->chemistryMark, sizeof(float), 1, fp);

        if(strlen(_student->surname) != 0){
            _student->infoOutput(_student);
            tmpPush->elem = _student;
            _stack->push(tmpPush);
        }

        free(_student->surname);
        free(_student->name);
        free(_student->sex);
    }

    fclose(fp);
    return NULL;
}
