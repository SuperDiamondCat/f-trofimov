#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>

// Функция для генерации следующего числа в заданном диапазоне
float random_bond(int min, int max) {
    return rand() % (min - max + 1)  + min;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    const int rows = 3;
    const int cols = 5;
    float **arr;

    arr = (float **)malloc(rows * sizeof(float *));
    
    if (arr == NULL) {
        printf("Не удалось выделить память.\n");
        return 1;
    }

    // Выделение памяти для столбцов
    for (int i = 0; i < rows; i++) {
        arr[i] = (float *)malloc(cols * sizeof(float));
        if (arr[i] == NULL) {
            printf("Не удалось выделить память.\n");
            return 2;
        }
    }

    // Заполняем массив случайными значениями
    srand(time(NULL));

    printf("Таблица:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = random_bond(-36, 74) / 10;
            printf("%.1f ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Освобождение выделенной памяти
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

