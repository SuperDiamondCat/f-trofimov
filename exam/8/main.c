#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Пример функции для поиска максимума
double square_function(double x) {
    return x * x;
}

double cube_function(double x) {
    return x * x * x;
}

// Функция для нахождения максимального значения функции на интервале [a, b]
double find_maximum(double (*func)(double), double a, double b, double step) {
    double max_value = func(a);
    double x = a;

    for (x = a; x <= b; x += step) {
        double current_value = func(x);
        if (current_value > max_value) {
            max_value = current_value;
        }
    }

    return max_value;
}

// Функция для тестирования
void test() {
    {
        double max = find_maximum(square_function, 0.0, 10.0, 0.1);
        if((int)(max + 1e-9) != 100) {
            printf("Ошибка в тесте 1");
            exit(1);
        }
    }
    {
        double max = find_maximum(cube_function, -100.0, 2.0, 0.5);
        if((int)(max + 1e-9) != 8) {
            printf("Ошибка в тесте 2");
            exit(2);
        }
    }
    {
        double max = find_maximum(square_function, -5.0, 2.0, 0.5);
        if((int)(max + 1e-9) != 25) {
            printf("Ошибка в тесте 3");
            exit(3);
        }
    }
}

int main() {
    setlocale(LC_ALL, "");
    test();
    return 0;
}
