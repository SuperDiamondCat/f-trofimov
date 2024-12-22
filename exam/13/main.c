#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int count_even_numbers(int *arr, int size) {
    int count = 0; // Счетчик четных чисел
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) { // Проверка на четность
            count++;
        }
    }
    return count;
}

void test() {
    {
        int arr[] = {1, 2, 3, 4, 5, 6};
        int size = sizeof(arr) / sizeof(arr[0]);
        if(count_even_numbers(arr, size) != 3) {
            printf("Ошибка в тесте 1");
            exit(1);
        }
    }
    {
        int arr[] = {2, 4, 6, 8, 10};
        int size = sizeof(arr) / sizeof(arr[0]);
        if(count_even_numbers(arr, size) != 5) {
            printf("Ошибка в тесте 2");
            exit(2);
        }
    }
    {
        int arr[] = {1, 3, 5, 7, 9};
        int size = sizeof(arr) / sizeof(arr[0]);
        if(count_even_numbers(arr, size) != 0) {
            printf("Ошибка в тесте 3");
            exit(3);
        }
    }
    {
        int arr[] = {0, -2, -4, 5, 7, -8};
        int size = sizeof(arr) / sizeof(arr[0]);
        if(count_even_numbers(arr, size) != 4) {
            printf("Ошибка в тесте 4");
            exit(4);
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    test();
    return 0;
}