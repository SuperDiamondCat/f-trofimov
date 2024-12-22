#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

double vector_length(const double *vector, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += vector[i] * vector[i]; // Возведение в квадрат
    }
    return sqrt(sum); // Возвращаем квадратный корень из суммы
}

void test() {
    {
        double vector[] = {3.0, 4.0}; // Длина должна быть 5.0
        double length = vector_length(vector, 2);

        if(length != 5.0) {
            printf("Ошибка 2");
            exit(2);
        }
    }
    {
        double vector[] = {1.0, 2.0, 2.0}; // Длина должна быть 3.0
        double length = vector_length(vector, 3);

        if(length != 3.0) {
            printf("Ошибка 2");
            exit(2);
        }   
    }
    {
        double vector[] = {0.0, 0.0, 0.0}; // Длина должна быть 0.0
        double length = vector_length(vector, 3);
        
        if(length != 0.0) {
            printf("Ошибка 3");
            exit(3);
        }
    }
    {
        double vector[] = {1.0}; // Длина должна быть 1.0
        double length = vector_length(vector, 1);
        
        if(length != 1.0) {
            printf("Ошибка 4");
            exit(4);
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    test();
    return 0;
}
