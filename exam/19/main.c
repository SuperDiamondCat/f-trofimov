#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int size;

    // Запрашиваем количество строк у пользователя
    printf("Введите количество строк: ");
    scanf("%d", &size);
    
    // Очищаем буфер ввода
    getchar();

    // Динамическое выделение памяти для массива строк
    char **array = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++) {
        array[i] = (char *)malloc(100 * sizeof(char)); // Предполагаем, что длина строки не больше 99 символов
    }

    // Заполнение массива строками
    printf("Введите строки:\n");
    for (int i = 0; i < size; i++) {
        printf("Строка[%d]: ", i);
        fgets(array[i], 100, stdin);
        
        // Удаляем символ новой строки, если он есть
        array[i][strcspn(array[i], "\n")] = '\0';
    }

    // Выводим массив до сортировки
    printf("Строки до сортировки:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", array[i]);
    }

    // Вызываем функцию сортировки
    sortStrings(array, size);

    // Выводим отсортированный массив
    printf("Строки после сортировки:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", array[i]);
    }

    // Освобождаем выделенную память
    for (int i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);
}

// Основная функция
int main() {
    test();
    return 0;
}
