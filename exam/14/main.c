#include <stdlib.h>
#include <locale.h>
#include <stdio.h>

int count_even_numbers(int *arr, int rows, int cols) {
    int count = 0; // Счетчик четных чисел
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i * cols + j] % 2 == 0) { // Проверка на четность
                count++;
            }
        }
    }
    return count;
}

void test() {
    {
        int rows = 3;
        int cols = 4;
        int array[3][4] = {
            {1, 4, 7, 8},
            {2, 5, 6, 9},
            {10, 11, 12, 13}
        };

        int count = count_even_numbers(*array, rows, cols);

        if(count != 6) {
            printf("Ошибка в тесте 1");
            exit(1);
        }
    }
    {
        int rows = 4;
        int cols = 3;
        int array[4][3] = {
            {76, 3, 23},
            {2, 5, 6},
            {107, 171, 128},
            {66, 123, 413}
        };

        int count = count_even_numbers(*array, rows, cols);

        if(count != 5) {
            printf("Ошибка в тесте 2");
            exit(2);
        }
    }
    {
        int rows = 2;
        int cols = 2;
        int array[2][2] = {
            {0, -3},
            {2, -2}
        };

        int count = count_even_numbers(*array, rows, cols);

        if(count != 3) {
            printf("Ошибка в тесте 3");
            exit(3);
        }
    }
}

int main(void) {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    test();
    return 0;
}