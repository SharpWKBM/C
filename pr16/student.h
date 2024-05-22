#ifndef student_H
#define student_H


struct Student {
    char *surname;
    char *name;
    char *sex;
    int age;
    int group;
    float mathMark;
    float physicsMark;
    float chemistryMark;
    void* (*infoOutput)(void*);
    void* (*saveToBinary)(void*);
    // void* (*saveBinary)(void*);
    // void* (*loadBinary)(void*);
};

void* studentInit(void *surname, void *name, void *sex, int age, int group, float mathMark, float physicsMark, float chemistryMark);

#endif 
