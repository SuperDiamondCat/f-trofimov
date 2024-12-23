#include <stdio.h>
#include <locale.h>

// Функция для проверки, является ли число простым
int is_prime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Рекурсивная функция разложения на простые множители
void factorize(int n) {
    if (n <= 1) return; // Базовый случай

    for (int i = 2; i <= n; i++) {
        if (n % i == 0 && is_prime(i)) { // Если i делитель и простое число
            printf("%d ", i); // Выводим множитель
            factorize(n / i); // Рекурсивно разлагаем оставшуюся часть
            return; // Завершаем цикл, чтобы не искать дальше
        }
    }
}

int main(void) {
    setlocale(LC_ALL, "");

    int number;
    printf("Введите число: ");
    scanf("%d", &number);

    printf("Простые множители: ");
    factorize(number);
    printf("\n");

    return 0;
}
