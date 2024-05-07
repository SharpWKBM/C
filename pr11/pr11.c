#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct Student {
    int age;
    char* name;
    char* surname;
    char* gender;
    char* group;
    int mathGrade;
    int physicGrade;
    int chemistryGrade;
    struct Student* left;
    struct Student* right;

    void (*printInfo)(struct Student*);
    void (*printExcellentFemaleStudents)(struct Student*);

} Student;

void PrintInfo(struct Student* student) {
    printf("Name: %s %s\n", student->name, student->surname);
    printf("Group: %s\n", student->group);
    printf("Age: %d\n", student->age);
    printf("Math Grade: %d\n", student->mathGrade);
    printf("Physic Grade: %d\n", student->physicGrade);
    printf("Chemistry Grade: %d\n\n", student->chemistryGrade);
}

void PrintExcellentFemaleStudents(struct Student* root) {
    if (root == NULL) {
        return;
    }

    PrintExcellentFemaleStudents(root->left);

    if (strcmp(root->gender, "жен") == 0 && root->physicGrade == 5 && root->chemistryGrade == 5) {
        root->printInfo(root);
    }

    PrintExcellentFemaleStudents(root->right);
}

struct Student* InitStudent(int age, char* name, char* surname, char* gender, char* group, int mathGrade, int physicGrade, int chemistryGrade) {
    struct Student* student = malloc(sizeof(struct Student));
    student->name = strdup(name);
    student->surname = strdup(surname);
    student->gender = strdup(gender);
    student->group = strdup(group);
    student->mathGrade = mathGrade;
    student->physicGrade = physicGrade;
    student->chemistryGrade = chemistryGrade;
    student->age = age;
    student->left = NULL;
    student->right = NULL;
    student->printInfo = PrintInfo;
    student->printExcellentFemaleStudents = PrintExcellentFemaleStudents;
    return student;
}

void FreeTree(struct Student* root) {
    if (root == NULL) {
        return;
    }

    FreeTree(root->left);
    FreeTree(root->right);
    free(root->name);
    free(root->surname);
    free(root->gender);
    free(root->group);
    free(root);
}

int main() {
    setlocale(LC_ALL, "RUS");
    struct Student* root = NULL;
    root = InitStudent(23, "Ksenia", "Tfgd", "жен", "ghgjf4", 4, 5, 5);
    root->left = InitStudent(14, "Vaho", "Tfgd", "муж", "ghgjf4", 4, 4, 3);
    root->right = InitStudent(17, "Timur", "Tfgd", "муж", "ghgjf4", 4, 3, 3);

    root->printExcellentFemaleStudents(root);

    FreeTree(root);
    return 0;
}
