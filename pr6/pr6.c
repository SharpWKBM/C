#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>


void fillArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 9 + 1;
    }
}


void printArray(int* arr, int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("|%d|", arr[i]);
    }
}


int* createArray(int size)
{
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr != NULL)
    {
        fillArray(arr, size);
        printArray(arr, size);
    }
    return arr;
}


void fillDArray(int** arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = rand() % 9 + 1;
        }
    }
}


void printDArray(int** arr, int row, int col)
{
    printf("\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("|%d|", arr[i][j]);
        }
        printf("\n");
    }
}


int** createDArray(int row, int col)
{
    int** dArr = (int*)malloc(row * sizeof(int));
    for (int i = 0; i < row; i++)
    {
        dArr[i] = (int*)malloc(col * sizeof(int));
    }
    if (dArr != NULL)
    {
        fillDArray(dArr, row, col);
        printDArray(dArr, row, col);
    }
    return dArr;
}


void pr2(int size)
{
    printf("\nОтработала функция с заданием из 2 практики");
    int* arr = createArray(size);
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 > 0)
        {
            count++;
        }
    }

    printf("\nКоличество нечетных чисел в массиве: %d\n", count);
    free(arr);
}


void pr5(int size)
{
    printf("\nОтработала функция с заданием из 5 практики");
    int* arr = createArray(size);
    int* unique = malloc(0);
    int unique_size = 1;
    for (int i = 0; i < size; i++)
    {
        int unique_num = 1;
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == unique[j])
            {
                unique_num = 0;
                break;
            }
        }
        if (unique_num)
        {
            unique = realloc(unique, unique_size * sizeof(int));
            unique[unique_size - 1] = arr[i];
            unique_size++;
        }
    }
    printArray(unique, unique_size - 1);
    free(arr);
    free(unique);
}


int findMaxInRow(int** arr, int row, int col)
{
    int max = arr[0][0];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (max < arr[i][j])
            {
                max = arr[i][j];
            }
        }
    }
    return max;
}


int findMinInCol(int** arr, int row, int col)
{
    int min = arr[0][0];
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (min > arr[j][i])
            {
                min = arr[j][i];
            }
        }
    }
    return min;
}


void pr3(int row, int col)
{
    printf("\nОтработала функция с заданием из 3 практики");
    int** arr = createDArray(row, col);
    for (int i = 0; i < row; i++)
    {
        int max = findMaxInRow(arr, row, col);
        int min = findMinInCol(arr, row, col);
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == max)
            {
                arr[i][j] = min;
            }
        }
    }
    printDArray(arr, row, col);
}


int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    const int SIZE = 10;
    const int ROW = 10, COL = 10;
    pr2(SIZE);
    pr3(ROW, COL);
    pr5(SIZE);
    return 0;
}