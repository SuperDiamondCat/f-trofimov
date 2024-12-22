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
long *find_primes(int N, int *count) {

    long *primes = (long *)malloc(sizeof(long) * N);
    if(primes == NULL) {
        printf("Ошибка при выделении памяти");
        exit(1);
    }

    int j = 0; // Второй счётчик
    for (int i = 2; i < N; i++) {
        if (is_prime(i)) {
            primes[j] = i;
            j++;
        }
    }

    // Уменьшаем размер массива до реального количества найденных чисел
    primes = (long *)realloc(primes, j * sizeof(long));
    if (primes == NULL && j > 0) {
        printf("Ошибка при повторном выделении памяти\n");
        exit(1);
    }    

    *count = j;
    return primes;
}

void test() {
    {
        int N = 15;
        int count = 0;
        long *primes = find_primes(N, &count);

        // for(int i = 0; i < count; i++) {
        //     printf("%ld ", primes[i]);
        // }
        // printf("\n");

        if(primes[4] != 11) {
            free(primes);
            printf("Ошибка 1");
            exit(1);
        }

        free(primes);
    }
    {
        int N = 5;
        int count = 0;
        long *primes = find_primes(N, &count);

        // for(int i = 0; i < count; i++) {
        //     printf("%ld ", primes[i]);
        // }
        // printf("\n");

        if(primes[1] != 3) {
            free(primes);
            printf("Ошибка 2");
            exit(2);
        }

        free(primes);
    }
    {
        int N = 0;
        int count = 0;
        long *primes = find_primes(N, &count);

        // for(int i = 0; i < count; i++) {
        //     printf("%ld ", primes[i]);
        // }
        // printf("\n");

        if(count != 0) {
            free(primes);
            printf("Ошибка 3");
            exit(3);
        }

        free(primes);
    }
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    test();
    return 0;
}
