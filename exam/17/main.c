#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <stdlib.h>


// Функция для удаления ведущих и конечных пробелов из строки
void trim(char *str) {
    if (str == NULL || strlen(str) == 0) {
        return;
    }

    // Удаление ведущих пробелов
    char *start = str;
    while (isspace((unsigned char)*start)) {
        start++;
    }

    // Если строка состоит только из пробелов
    if (*start == '\0') {
        str[0] = '\0';
        return;
    }

    // Удаление конечных пробелов
    char *end = start + strlen(start) - 1;
    while (end > start && isspace((unsigned char)*end)) {
        *end = '\0';
        end--;
    }

    // Сдвиг строки, если есть ведущие пробелы
    if (start != str) {
        memmove(str, start, strlen(start) + 1);
    }
}

// Тестовая функция
void test() {
    {
        char test[] = "    Hello, World!    ";
        trim(test);
        if(strcmp(test, "Hello, World!") != 0) {
            printf("Ошибка в тесте 1");
            exit(1);
        }
    }
    {
        char test[] = "NoSpaces";
        trim(test);
        if(strcmp(test, "NoSpaces") != 0) {
            printf("Ошибка в тесте 2");
            exit(2);
        }
    }
    {
        char test[] = "     Leading spaces";
        trim(test);
        if(strcmp(test, "Leading spaces") != 0) {
            printf("Ошибка в тесте 3");
            exit(3);
        }
    }
    {
        char test[] = "Trailing spaces     ";
        trim(test);
        if(strcmp(test, "Trailing spaces") != 0) {
            printf("Ошибка в тесте 4");
            exit(4);
        }
    }
    {
        char test[] = "       ";
        trim(test);
        if(strcmp(test, "") != 0) {
            printf("Ошибка в тесте 5");
            exit(5);
        }
    }
    {
        char test[] = "";
        trim(test);
        if(strcmp(test, "") != 0) {
            printf("Ошибка в тесте 6");
            exit(6);
        }
    }
}

// Главная функция
int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    test();
    return 0;
}
