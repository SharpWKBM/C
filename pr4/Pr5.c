#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "RUS");
    srand(time(0)); // ������������� ���������� ��������� �����

    int size = 10; // ������ ��������� �������
    int* arr = malloc(size * sizeof(int)); // ��������� ������ ��� ��������� �������
    int* unique = malloc(size * sizeof(int)); // ��������� ������ ��� ���������� �����
    int unique_size = 0; // ������ ������� ���������� �����

    // ���������� ��������� ������� ���������� �������
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10; // ��������� ���������� ����� �� 0 �� 9
    }

    // ����� ���������� �����
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

    // ����� ��������� �������
    printf("�������� ������: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // ����� ������� ���������� �����
    printf("������ ���������� �����: ");
    for (int i = 0; i < unique_size; i++) {
        printf("%d ", unique[i]);
    }
    printf("\n");

    // ������������ ������
    free(arr);
    free(unique);

    return 0;
}