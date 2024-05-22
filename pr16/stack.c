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
}

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
}

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
}

void* loadFromBinary(void* stack) {
    struct Stack* _stack = (struct Stack*)stack;
    if (_stack == NULL) {
        perror("Ошибка: передан нулевой указатель на стек");
        return NULL;
    }

    FILE* fp = fopen("data.bin", "rb");
    if (fp == NULL) {
        perror("Ошибка при открытии файла для чтения");
        return NULL;
    }

    struct StackElem tmpPush;
    tmpPush.stack = _stack;

    while (1) {
        int surnameSize;
        int nameSize;
        int sexSize;

        if (fread(&surnameSize, sizeof(int), 1, fp) != 1) break;
        char* surname = (char*)calloc(surnameSize + 1, sizeof(char));
        fread(surname, sizeof(char), surnameSize, fp);

        if (fread(&nameSize, sizeof(int), 1, fp) != 1) break;
        char* name = (char*)calloc(nameSize + 1, sizeof(char));
        fread(name, sizeof(char), nameSize, fp);

        if (fread(&sexSize, sizeof(int), 1, fp) != 1) break;
        char* sex = (char*)calloc(sexSize + 1, sizeof(char));
        fread(sex, sizeof(char), sexSize, fp);

        int age;
        fread(&age, sizeof(int), 1, fp);
        int group;
        fread(&group, sizeof(int), 1, fp);
        float mathMark;
        fread(&mathMark, sizeof(float), 1, fp);
        float physicsMark;
        fread(&physicsMark, sizeof(float), 1, fp);
        float chemistryMark;
        fread(&chemistryMark, sizeof(float), 1, fp);

        if (feof(fp)) {
            free(surname);
            free(name);
            free(sex);
            break;
        }

        struct Student* _student = (struct Student*)studentInit(surname, name, sex, age, group, mathMark, physicsMark, chemistryMark);

        if (_student != NULL && strcmp(_student->sex, "f") == 0 && _student->physicsMark == 5.0 && _student->chemistryMark == 5.0) {
            tmpPush.elem = _student;
            _stack->push(&tmpPush);
        } else {
            free(_student->surname);
            free(_student->name);
            free(_student->sex);
            free(_student);
        }

        free(surname);
        free(name);
        free(sex);
    }

    fclose(fp);
    return NULL;
}