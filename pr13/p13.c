#include "list.h"
#include "UniversalPointer.h"
#include "student.h"
#include <stdio.h>
#include <locale.h>

int main() {
    UniversalPointer* universalPointer = malloc(sizeof(UniversalPointer));
    setlocale(LC_ALL, "RUS");
    List* StudentList = InitList();
    universalPointer->list = StudentList;
    universalPointer->student = InitStudent(23, "Ksenia", "Tfgd", "���", "ghgjf4", 4, 5, 5);
    StudentList->append(universalPointer);
    universalPointer->student = InitStudent(14, "Vaho", "Tfgd", "���", "ghgjf4", 4, 4, 3);
    StudentList->append(universalPointer);
    universalPointer->student = InitStudent(17, "Timur", "Tfgd", "���", "ghgjf4", 4, 3, 3);
    StudentList->append(universalPointer);
    StudentList->printE(universalPointer);

    StudentList->free(StudentList);
    return 0;
}