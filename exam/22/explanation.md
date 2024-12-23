Эта программа выполняет разложение введённого числа на простые множители с использованием рекурсивного подхода. Вот подробное объяснение:

---

### 1. **Функция `is_prime`**
- **Назначение**: Проверяет, является ли число простым.
- **Как работает**:
  - Если число меньше или равно 1, оно не является простым.
  - Проверяется делимость числа `n` на все числа от 2 до квадратного корня из `n`. Если делитель найден, число не является простым.
  - Если делителей не найдено, число считается простым.

---

### 2. **Функция `factorize`**
- **Назначение**: Рекурсивно разлагает число на простые множители.
- **Как работает**:
  1. Если число `n` меньше или равно 1, функция завершает выполнение (базовый случай рекурсии).
  2. Ищется первый простой делитель числа `n`, начиная с 2.
  3. Если делитель найден:
     - Он выводится на экран.
     - Функция вызывается снова для оставшейся части числа (`n / i`).
  4. Рекурсия продолжается, пока число полностью не разложится на множители.

---

### 3. **Функция `main`**
- **Назначение**: Организует ввод данных и вызывает разложение.
- **Как работает**:
  - Пользователь вводит целое число.
  - Выводится сообщение о найденных простых множителях.
  - Функция `factorize` вызывается для разложения введённого числа.
  - После выполнения выводится результат.

---

### Пример выполнения программы

#### Ввод:
```
Enter a number: 60
```

#### Шаги разложения:
1. Функция находит первый простой делитель: `2`.
2. Рекурсивно вызывает `factorize(30)`, где находит делитель `2`.
3. Рекурсивно вызывает `factorize(15)`, где находит делитель `3`.
4. Рекурсивно вызывает `factorize(5)`, где находит делитель `5`.
5. Число разложено, рекурсия завершается.

#### Вывод:
```
Prime factors: 2 2 3 5
```

---

### Основные моменты:
- **Рекурсия**: Используется для последовательного разложения числа.
- **Простые числа**: Проверяются с помощью функции `is_prime`.
- **Минимальные делители**: Найдены в порядке возрастания, начиная с 2.

Этот подход работает для всех положительных чисел больше 1.