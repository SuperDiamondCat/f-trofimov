#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

void trim(char *str) {
    // Убедитесь, что строка не пустая
    if (str == NULL) {
        return;
    }

    // Удаление ведущих пробелов
    while (isspace((unsigned char)*str)) {
        str++;
    }

    // Если строка стала пустой, возвращаем
    if (*str == '\0') {
        return;
    }

    // Удаление конечных пробелов
    char *end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }

    // Установка конца строки
    end[1] = '\0';
    // Сдвигаем строку в начало
    memmove(str, str, (end - str + 2) * sizeof(char));
}

// Функция для тестирования
void test() {
    char str[] = "  Test ";

    // Вызываем функцию trim для удаления пробелов
    trim(str);
    
    // Выводим строку после обработки
    printf("После: '%s'\n", str);
}

// Основная функция
int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    test();
    return 0;
}