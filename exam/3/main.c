#include <stdio.h>
#include <float.h>
#include <locale.h>

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
#endif

int main() {
    setlocale(LC_ALL, "");

#if defined(_WIN32) || defined(_WIN64)
    // Устанавливаем кодировку консоли на UTF-8 для Windows
    SetConsoleOutputCP(CP_UTF8);
#endif  

    // Вывод машинного епсилон для типа float
    float machine_epsilon = FLT_EPSILON;

    // Вывод машинного нуля для типа float
    float machine_zero = 1.0f / (1.0f / machine_epsilon);
    
    // Ввод числа пользователем
    float number;
    printf("Введите вещественное число: ");
    scanf("%f", &number);
    
    // Находим «правого соседа» для данного числа
    float right_neighbor = number + machine_epsilon;

    // Вывод результатов
    printf("Машинный ноль (для float): %g\n", machine_zero);
    printf("Машинный епсилон (для float): %g\n", machine_epsilon);
    printf("Правый сосед для числа %.6f: %.6f\n", number, right_neighbor);

    return 0;
}
