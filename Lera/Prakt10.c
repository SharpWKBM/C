#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Gender {
    MALE,
    FEMALE
} GENDER;

typedef struct Group {
    char spec[32];
    int number;
} GROUP;

typedef struct Score {
    int math;
    int physics;
    int chemistry;
} SCORE;

typedef struct Student {
    char surname[32];
    char name[32];
    GENDER gender;
    int age;
    GROUP group;
    SCORE score;
} STUDENT;

typedef struct Node {
    STUDENT data;
    struct Node* next;
} NODE;

NODE* pushStudent(NODE*, STUDENT);
NODE* popStudent(NODE*);
void printStudents(NODE*);
void swapStudents(NODE*, NODE*);
void sortStudents(NODE*);

int main() {
    NODE* top = NULL;
    STUDENT student;
    int number;

    printf("Number of students: ");
    scanf("%d", &number);

    for (int i = 0; i < number; i++) {
        printf("Student's name: ");
        scanf("%s", student.name);
        top = pushStudent(top, student);
    }

    printf("До Сорты:\n");
    printStudents(top);

    sortStudents(top);

    printf("После Сорты:\n");
    printStudents(top);

    while (top)
        top = popStudent(top);

    return 0;
}

NODE* pushStudent(NODE* top, STUDENT student) {
    NODE* ptr = malloc(sizeof(NODE));
    ptr->data = student;
    ptr->next = top;
    return ptr;
};

NODE* popStudent(NODE* top) {
    if (top == NULL)
        return top;

    NODE* ptr = top->next;
    free(top);
    return ptr;
};

void printStudents(NODE* top) {
    NODE* ptr = top;

    while (ptr != NULL) {
        printf("%s\n", ptr->data.name);
        ptr = ptr->next;
    }
}

void swapStudents(NODE* a, NODE* b) {
    STUDENT temp = a->data;
    a->data = b->data;
    b->data = temp;
};

void sortStudents(NODE* top) {
    int swapped;
    NODE* ptr;
    NODE* last = NULL;

    if (top == NULL)
        return;

    do {
        swapped = 0;
        ptr = top;

        while (ptr->next != last) {
            if (strcmp(ptr->data.name, ptr->next->data.name) > 0) {
                swapStudents(ptr, ptr->next);
                swapped = 1;
            }
            ptr = ptr->next;
        }
        last = ptr;
    } while (swapped);
};
