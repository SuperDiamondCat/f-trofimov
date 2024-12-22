#include <stdio.h>
#include <stdlib.h>

// Прототип функции
int determinant(int** matrix, int size);

// Вспомогательная функция для создания минорной матрицы
int** getMinor(int** matrix, int size, int row, int col);

int determinant(int** matrix, int size) {
    if (size == 1) {
        return matrix[0][0]; // Базовый случай
    }

    int det = 0;
    for (int col = 0; col < size; col++) {
        // Получение минорной матрицы
        int** minor = getMinor(matrix, size, 0, col);

        // Рекурсивное вычисление
        det += (col % 2 == 0 ? 1 : -1) * matrix[0][col] * determinant(minor, size - 1);

        // Освобождение памяти
        for (int i = 0; i < size - 1; i++) {
            free(minor[i]);
        }
        free(minor);
    }
    return det;
}

int** getMinor(int** matrix, int size, int row, int col) {
    int** minor = (int**)malloc((size - 1) * sizeof(int*));
    for (int i = 0; i < size - 1; i++) {
        minor[i] = (int*)malloc((size - 1) * sizeof(int));
    }

    int minorRow = 0, minorCol = 0;
    for (int i = 0; i < size; i++) {
        if (i == row) continue;
        minorCol = 0;
        for (int j = 0; j < size; j++) {
            if (j == col) continue;
            minor[minorRow][minorCol] = matrix[i][j];
            minorCol++;
        }
        minorRow++;
    }
    return minor;
}

// Функция тестирования
void test() {
    printf("Тестируем программу...\n");

    int size = 3;
    int** matrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int*)malloc(size * sizeof(int));
    }

    matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3;
    matrix[1][0] = 4; matrix[1][1] = 5; matrix[1][2] = 6;
    matrix[2][0] = 7; matrix[2][1] = 8; matrix[2][2] = 9;

    printf("Определитель матрицы: %d\n", determinant(matrix, size));

    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    // Поддержка русского языка в консоли
    setlocale(LC_ALL, "Russian");

    printf("Программа для вычисления определителя матрицы рекурсивным способом\n");

    test();

    return 0;
}
