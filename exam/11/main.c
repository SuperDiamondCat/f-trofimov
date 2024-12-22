#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int* find_numbers_with_digit_sum(int N, int* count) {

    if(N <= 0) {
        printf("Ошибка: N должен быть больше нуля");
        exit(1);
    }

    int capacity = 10; // Начальный размер массива
    int* numbers = (int *)malloc(capacity * sizeof(int));
    if(numbers == NULL) {
        printf("Ошибка при выделении памяти");
        exit(2);
    }
    
    int j = 0; // Второй счётчик
    for (int i = 100; i <= 999; i++) {
        int sum = (i / 100) + (i / 10 % 10) + (i % 10); // Сумма цифр
        if (sum == N) {
            numbers[j] = i;
            j++;
            if (j >= capacity) {
                capacity *= 2; // Удвоение массива
                numbers = (int *)realloc(numbers, capacity * sizeof(int));
                if (numbers == NULL) {
                    printf("Ошибка при повторном выделении памяти");
                    exit(2);
                }
            }
        }
    }

    *count = j;
    return numbers;
}

// Функция для тестирования
void test() {
    {
        int N = 9;
        int count = 0;
        int* numbers = find_numbers_with_digit_sum(N, &count);
        if (count < 3 || numbers[2] != 126) {
            printf("Ошибка в тесте 1\n");
            free(numbers);
            exit(3);
        }
        free(numbers);
    }

    {
        int N = 15;
        int count = 0;
        int* numbers = find_numbers_with_digit_sum(N, &count);
        if (count < 3 || numbers[2] != 177) {
            printf("Ошибка в тесте 2\n ");
            free(numbers);
            exit(4);
        }
        free(numbers);
    }

    {
        int N = 20;
        int count = 0;
        int* numbers = find_numbers_with_digit_sum(N, &count);
        if (count < 3 || numbers[2] != 398) {
            printf("Ошибка в тесте 3\n");
            free(numbers);
            exit(5);
        }
        free(numbers);
    }
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    test();
    return 0;
}
