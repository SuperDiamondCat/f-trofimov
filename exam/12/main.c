#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

bool has_unique_digits(int num) {
    bool digits[10] = {false};

    while (num > 0) {
        int digit = num % 10; // Получаем последнюю цифру
        if (digits[digit]) {
            return false; // Если цифра уже встречалась, возвращаем false
        }
        digits[digit] = true; // Помечаем цифру как встречавшуюся
        num /= 10; // Убираем последнюю цифру
    }
    
    return true; // Все цифры уникальны
}

// Функция для нахождения всех чисел до N с уникальными цифрами
int* find_unique_digit_numbers(int N, int *count) {
    int capacity = 10; // Начальная ёмкость
    int* numbers = (int *)malloc(capacity * sizeof(int));
    if(numbers == NULL) {
        printf("Ошибка при выделении памяти");
        exit(1);
    }

    int j = 0; // Счётчик

    for(int i = 0; i < N; i++) {
        if(has_unique_digits(i)) {
            numbers[j] = i;
            j++;
            if(capacity <= j) {
                capacity *= 2;
                numbers = (int *)realloc(numbers, capacity * sizeof(int));
                if (numbers == NULL) {
                    printf("Ошибка при повторном выделении памяти");
                    exit(1);
                }
            }
        }
    }

    *count = j;
    return numbers;
}

void test() {
    {
        int N = 20;
        int count = 0;
        int *numbers = find_unique_digit_numbers(N, &count);

        if(numbers[5] != 5) {
            printf("Ошибка в тесте 1\n ");
            free(numbers);
            exit(2);            
        }

        free(numbers);
    }
    {
        int N = 100;
        int count = 0;
        int *numbers = find_unique_digit_numbers(N, &count);

        if(numbers[20] != 21) {
            printf("Ошибка в тесте 2\n ");
            free(numbers);
            exit(3);            
        }

        free(numbers);
    }
    {
        int N = 50;
        int count = 0;
        int *numbers = find_unique_digit_numbers(N, &count);

        if(numbers[40] != 43) {
            printf("Ошибка в тесте 3\n ");
            free(numbers);
            exit(4);
        }

        free(numbers);
    }
}

int main(void) {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    test();
    return 0;
}
