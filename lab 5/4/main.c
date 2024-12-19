#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    int *numbers = NULL;
    int size = 0;  
    int input;

    printf("Введите натуральные числа (0 для завершения ввода):\n");

    while (1) {
        scanf_s("%d", &input);

        if (input == 0) {
            break;
        }

        if (input < 0) { // Проверка на натуральное число
            printf("Ошибка: введите натуральное число.\n");
            continue;
        }

        // Расширяем массив
        int *temp = realloc(numbers, (size + 1) * sizeof(int));

        if (temp == NULL) {
            printf("Ошибка выделения памяти.\n");
            free(numbers);
            return 1;
        }

        numbers = temp;
        numbers[size] = input; // Сохраняем число
        size++;
    }

    // Вывод чисел
    printf("Введённые числа:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");


    free(numbers);
    return 0;
}
