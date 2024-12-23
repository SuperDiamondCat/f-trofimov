#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>

// Структура для представления даты
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Функция для сравнения двух дат
int compare_dates(Date date1, Date date2) {
    if (date1.year < date2.year) {
        return -1;  // date1 меньше date2
    } else if (date1.year > date2.year) {
        return 1;   // date1 больше date2
    }
    
    if (date1.month < date2.month) {
        return -1;  // date1 меньше date2
    } else if (date1.month > date2.month) {
        return 1;   // date1 больше date2
    }
    
    if (date1.day < date2.day) {
        return -1;  // date1 меньше date2
    } else if (date1.day > date2.day) {
        return 1;   // date1 больше date2
    }
    
    return 0; // Даты равны
}

void test() {
    {
        Date date1 = {15, 5, 2020};
        Date date2 = {20, 5, 2020};
        if(compare_dates(date1, date2) != -1) {
            printf("Ошибка в тесте 1");
            exit(1);
        } 
    }
    {
        Date date1 = {20, 5, 2020};
        Date date2 = {20, 5, 2020};
        if(compare_dates(date1, date2) != 0) {
            printf("Ошибка в тесте 2");
            exit(2);
        } 
    }
    {
        Date date1 = {25, 12, 2021};
        Date date2 = {1, 1, 2020};
        if(compare_dates(date1, date2) != 1) {
            printf("Ошибка в тесте 3");
            exit(3);
        } 
    }
}

int main(void) {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    test();
    return 0;
}
