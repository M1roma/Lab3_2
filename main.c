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
    
    // =========================================================================
    // 3. ОСНОВНИЙ ОБЧИСЛЮВАЛЬНИЙ ЦИКЛ С ТАЙМЕРОМ ТА ЛІМІТОМ ІТЕРАЦІЙ
    // =========================================================================

    double root = 0.0;                   // Змінна для знайденого кореня x
    double cur_a = a;                    // Поточна ліва межа
    double cur_b = b;                    // Поточна права межа
    double x_prev = a;                   // Попереднє значення x (для методу хорд)

    unsigned int total_iter = 0;         // Лічильник ітерацій
    unsigned int current_limit = max_iter; // Поточний ліміт ітерацій
    int stop_flag = 0;                   // Прапорець переривання користувачем

    // Фіксуємо час початку розрахунку за допомогою функції clock()
    clock_t start_time = clock();

    while (1) {
        total_iter = total_iter + 1; // Збільшуємо лічильник ітерацій на 1

        // МЕТОД 1: Половинного ділення (Bisection)
        if (method_choice == 1) {
            root = (cur_a + cur_b) / 2.0; // Знаходимо середину відрізка

            // Обчислюємо значення функції у середині f(root)
            double f_root = 0.25 * pow(root, 5.0) + 4.0 * pow(root + 20.0, 4.0) - 2.0 * root;
            double f_a = 0.25 * pow(cur_a, 5.0) + 4.0 * pow(cur_a + 20.0, 4.0) - 2.0 * cur_a;

            // Виведення інформації про ітерацію, якщо увімкнено відладку
            if (debug_choice == 1) {
                printf("Iter %2u: x = %10.6f, f(x) = %10.6f\n", total_iter, root, f_root);
            }

            // Умова досягнення точності: fabs() — обчислення модуля числа (значення без знака)
            if (fabs(cur_b - cur_a) < eps || fabs(f_root) < eps) {
                break; // Корінь знайдено з потрібною точністю
            }

            // Звужуємо інтервал: якщо знаки протилежні, корінь у лівій половині
            if (f_a * f_root < 0) {
                cur_b = root;
            } else {
                cur_a = root;
            }
        }
        // МЕТОД 2: Хорд (Chord)
        else if (method_choice == 2) {
            double f_a = 0.25 * pow(cur_a, 5.0) + 4.0 * pow(cur_a + 20.0, 4.0) - 2.0 * cur_a;
            double f_b = 0.25 * pow(cur_b, 5.0) + 4.0 * pow(cur_b + 20.0, 4.0) - 2.0 * cur_b;

            // Формула методу хорд
            root = cur_a - (f_a * (cur_b - cur_a)) / (f_b - f_a);

            double f_root = 0.25 * pow(root, 5.0) + 4.0 * pow(root + 20.0, 4.0) - 2.0 * root;

            if (debug_choice == 1) {
                printf("Iter %2u: x = %10.6f, f(x) = %10.6f\n", total_iter, root, f_root);
            }

            // Перевірка умови зупинки за точністю
            if (fabs(root - x_prev) < eps || fabs(f_root) < eps) {
                break;
            }

            if (f_a * f_root < 0) {
                cur_b = root;
            } else {
                cur_a = root;
            }
            x_prev = root; // Зберігаємо поточний корінь як попередній
        }

        // --- ПЕРЕВІРКА ПЕРЕВИЩЕННЯ ЛІМІТУ ІТЕРАЦІЙ (Пункт 3б методички) ---
        if (total_iter >= current_limit) {
            printf("\nLimit of %u iterations reached!\n", current_limit);
            printf("1 - Continue (+10 iter)\n");
            printf("2 - Run to the end\n");
            printf("3 - Stop and show result\n");
            printf("Action: ");

            int user_action = 0;
            scanf("%d", &user_action);

            if (user_action == 1) {
                current_limit = current_limit + max_iter; // Додаємо ще 10 ітерацій
            } else if (user_action == 2) {
                current_limit = 4294967295U; // Знімаємо ліміт (максимальне ціле число)
            } else {
                stop_flag = 1; // Зупиняємо розрахунок за бажанням користувача
                break;
            }
        }
    }

    // Фіксуємо час закінчення розрахунку
    clock_t end_time = clock();

    // Переводимо час у секунди (ділимо різницю тактів на константу CLOCKS_PER_SEC)
    double exec_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // =========================================================================
    // 4. ВИВЕДЕННЯ РЕЗУЛЬТАТІВ ТА ПЕРЕВІРКА ПОХІДНОЇ
    // =========================================================================

    // Обчислюємо значення функції f(x) та її похідної f'(x) у знайденому корені
    double final_f = 0.25 * pow(root, 5.0) + 4.0 * pow(root + 20.0, 4.0) - 2.0 * root;
    double final_df = 1.25 * pow(root, 4.0) + 16.0 * pow(root + 20.0, 3.0) - 2.0;

    printf("\n========================================\n");
    if (stop_flag == 1) {
        printf("CALCULATION INTERRUPTED BY USER!\n");
    } else {
        printf("SUCCESSFULLY COMPLETED!\n");
    }
    printf("========================================\n");
    printf("Root x           = %.8f\n", root);
    printf("Function f(x)    = %.8f\n", final_f);
    printf("Derivative f'(x) = %.8f\n", final_df);
    printf("Iterations       = %u\n", total_iter);
    printf("Time             = %.6f seconds\n", exec_time);
    printf("========================================\n");

    
    return 0;
}
