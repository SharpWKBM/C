#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

void change_case(char* str) {
    int len = strlen(str);
    int i = 0;
    int toUpper = 1;

    while (i < len) {
        if (str[i] == ' ') {
            toUpper = 1;
        }
        else {
            if (toUpper) {
                str[i] = toupper(str[i]);
                toUpper = 0;
            }
            else {
                str[i] = tolower(str[i]);
                toUpper = 1;
            }
        }
        i++;
    }
}

int main() {
     setlocale(LC_ALL, "Rus");
    char str[100];
    printf("������� ������: ");
    fgets(str, 100, stdin);
    str[strlen(str) - 1] = '\0'; // ������� ������ ����� ������

    change_case(str);

    printf("���������� ������: %s\n", str);

    return 0;
}