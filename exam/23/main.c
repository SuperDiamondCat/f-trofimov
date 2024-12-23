#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

#define EPSILON 1e-6

typedef double (*func_ptr)(double);

double bisection_recursive(func_ptr f, double a, double b) {
    double mid = (a + b) / 2;

    if (fabs(f(mid)) < EPSILON || fabs(b - a) < EPSILON) {
        return mid;
    }

    if (f(a) * f(mid) < 0) {
        return bisection_recursive(f, a, mid);
    } else {
        return bisection_recursive(f, mid, b);
    }
}

double test_function(double x) {
    return x * x - 2; // Root at sqrt(2)
}

void test() {
    double root = bisection_recursive(test_function, 0, 2);
    double expected = sqrt(2);

    if (fabs(root - expected) >= EPSILON) {
        printf("Ошибка в тесте");
        exit(1);
    }
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    test();
    return 0;
}
