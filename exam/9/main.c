#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

void matrix_multiply(int *matrix_a, int *matrix_b, int *result, int rows_a, int cols_a, int rows_b, int cols_b) {
    // Проверка на возможность умножения матриц
    if (cols_a != rows_b) {
        printf("Невозможно умножить матрицы: несоответствие размеров.\n");
        exit(1);
    }

    // Выполнение умножения матриц
    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            int sum = 0;
            for (int k = 0; k < cols_a; k++) {
                sum += *(matrix_a + i * cols_a + k) * *(matrix_b + k * cols_b + j);
            }
            *(result + i * cols_b + j) = sum;
        }
    }
}

void test() {
    {
        const int rows_a = 2;
        const int cols_a = 3;

        const int rows_b = 3;
        const int cols_b = 2;

        int matrix_a[2][3] = {
            {1, 2, 3}, 
            {4, 5, 6}
        };
        int matrix_b[3][2] = {
            {7, 8}, 
            {9, 10}, 
            {11, 12}
        };

        int result[rows_a][cols_b];

        matrix_multiply((int*)matrix_a, (int*)matrix_b, (int*)result, rows_a, cols_a, rows_b, cols_b);

        if(result[1][1] != 154) {
            printf("Ошибка в тесте 1");
            exit(1);
        };
    }
    {
        const int rows_a = 3;
        const int cols_a = 2;
        const int rows_b = 2;
        const int cols_b = 3;

        int matrix_a[3][2] = {
            {1, 2}, 
            {3, 4}, 
            {5, 6}
        };
        int matrix_b[2][3] = {
            {7, 8, 9}, 
            {10, 11, 12}
        };

        int result[rows_a][cols_b];
    
        matrix_multiply((int*)matrix_a, (int*)matrix_b, (int*)result, rows_a, cols_a, rows_b, cols_b);

        if(result[2][2] != 117) {
            printf("Ошибка в тесте 2");
            exit(2);
        };
    }
    {
        const int rows_a = 3;
        const int cols_a = 3;
        const int rows_b = 3;
        const int cols_b = 3;

        int matrix_a[3][3] = {
            {1, 2, 3}, 
            {4, 5, 6}, 
            {7, 8, 9}
        };
        int matrix_b[3][3] = {
            {9, 8, 7}, 
            {6, 5, 4}, 
            {3, 2, 1}
        };

        int result[rows_a][cols_b];
    
        matrix_multiply((int*)matrix_a, (int*)matrix_b, (int*)result, rows_a, cols_a, rows_b, cols_b);

        if(result[2][2] != 90) {
            printf("Ошибка в тесте 3");
            exit(3);
        };
    }
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    test();
    return 0;
}