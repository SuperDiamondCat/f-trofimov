#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

// Function to find the last occurrence of a character in a string
char* find_last_occurrence(const char* str, char c) {
    if (str == NULL) {
        return NULL;
    }

    const char* last_occurrence = NULL;
    while (*str) {
        if (*str == c) {
            last_occurrence = str;
        }
        str++;
    }

    return (char*)last_occurrence;
}

// Test function
void test() {
    {
        const char* test = "hello world";
        const char* expected = &test[7];
        char* result = find_last_occurrence(test, 'o');

        if(result != expected) {
            printf("Ошибка в тесте 1");
            exit(1);
        }
    }
    {
        const char* test = "test string";
        const char* expected = &test[3];
        char* result = find_last_occurrence(test, 't');
        if(result != expected) {
            printf("Ошибка в тесте 2");
            exit(2);
        }
    }
    {
        const char* test = "abcdef";
        const char* expected = &test[0];
        char* result = find_last_occurrence(test, 'a');
        if(result != expected) {
            printf("Ошибка в тесте 3");
            exit(3);
        }
    }
    {
        const char* test = "aaaa";
        const char* expected = &test[3];
        char* result = find_last_occurrence(test, 'a');
        if(result != expected) {
            printf("Ошибка в тесте 4");
            exit(4);
        }
    }
    {
        const char* test = ""; // Empty string
        const char* expected = NULL;
        char* result = find_last_occurrence(test, 'a');
        if(result != expected) {
            printf("Ошибка в тесте 5");
            exit(5);
        }
    }
}

// Main function
int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    test();
    return 0;
}
