#include "list.h"
#include "student.h"
#include "UniversalPointer.h"
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
    UniversalPointer* universalPointer = (UniversalPointer*)args;
    Node* newNode = malloc(sizeof(Node));
    newNode->student = universalPointer->student;
    newNode->next = NULL;

    if (universalPointer->list->size == 0) {
        universalPointer->list->head = newNode;
        universalPointer->list->tail = universalPointer->list->head;
    }
    else {
        universalPointer->list->tail->next = newNode;
        universalPointer->list->tail = newNode;
    }
    universalPointer->list->size++;
}

void* PrintExcellentFemaleStudents(void* args) {
    UniversalPointer* universalPointer = (UniversalPointer*)args;
    Node* current = universalPointer->list->head;
    while (current != NULL) {
        if (strcmp(current->student->gender, "���") == 0 && current->student->physicGrade == 5 && current->student->chemistryGrade == 5) {
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
    UniversalPointer* universalPointer = (UniversalPointer*)args;
    Node* current = universalPointer->list->head;
    while (current != NULL) {
        printf("%s - %d\n", current->student->name, current->student->physicGrade);
        current = current->next;
    }
}

void* FreeList(void* args) {
    UniversalPointer* universalPointer = (UniversalPointer*)args;
    Node* current = universalPointer->list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp->student);
        free(temp);
    }
    free(universalPointer->list);
}