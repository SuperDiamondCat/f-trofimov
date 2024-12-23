#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Функция для сортировки массива строк в лексикографическом порядке
void sortStrings(char **array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(array[j], array[j + 1]) > 0) {
                // Обмен строк, если они не в порядке
                char *temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Функция для тестирования
void test() {
    {
        // Исходный массив строк
        const char *input[] = {"яблоко", "груша", "апельсин", "банан"};
        const int size = sizeof(input) / sizeof(input[0]);

        // Ожидаемый результат после сортировки
        const char *expected[] = {"апельсин", "банан", "груша", "яблоко"};

        // Динамическое выделение памяти для массива строк
        char **array = (char **)malloc(size * sizeof(char *));
        for (int i = 0; i < size; i++) {
            array[i] = (char *)malloc((strlen(input[i]) + 1) * sizeof(char));
            strcpy(array[i], input[i]);
        }

        if(array == NULL) {
            printf("Ошибка выделения памяти");
            exit(1);
        }

        // Сортировка массива строк
        sortStrings(array, size);

        // Проверка результата
        for (int i = 0; i < size; i++) {
            if(strcmp(array[i], expected[i]) != 0) {
                printf("Ошибка в тесте 1");
                // Освобождаем выделенную память
                for (int i = 0; i < size; i++) {
                    free(array[i]);
                }
                free(array);
                exit(2);
            }
        }

        // Освобождаем выделенную память
        for (int i = 0; i < size; i++) {
            free(array[i]);
        }
        free(array);
    }
    {
        // Исходный массив строк
        const char *input[] = {"", "1", "0", "Test"};
        const int size = sizeof(input) / sizeof(input[0]);

        // Ожидаемый результат после сортировки
        const char *expected[] = {"", "0", "1", "Test"};

        // Динамическое выделение памяти для массива строк
        char **array = (char **)malloc(size * sizeof(char *));
        for (int i = 0; i < size; i++) {
            array[i] = (char *)malloc((strlen(input[i]) + 1) * sizeof(char));
            strcpy(array[i], input[i]);
        }

        if(array == NULL) {
            printf("Ошибка выделения памяти");
            exit(1);
        }

        // Сортировка массива строк
        sortStrings(array, size);

        // Проверка результата
        for (int i = 0; i < size; i++) {
            if(strcmp(array[i], expected[i]) != 0) {
                printf("Ошибка в тесте 2");
                // Освобождаем выделенную память
                for (int i = 0; i < size; i++) {
                    free(array[i]);
                }
                free(array);
                exit(3);
            }
        }

        // Освобождаем выделенную память
        for (int i = 0; i < size; i++) {
            free(array[i]);
        }
        free(array);
    }
    {
        // Исходный массив строк
        const char *input[] = {".", "A", "сглыпа)", "Test"};
        const int size = sizeof(input) / sizeof(input[0]);

        // Ожидаемый результат после сортировки
        const char *expected[] = {".", "A", "Test", "сглыпа)"};

        // Динамическое выделение памяти для массива строк
        char **array = (char **)malloc(size * sizeof(char *));
        for (int i = 0; i < size; i++) {
            array[i] = (char *)malloc((strlen(input[i]) + 1) * sizeof(char));
            strcpy(array[i], input[i]);
        }

        if(array == NULL) {
            printf("Ошибка выделения памяти");
            exit(1);
        }

        // Сортировка массива строк
        sortStrings(array, size);

        // Проверка результата
        for (int i = 0; i < size; i++) {
            if(strcmp(array[i], expected[i]) != 0) {
                printf("Ошибка в тесте 3");
                // Освобождаем выделенную память
                for (int i = 0; i < size; i++) {
                    free(array[i]);
                }
                free(array);
                exit(4);
            }
        }

        // Освобождаем выделенную память
        for (int i = 0; i < size; i++) {
            free(array[i]);
        }
        free(array);
    }
}

// Основная функция
int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    test();
    return 0;
}
