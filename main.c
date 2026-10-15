#include <stdio.h>   // Бібліотека для введення та виведення даних (printf, scanf)
#include <math.h>    // Бібліотека для математичних функцій (pow, fabs)
#include <time.h>    // Бібліотека для вимірювання часу (clock)

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

    // max_iter — початковий ліміт ітерацій до зупинки (наприклад, 10).
    // Тип unsigned int — ціле беззнакове число (тільки додатні числа).
    unsigned int max_iter = 10;

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

        // Обчислюємо значення функції на кінцях відрізка f(a) та f(b)
        // Формула Варіанта 2: f(x) = 0.25*x^5 + 4*(x + 20)^4 - 2*x
        double fa = 0.25 * pow(a, 5.0) + 4.0 * pow(a + 20.0, 4.0) - 2.0 * a;
        double fb = 0.25 * pow(b, 5.0) + 4.0 * pow(b + 20.0, 4.0) - 2.0 * b;

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
    
    return 0;
}
