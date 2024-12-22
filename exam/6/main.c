#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int *find_lucky(int *count) { 
    int capacity = 50; // Начальный размер массива
    int *tickets = (int *)malloc(capacity * sizeof(int));
    if (tickets == NULL) {
        printf("Ошибка при выделении памяти");
        exit(1);
    }

    int j = 0; // Счётчик билетов
    for (int a = 0; a <= 9; a++) { 
        for (int b = 0; b <= 9; b++) { 
            for (int c = 0; c <= 9; c++) { 
                for (int d = 0; d <= 9; d++) { 
                    for (int e = 0; e <= 9; e++) { 
                        for (int f = 0; f <= 9; f++) { 
                            if ((a + b + c == d + e + f) && (a != 0)) { 
                                tickets[j] = a * 100000 + b * 10000 + c * 1000 + d * 100 + e * 10 + f;
                                j++;
                                if (j >= capacity) {
                                    capacity *= 2; // Удвоение массива
                                    tickets = (int *)realloc(tickets, capacity * sizeof(int));
                                    if (tickets == NULL) {
                                        printf("Ошибка при повторном выделении памяти");
                                        exit(1);
                                    }
                                }
                            } 
                        } 
                    } 
                } 
            } 
        } 
    } 
    
    *count = j;
    return tickets;
}

void test() {
    {
        int count = 0;
        int *tickets = find_lucky(&count);

        // printf("%d\n", tickets[345]);

        if(tickets[345] != 114141) {
            printf("Ошибка в тесте 1");
            exit(2);
        }

        // for (int i = 0; i < count; i++) {
        //     printf("%d \n", tickets[i]);
        // }

        free(tickets);
    }
    {
        int count = 0;
        int *tickets = find_lucky(&count);

        // printf("%d\n", tickets[0]);

        if(tickets[1] != 100010) {
            printf("Ошибка в тесте 2");
            exit(3);
        }

        // for (int i = 0; i < count; i++) {
        //     printf("%d \n", tickets[i]);
        // }

        free(tickets);
    }
    {
        int count = 0;
        int *tickets = find_lucky(&count);

        // printf("%d\n", tickets[50411]);

        if(tickets[50411] != 999999) {
            printf("Ошибка в тесте 3");
            exit(4);
        }

        // for (int i = 0; i < count; i++) {
        //     printf("%d \n", tickets[i]);
        // }

        free(tickets);
    }
}

int main(void) {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    test(); 
    return 0; 
}