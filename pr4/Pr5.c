#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "RUS");
    srand(time(0)); // Инициализация генератора случайных чисел

    int size = 10; // Размер исходного массива
    int* arr = malloc(size * sizeof(int)); // Выделение памяти для исходного массива
    int* unique = malloc(size * sizeof(int)); // Выделение памяти для уникальных чисел
    int unique_size = 0; // Размер массива уникальных чисел

    // Заполнение исходного массива случайными числами
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10; // Генерация случайного числа от 0 до 9
    }

    // Поиск уникальных чисел
    for (int i = 0; i < size; i++) {
        int j;
        for (j = 0; j < unique_size; j++) {
            if (arr[i] == unique[j]) {
                break;
            }
        }
        if (j == unique_size) {
            unique[unique_size++] = arr[i];
        }
    }

    // Вывод исходного массива
    printf("Исходный массив: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Вывод массива уникальных чисел
    printf("Массив уникальных чисел: ");
    for (int i = 0; i < unique_size; i++) {
        printf("%d ", unique[i]);
    }
    printf("\n");

    // Освобождение памяти
    free(arr);
    free(unique);

    return 0;
}