#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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

typedef struct List {
    Node* head;
    Node* tail;
    int size;

    void (*append)(struct List*, struct Student*);
    void (*printE)(struct List*);
    void (*print)(struct List*);
    void (*free)(struct List*);
} List;

void Append(List*, Student*);
void PrintExcellentFemaleStudents(List*);
void PrintList(List*);
void FreeList(List*);

void Append(List* list, Student* student) {
    Node* newNode = malloc(sizeof(Node));
    newNode->student = student;
    newNode->next = NULL;

    if (list->size == 0) {
        list->head = newNode;
        list->tail = list->head;
    }
    else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
}

void PrintExcellentFemaleStudents(List* list) {
    Node* current = list->head;
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

void PrintList(List* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%s - %d\n", current->student->name, current->student->physicGrade);
        current = current->next;
    }
}

void FreeList(List* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp->student);
        free(temp);
    }
    free(list);
}

int main() {
    setlocale(LC_ALL, "RUS");
    List* StudentList = InitList();
    StudentList->append(StudentList, InitStudent(23, "Ksenia", "Tfgd", "жен", "ghgjf4", 4, 5, 5));
    StudentList->append(StudentList, InitStudent(14, "Vaho", "Tfgd", "муж", "ghgjf4", 4, 4, 3));
    StudentList->append(StudentList, InitStudent(17, "Timur", "Tfgd", "муж", "ghgjf4", 4, 3, 3));
    StudentList->printE(StudentList);

    StudentList->free(StudentList);
    return 0;
}