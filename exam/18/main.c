#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Функция для сортировки массива вещественных чисел по возрастанию
void sortArray(float *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        // Обмен значений
        if (minIndex != i) {
            float temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}

// Функция для тестирования
void test() {
    {
        // Тестовые данные
        float inputArray[] = {3.5, 2.1, 4.7, 1.0};
        float expectedArray[] = {1.0, 2.1, 3.5, 4.7};
        int size = sizeof(inputArray) / sizeof(inputArray[0]);

        // Копируем входной массив для сортировки
        float *testArray = (float *)malloc(size * sizeof(float));
        for (int i = 0; i < size; i++) {
            testArray[i] = inputArray[i];
        }

        // Вызываем функцию сортировки
        sortArray(testArray, size);

        // Сравниваем результат с ожидаемым значением
        for (int i = 0; i < size; i++) {
            if (testArray[i] != expectedArray[i]) {
                printf("Ошибка в тесте 1");
                free(testArray);
                exit(1);
            }
        }

        // Освобождаем выделенную память
        free(testArray);
    }
    {
        // Тестовые данные
        float inputArray[] = {3.1, 0, 3, -1.0};
        float expectedArray[] = {-1.0, 0, 3, 3.1};
        int size = sizeof(inputArray) / sizeof(inputArray[0]);

        // Копируем входной массив для сортировки
        float *testArray = (float *)malloc(size * sizeof(float));
        for (int i = 0; i < size; i++) {
            testArray[i] = inputArray[i];
        }

        // Вызываем функцию сортировки
        sortArray(testArray, size);

        // Сравниваем результат с ожидаемым значением
        for (int i = 0; i < size; i++) {
            if (testArray[i] != expectedArray[i]) {
                printf("Ошибка в тесте 2");
                free(testArray);
                exit(2);
            }
        }

        // Освобождаем выделенную память
        free(testArray);
    }
}

// Основная функция
int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    test();
    return 0;
}
