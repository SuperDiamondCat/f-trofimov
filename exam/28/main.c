//Напишите программу, 
//которая записывает в текстовый файл 10000 случайных целых
//чисел : -1 или 1. 
//Затем считывает их в динамическую память и находит сумму.

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main() {
    setlocale(LC_ALL, "rus");

    const char *filename = "пиздарики.txt";
    const int count = 10000;
    int sum = 0;

    srand(time(NULL));


    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("ПИЗДА ФАЙЛ НЕ ОТКРЫЛСЯ ДЛЯ ЗАПИСИ");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        int random_number = (rand() % 2 == 0) ? -1 : 1;
        fprintf(file, "%d\n", random_number);
    }

    fclose(file);

    file = fopen(filename, "r");
    if (!file) {
        printf("ПИЗДА ФАЙЛ НЕ ОТКРЫЛСЯ ДЛЯ ЧТЕНИЯ");
        exit(2);
    }

    int* mzllf;
    mzllf = (int*)malloc(count * sizeof(int));
    if (mzllf == NULL) {
        printf("ПИЗДА ПАМЯТИ");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        if (fscanf(file, "%d", &mzllf[i]) != 1) {
            perror("ПИЗДА ФАЙЛ НЕ ЧИТАЕТСЯ");
            free(mzllf);
            fclose(file);
            return 1;
        }
        sum += mzllf[i];
    }

    fclose(file);

    printf("ТАК УЖ И БЫТЬ, СУММА ЧИСЕЛ В ФАЙЛЕ %s РАВНА %d\n", filename, sum);

    return 0;
}
