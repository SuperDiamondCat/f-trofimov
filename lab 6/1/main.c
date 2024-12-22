#include <stdio.h>
#include <locale.h>

// Функция разделения для быстрой сортировки
int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);  // Индекс меньшего элемента

    for (int j = low; j < high; j++) {
        // Если текущий элемент меньше или равен опорному элементу
        if (array[j] <= pivot) {
            i++;    // Увеличить индекс меньшего элемента
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    return i + 1;
}

// Функция быстрой сортировки
void quicksort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    }
}

// Функция для печати массива
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

// Функция сортировки массива
void sortArray(int array[], int size) {
    quicksort(array, 0, size - 1);
}

int main() {
    // Устанавливаем локаль для поддержки русского языка
    setlocale(LC_ALL, "Russian");

    int array[] = { 10, 7, 8, 9, 1, 5 };
    int size = sizeof(array) / sizeof(array[0]);

    printf("Исходный массив:\n");
    printArray(array, size);

    sortArray(array, size);

    printf("Отсортированный массив:\n");
    printArray(array, size);
    return 0;
}
