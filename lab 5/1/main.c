#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    int *array;
    const int N = 20;

    array = (int*)malloc(N * sizeof(int));

    if (array == NULL) {  // Проверка успешности выделения памяти
        printf("Ошибка выделения памяти.\n");
        return 1;
    }
    srand(time(NULL));

    printf("Случайные числа:\n");
    for (int i = 0; i < N; ++i) {
        // Генерация случайных чисел в диапазоне [-3, 7]
        array[i] = -3 + rand() % 11;

        printf("%d ", array[i]);
    }

    // Освобождаем выделенную память
    free(array);

    return 0;
}
