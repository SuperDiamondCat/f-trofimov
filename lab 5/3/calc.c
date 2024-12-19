#include <stdio.h>
#include <stdlib.h>
#include "my.h"

float** MMult(float **A, float **B, int m, int n, int k) {
    // Выделение памяти для результирующей матрицы
    float **C = (float **)malloc(m * sizeof(float *));
    if (C == NULL) {
        printf("Ошибка выделения памяти.\n");
        return NULL;
    }

    for (int i = 0; i < m; i++) {
        C[i] = (float *)malloc(k * sizeof(float));
        if (C[i] == NULL) {
            printf("Ошибка выделения памяти.\n");
            // Освобождаем уже выделенную память
            for (int j = 0; j < i; j++) {
                free(C[j]);
            }
            free(C);
            return NULL;
        }
    }

    // Инициализация результирующей матрицы нулями
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = 0.0f;
        }
    }

    // Умножение матриц
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            for (int l = 0; l < n; l++) {
                C[i][j] += A[i][l] * B[l][j];
            }
        }
    }

    return C;
}

// Функция для освобождения памяти двумерной матрицы
void FreeMatrix(float **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}