#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Рекурсивная функция для вычисления элемента последовательности
int calculate_sequence(int n) {
    if (n == 0) {
        return 1; // F0 = 1
    } else if (n == 1) {
        return 2; // F1 = 2
    } else {
        return 2 * calculate_sequence(n - 1) - calculate_sequence(n - 2);
    }
}

// Функция тестирования
void test() {
    // Ожидаемые значения последовательности по формуле:
    // F0 = 1, F1 = 2, F2 = 3, F3 = 4, F4 = 5, F5 = 6
    int expected[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++) {
        int result = calculate_sequence(i);
        if (result != expected[i]) {
            printf("Ошибка в тесте 1");
            exit(1);
        }
    }
}

// Главная функция
int main(void) {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    test();
    return 0;
}
