#include <stdio.h>   // Бібліотека для введення та виведення даних (printf, scanf)
#include <math.h>    // Бібліотека для математичних функцій (pow, fabs)
#include <time.h>    // Бібліотека для вимірювання часу (clock)
#include "methods.h"

int main() {

    // =========================================================================
    // 1. ОГОЛОШЕННЯ ЗМІННИХ ТА ПОЯСНЕННЯ ТИПІВ ДАНИХ
    // =========================================================================

    // method_choice — вибір чисельного методу (1: Половинного ділення, 2: Хорд).
    // Тип int (ціле число).
    int method_choice = 0;

    // debug_choice — прапорець режиму відладки (1: Показувати кожну ітерацію, 0: Ні).
    int debug_choice = 0;

    // a, b — межі відрізка [a, b], на якому шукаємо корінь.
    // eps — точність обчислень (наприклад, 0.0001).
    // Тип double — дійсне дробове число подвійної точності (8 байт у пам'яті).
    double a = 0.0;
    double b = 0.0;
    double eps = 0.0001;

    // =========================================================================
    // 2. ВВЕДЕННЯ ТА ВАЛІДАЦІЯ ВХІДНИХ ДАНИХ
    // =========================================================================

    // Вибір методу розв'язання (1 або 2)
    while (1) {
        printf("Choose method (1 - Bisection, 2 - Chord): ");
        if (scanf("%d", &method_choice) != 1) {
            printf("Error! Enter a number.\n\n");
            while (getchar() != '\n'); // Очищення буфера клавіатури від літер
        }
        else if (method_choice == 1 || method_choice == 2) {
            break; // Коректний вибір — виходимо з циклу
        }
        else {
            printf("Error! Choose 1 or 2.\n\n");
        }
    }

    // Вибір режиму відладки (0 або 1)
    while (1) {
        printf("Show iterations? (1 - Yes, 0 - No): ");
        if (scanf("%d", &debug_choice) != 1) {
            printf("Error! Enter a number.\n\n");
            while (getchar() != '\n');
        }
        else if (debug_choice == 0 || debug_choice == 1) {
            break;
        }
        else {
            printf("Error! Choose 0 or 1.\n\n");
        }
    }

    // Введення меж відрізка [a, b] та точності eps
    while (1) {
        printf("\nEnter a, b, eps:\n");
        printf("a   = "); scanf("%lf", &a);
        printf("b   = "); scanf("%lf", &b);
        printf("eps = "); scanf("%lf", &eps);

        if (a >= b) {
            printf("Error! 'a' must be less than 'b'.\n");
        }
        else if (eps <= 0) {
            printf("Error! 'eps' must be > 0.\n");
        }
        // Перевірка існування кореня: знаки f(a) та f(b) мають бути протилежними!
        else if (fa * fb > 0) {
            printf("Error! f(a) and f(b) must have opposite signs.\n");
        }
        else {
            break; // Відрізок вибрано правильно
        }
        while (getchar() != '\n');
    }
    
    // =========================================================================
    // 3. ОСНОВНИЙ ОБЧИСЛЮВАЛЬНИЙ ЦИКЛ С ТАЙМЕРОМ ТА ЛІМІТОМ ІТЕРАЦІЙ
    // =========================================================================

    double root = 0.0;                   // Змінна для знайденого кореня x
    unsigned int total_iter = 0;         // Лічильник ітерацій

    clock_t start_time = clock();

   // МЕТОД 1: Половинного ділення (Bisection)
        if (method_choice == 1) {
            root = bisection_method(a, b, eps, debug_choice, &total_iter);
    } else if (method_choice == 2) {
        root = chord_method(a, b, eps, debug_choice, &total_iter);
    }

    clock_t end_time = clock();
    double exec_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // =========================================================================
    // 4. ВИВЕДЕННЯ РЕЗУЛЬТАТІВ ТА ПЕРЕВІРКА ПОХІДНОЇ
    // =========================================================================

    printf("\n========================================\n");
    printf("SUCCESSFULLY COMPLETED!\n");
    printf("========================================\n");
    printf("Root x           = %.8f\n", root);
    printf("Function f(x)    = %.8f\n", final_f);
    printf("Iterations       = %u\n", total_iter);
    printf("Time             = %.6f seconds\n", exec_time);
    printf("========================================\n");

    return 0;
}
