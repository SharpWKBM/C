#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define ROWS 3
#define COLS 3

int find_max_in_row(int row[], int cols) 
{
    int max = row[0];
    for (int i = 1; i < cols; i++) 
    {
        if (row[i] > max) 
        {
            max = row[i];
        }
    }
    return max;
}


int find_min_in_col(int arr[][COLS], int rows, int col)
{
    int min = arr[0][col];
    for (int i = 1; i < rows; i++) 
    {
        if (arr[i][col] < min) 
        {
            min = arr[i][col];
        }
    }
    return min;
}


void print_array(int arr[][COLS], int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}


void generate_random_array(int arr[][COLS], int rows, int cols) 
{
    srand( time(0) );
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            arr[i][j] = rand() % 100;
        }
    }
}


int main() {
    setlocale(LC_ALL, "RUS");
    int arr[ROWS][COLS];

    // Заполнение массива случайными числами
    generate_random_array(arr, ROWS, COLS);

    printf("Исходный массив:\n");
    print_array(arr, ROWS, COLS);

    // Замена максимума строки на минимум столбца
    for (int i = 0; i < ROWS; i++) 
    {
        int max = find_max_in_row(arr[i], COLS);
        int min = find_min_in_col(arr, ROWS, i);
        for (int j = 0; j < COLS; j++) 
        {
            if (arr[i][j] == max) 
            {
                arr[i][j] = min;
            }
        }
    }

    printf("Измененный массив:\n");
    print_array(arr, ROWS, COLS);

    return 0;
}
