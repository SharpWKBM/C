#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "stack.h"

int main() {
    system("chcp 65001");

    struct Student* student1 = (struct Student*)studentInit("test1", "test1", "m", 11, 207, 5.0, 5.0, 5.0);
    struct Student* student2 = (struct Student*)studentInit("test2", "test2", "m", 11, 207, 5.0, 5.0, 2.2);
    struct Student* student3 = (struct Student*)studentInit("test3", "test3", "m", 11, 206, 5.0, 5.0, 5.0);

    void* students = stackInit(NULL);

    struct StackElem stdPushElems;
    stdPushElems.stack = students;

    stdPushElems.elem = student1;
    stdPushElems.stack->push(&stdPushElems);

    stdPushElems.elem = student2;
    stdPushElems.stack->push(&stdPushElems);

    stdPushElems.elem = student3;
    stdPushElems.stack->push(&stdPushElems);

    printf("Обычный вывод:\n");
    while (((struct Stack*)students)->size > 0) {
        struct Student* tmp = (struct Student*)((struct Stack*)students)->pop(students);
        if (tmp->group == 207 && tmp->mathMark == 5.0 && tmp->physicsMark == 5.0 && tmp->chemistryMark == 5.0) {
            tmp->infoOutput(tmp);
        }
        free(tmp);
    }

    free(students);


    struct Student* st1 = (struct Student*)studentInit("test1", "test1", "f", 11, 207, 5.0, 5.0, 5.0);
    struct Stack* studs = stackInit(NULL);

    studs->loadFromTxt(studs);

    printf("Файловый вывод:\n");
    while (((struct Stack*)studs)->size > 0) {
        struct Student* tmp = (struct Student*)((struct Stack*)studs)->pop(studs);
        if (strcmp(tmp->sex, "f") == 0 && tmp->physicsMark == 5.0 && tmp->chemistryMark == 5.0) {
            tmp->infoOutput(tmp);
        }
        free(tmp);
    }

    st1->saveToTxt(st1);
    free(studs);

    return 0;
}
