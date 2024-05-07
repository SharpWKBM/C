#include "list.h"
#include "stasik.h"
#include "student.h"
#include <stdio.h>
#include <locale.h>

int main() {
    Stasik* stasik = malloc(sizeof(Stasik));
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