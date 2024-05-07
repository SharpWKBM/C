#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void printArray(int arr[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int mainl() {
    srand(time(0)); // Инициализация генератора случайных чисел

    int arr[ROWS][COLS];

    // Заполнение массива случайными значениями
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = rand() % 100; // Генерация случайного числа от 0 до 99
        }
    }

    printf("Исходный массив:\n");
    printArray(arr);

    for (int i = 0; i < ROWS; i++) {
        int max = arr[i][0];
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }

        int min = arr[0][i];
        for (int j = 0; j < ROWS; j++) {
            if (arr[j][i] < min) {
                min = arr[j][i];
            }
        }

        arr[i][i] = min;
    }

    printf("\nИзмененный массив:\n");
    printArray(arr);

    return 0;
}