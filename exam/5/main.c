#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

// Функция для проверки, является ли число простым
bool is_prime(int num) {
    if (num < 2) return false; // 0 и 1 не простые
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; // Если число делится на i, оно не простое
        }
    }
    return true; // Число простое
}

// Функция для нахождения всех простых чисел до N
int* find_primes(int N) {

    int *primes = (int *)malloc(sizeof(int *));
    if(primes == NULL) {
        printf("Ошибка при выделении памяти");
        exit(1);
    }
    int j = 0; // Второй счётчик
    for (int i = 2; i < N; i++) {
        if (is_prime(i)) {
            primes = realloc(primes, sizeof(primes) + sizeof(int *));
            primes[j] = i;
            j++; 
        }
    }
    return primes;
}

void test() {
    int primes[] = find_primes(10);
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    test();
    return 0;
}
