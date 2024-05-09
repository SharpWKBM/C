#ifndef LIST_H
#define LIST_H
typedef struct List {
    struct Node* head;
    struct Node* tail;
    int size;

    void* (*append)(void*);
    void* (*printE)(void*);
    void* (*print)(void*);
    void* (*free)(void*);
} List;
void* Append(void*);
void* PrintExcellentFemaleStudents(void*);
void* PrintList(void*);
void* FreeList(void*);
List* InitList();
#endif // LIST_H
