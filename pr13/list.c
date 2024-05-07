#include "list.h"
#include "student.h"
#include "stasik.h"
#include <stdio.h>

List* InitList() {
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->append = Append;
    list->print = PrintList;
    list->free = FreeList;
    list->printE = PrintExcellentFemaleStudents;
    return list;
}
void* Append(void* args) {
    Stasik* stasik = (Stasik*)args;
    Node* newNode = malloc(sizeof(Node));
    newNode->student = stasik->student;
    newNode->next = NULL;

    if (stasik->list->size == 0) {
        stasik->list->head = newNode;
        stasik->list->tail = stasik->list->head;
    }
    else {
        stasik->list->tail->next = newNode;
        stasik->list->tail = newNode;
    }
    stasik->list->size++;
}

void* PrintExcellentFemaleStudents(void* args) {
    Stasik* stasik = (Stasik*)args;
    Node* current = stasik->list->head;
    while (current != NULL) {
        if (strcmp(current->student->gender, "жен") == 0 && current->student->physicGrade == 5 && current->student->chemistryGrade == 5) {
            printf("Name: %s %s\n", current->student->name, current->student->surname);
            printf("Group: %s\n", current->student->group);
            printf("Age: %d\n", current->student->age);
            printf("Math Grade: %d\n", current->student->mathGrade);
            printf("Physic Grade: %d\n", current->student->physicGrade);
            printf("Chemistry Grade: %d\n\n", current->student->chemistryGrade);
        }
        current = current->next;
    }
}
void* PrintList(void* args) {
    Stasik* stasik = (Stasik*)args;
    Node* current = stasik->list->head;
    while (current != NULL) {
        printf("%s - %d\n", current->student->name, current->student->physicGrade);
        current = current->next;
    }
}

void* FreeList(void* args) {
    Stasik* stasik = (Stasik*)args;
    Node* current = stasik->list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp->student);
        free(temp);
    }
    free(stasik->list);
}