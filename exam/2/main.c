#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


int main() {

    setlocale(LC_ALL, "");

    // Определение размера массива
    const int rows = 100;
    const int cols = 200;

    // Выделение памяти для двумерного динамического массива
    float **array = (float **)malloc(rows * sizeof(float *));

    if (array == NULL) {
        printf("Ошибка при выделении памяти для строк массива.\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        array[i] = (float *)malloc(cols * sizeof(float));
        
        if (array[i] == NULL) {
            printf("Ошибка при выделении памяти для столбцов массива.\n");
            // Освобождаем уже выделенную память
            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            return 1;
        }
    }

    // Инициализация генератора случайных чисел
    srand(time(NULL));

    // Заполнение массива случайными числами из отрезка [-3, 10]
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = rand() % 14 - 3; // В диапазоне [-3, 10]
        }
    }

    // Пример вывода нескольких элементов массива
    printf("Некоторые элементы массива:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%.2f ", array[i][j]);
        }
        printf("\n");
    }

    // Освобождение памяти
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
