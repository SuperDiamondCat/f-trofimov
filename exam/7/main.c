#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int is_palindrome(int N) {
    int original = N;
    int reversed = 0;

    // Обратное число
    while (N > 0) {
        int digit = N % 10;
        reversed = reversed * 10 + digit;
        N /= 10;
    }
    
    // Проверка на равенство оригинальному числу
    return original == reversed;
}

int *find_palindromes(int N, int *count) {

    int capacity = 50; // Начальный размер массива
    int *palindromes = (int *)malloc(capacity * sizeof(int));
    if (palindromes == NULL) {
        printf("Ошибка при выделении памяти");
        exit(1);
    }

    int j = 0; // Счётчик чисел
    for (int i = 0; i <= N; i++) {
        if (is_palindrome(i)) {
            palindromes[j] = i;
            j++;
            if (j >= capacity) {
                capacity *= 2; // Удвоение массива
                palindromes = (int *)realloc(palindromes, capacity * sizeof(int));
                if (palindromes == NULL) {
                    printf("Ошибка при повторном выделении памяти");
                    exit(1);
                }
            }
        }
    }
    
    *count = j;
    return palindromes;
}

void test() {
    {
        int N = 23456;
        int count;
        int *palindromes = find_palindromes(N, &count);

        if(count != 334) {
            printf("Ошибка в тесте 1");
            free(palindromes);
            exit(2);
        }

        free(palindromes);
    }
    {
        int N = 364567;
        int count;
        int *palindromes = find_palindromes(N, &count);

        if(count != 1364) {
            printf("Ошибка в тесте 2");
            free(palindromes);
            exit(3);
        }

        free(palindromes);
    }
    {
        int N = 11;
        int count;
        int *palindromes = find_palindromes(N, &count);

        if(count != 11) {
            printf("Ошибка в тесте 3");
            free(palindromes);
            exit(4);
        }

        free(palindromes);
    }
}

int main(void) {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    test(); 
    return 0; 
}