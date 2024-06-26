#ifndef STUDENT_H
#define STUDENT_H
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
Student* InitStudent(int age, char* name, char* surname, char* gender, char* group, int mathGrade, int physicGrade, int chemistryGrade);
#endif // STUDENT_H
