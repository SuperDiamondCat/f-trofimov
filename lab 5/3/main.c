#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "my.h"

int main(void) {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int m = 2, n = 3, k = 2;

    // Выделение памяти для матриц A и B
    float **A = (float **)malloc(m * sizeof(float *));
    float **B = (float **)malloc(n * sizeof(float *));
    for (int i = 0; i < m; i++) {
        A[i] = (float *)malloc(n * sizeof(float));
    }
    for (int i = 0; i < n; i++) {
        B[i] = (float *)malloc(k * sizeof(float));
    }

    // Инициализация матриц A и B
    A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
    A[1][0] = 4; A[1][1] = 5; A[1][2] = 6;

    B[0][0] = 7; B[0][1] = 8;
    B[1][0] = 9; B[1][1] = 10;
    B[2][0] = 11; B[2][1] = 12;

    // Умножение матриц
    float **C = MMult(A, B, m, n, k);

    // Вывод результирующей матрицы
    if (C != NULL) {
        printf("Результирующая матрица C:\n");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < k; j++) {
                printf("%.2f ", C[i][j]);   // должна быть [58 64; 139 154]
            }
            printf("\n");
        }

        // Освобождение памяти
        FreeMatrix(C, m);
    }

    // Освобождение памяти для A и B
    FreeMatrix(A, m);
    FreeMatrix(B, n);

    return 0;
}
