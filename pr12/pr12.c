#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct Node {
    struct Student* student;
    struct Node* next;
} Node;

typedef struct Student {
    int age;
    char* name;
    char* surname;
    char* gender;
    char* group;
    int mathGrade;
    int physicGrade;
    int chemistryGrade;
} Student;

typedef struct Stasik {
    struct List* list;
    struct Student* student;
} Stasik;
typedef struct List {
    Node* head;
    Node* tail;
    int size;

    void* (*append)(void*);
    void* (*printE)(void*);
    void* (*print)(void*);
    void* (*free)(void*);
} List;

void* Append(void *);
void* PrintExcellentFemaleStudents(void*);
void* PrintList(void*);
void* FreeList(void*);

void* Append(void* args) {
    Stasik* stasik = (Stasik*)args;
    Node* newNode = malloc(sizeof(Node));
    newNode->student = stasik -> student;
    newNode->next = NULL;

    if (stasik -> list->size == 0) {
        stasik -> list->head = newNode;
        stasik -> list->tail = stasik -> list->head;
    }
    else {
        stasik -> list->tail->next = newNode;
        stasik -> list->tail = newNode;
    }
    stasik -> list->size++;
}

void* PrintExcellentFemaleStudents(void* args) {
    Stasik* stasik = (Stasik*)args;
    Node* current = stasik->list ->head;
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

Student* InitStudent(int age, char* name, char* surname, char* gender, char* group, int mathGrade, int physicGrade, int chemistryGrade) {
    Student* student = malloc(sizeof(Student));
    student->name = name;
    student->surname = surname;
    student->gender = gender;
    student->group = group;
    student->mathGrade = mathGrade;
    student->physicGrade = physicGrade;
    student->chemistryGrade = chemistryGrade;
    student->age = age;
    return student;
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

int main() {
    Stasik* stasik = malloc(sizeof (Stasik));
    setlocale(LC_ALL, "RUS");
    List* StudentList = InitList();
    stasik->list = StudentList;
    stasik->student = InitStudent(23, "Ksenia", "Tfgd", "жен", "ghgjf4", 4, 5, 5);
    StudentList->append(stasik);
    stasik->student = InitStudent(14, "Vaho", "Tfgd", "муж", "ghgjf4", 4, 4, 3);
    StudentList->append(stasik);
    stasik->student = InitStudent(17, "Timur", "Tfgd", "муж", "ghgjf4", 4, 3, 3);
    StudentList->append(stasik);
    StudentList->printE(stasik);

    StudentList->free(StudentList);
    return 0;
}