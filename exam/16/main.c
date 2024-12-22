#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

// Функция для проверки наличия нулевых элементов в каждой строке и в каждом столбце
int checkZeros(int **matrix, int rows, int cols) {
    // Проверяем строки
    int rows_zeros = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                rows_zeros++;
                break;
            }
        }
    }

    // Проверяем столбцы
    int cols_zeros = 0;
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] == 0) {
                cols_zeros++;
                break;
            }
        }
    }

    return (rows_zeros >= rows && cols_zeros >= cols);
}

// Функция для тестирования
void test() {
    {
        int rows = 4;
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

        array [0][0] = 0;   array [0][1] = 5; array [0][2] = 53; array [0][3] = 236;
        array [1][0] = 123; array [1][1] = 0; array [1][2] = 15; array [1][3] = 23;
        array [2][0] = 311; array [2][1] = 7; array [2][2] = 0;  array [2][3] = 454;
        array [3][0] = 311; array [3][1] = 7; array [3][2] = 86; array [3][3] = 0;

        if (!checkZeros(array, rows, cols)) {
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

        if (checkZeros(array, rows, cols)) {
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
        int rows = 4;
        int cols = 4;

        // Динамическое выделение памяти под двумерный массив
        int **array = (int **)malloc(rows * sizeof(int *));
        for (int i = 0; i < rows; i++) {
            array[i] = (int *)malloc(cols * sizeof(int));
        }

        array [0][0] = 345; array [0][1] = 9; array [0][2] = 435; array [0][3] = 0;
        array [1][0] = 123; array [1][1] = 0; array [1][2] = 0;   array [1][3] = 124;
        array [2][0] = 0;   array [2][1] = 0; array [2][2] = 123; array [2][3] = 562;
        array [3][0] = 0;   array [3][1] = 7; array [3][2] = 863; array [3][3] = 123;

        if (!checkZeros(array, rows, cols)) {
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