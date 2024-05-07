#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <time.h>

#define SIZE 10

int generate_array(int a[], int i) {
    if (i < SIZE) {
        a[i] = rand() % 10 + 1;
        generate_array(a, i + 1);
    }
}

int count_odd_numbers(int a[], int i, int num) {
    if (i < SIZE) {
        if (a[i] % 2 > 0) {
            num = count_odd_numbers(a, i + 1, num + 1);
        }
        else {
            num = count_odd_numbers(a, i + 1, num);
        }
    }
    return num;
}

int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    int a[SIZE];
    int num = 0;
    generate_array(a, 0);
    num = count_odd_numbers(a, 0, num);
    printf("%d\n", num);
    for (int i = 0; i < SIZE; i++) {
        printf("|%d|", a[i]);
    }
    system("PAUSE");
    return 0;
}