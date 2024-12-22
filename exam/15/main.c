#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

// Функция для подсчета четных чисел в динамическом двумерном массиве
int countEvenNumbers(int **array, int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (array[i][j] % 2 == 0) { // Проверяем, четное ли число
                count++;
            }
        }
    }
    return count; // Возвращаем количество четных чисел
}

// Функция для тестирования
void test() {
    {
        int rows = 3;
        int cols = 4;

        // Динамическое выделение памяти под двумерный массив
        int **array = (int **)malloc(rows * sizeof(int *));
        for (int i = 0; i < rows; i++) {
            array[i] = (int *)malloc(cols * sizeof(int));
        }

        if(array == NULL) {
            printf("Ошибка выделения памяти");
            exit(1);
        }

        // Заполнение массива
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                array[i][j] = 50 - (i + 1) * (j + 1);
            }
        }

        // Подсчет четных чисел
        int even_count = countEvenNumbers(array, rows, cols);

        if (even_count != 8) {
            printf("Ошибка в тесте 1");
            // Освобождение памяти
            for (int i = 0; i < rows; i++) {
                free(array[i]);
            }
            free(array);
            exit(2);
        }

        // Освобождение памяти
        for (int i = 0; i < rows; i++) {
            free(array[i]);
        }
        free(array);
    }
    {
        int rows = 3;
        int cols = 4;

        // Динамическое выделение памяти под двумерный массив
        int **array = (int **)malloc(rows * sizeof(int *));
        for (int i = 0; i < rows; i++) {
            array[i] = (int *)malloc(cols * sizeof(int));
        }

        // Заполнение массива
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                array[i][j] = 50 - (i + 2) * (j + 1);
            }
        }


        int even_count = countEvenNumbers(array, rows, cols);

        if (even_count != 10) {
            printf("Ошибка в тесте 2");
            // Освобождение памяти
            for (int i = 0; i < rows; i++) {
                free(array[i]);
            }
            free(array);
            exit(3);
        }

        // Освобождение памяти
        for (int i = 0; i < rows; i++) {
            free(array[i]);
        }
        free(array);
    }
    {
        int rows = 3;
        int cols = 4;

        // Динамическое выделение памяти под двумерный массив
        int **array = (int **)malloc(rows * sizeof(int *));
        for (int i = 0; i < rows; i++) {
            array[i] = (int *)malloc(cols * sizeof(int));
        }

        // Заполнение массива
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                array[i][j] = 50 - (i + 2) * (j + 7);
            }
        }

        // Подсчет четных чисел
        int even_count = countEvenNumbers(array, rows, cols);

        if (even_count != 10) {
            printf("Ошибка в тесте 3");
            // Освобождение памяти
            for (int i = 0; i < rows; i++) {
                free(array[i]);
            }
            free(array);
            exit(4);
        }

        // Освобождение памяти
        for (int i = 0; i < rows; i++) {
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
