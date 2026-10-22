#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "methods.h"

// =========================================================================
// ||          МАТЕМАТИЧНА ФУНКЦІЯ                                        ||
// =========================================================================

// Обчислює значення f(x) = 0.25*x^5 + 4*(x + 20)^4 - 2*x
  double f(double x){
  return 0.25 * pow(x, 5.0) + 4.0 * pow(x + 20.0, 4.0) - 2.0 * x;
}

// =========================================================================
// ||           МЕТОД ХОРД                                                ||
// =========================================================================

double chord_method(double a, double b, double eps, double debug_mode, unsigned int *iter_count) {
    // x — поточне значення кореня (на початку дорівнює лівій межі a)
    double x = a;

    // x_prev — значення кореня з попереднього кроку (для перевірки точності)
    double x_prev = a;

    // iter — локальний лічильник виконаних кроків (ітерацій)
    unsigned int iter = 0;

    while (1) {
        iter++;

        x = a - (f(a) * (b - a)) / (f(b) - f(a));

        if (debug_mode) {
            printf("Chord Iter %2u: x = %10.6f, f(x) = %10.6f\n", iter, x, f(x));
        }

        // Перевірка умови зупинки
        if (fabs(x - x_prev) < eps || fabs(f(x)) < eps) {
            break;
        }

        // Звуження інтервалу
        if (f(a) * f(x) < 0) {
            b = x;
        } else {
            a = x;
        }
        x_prev = x;
    }

    *iter_count = iter;
    return x;
}

// =========================================================================
// ||           МЕТОД ПОЛОВИННОГО ДІЛЕННЯ                                 ||
// =========================================================================

double bisection_method(double a, double b, double eps, double debug_mode, unsigned int *iter_count){
    double x = a;
    unsigned int iter = 0;

    while (1) {
        iter++;
        x = (a + b) / 2.0; // Середина відрізка

        if (debug_mode) {
            printf("Bisec Iter %2u: x = %10.6f, f(x) = %10.6f\n", iter, x, f(x));
        }

        // Перевірка умови зупинки
        if (fabs(b - a) < eps || fabs(f(x)) < eps) {
            break;
        }

        // Звуження інтервалу
        if (f(a) * f(x) < 0) {
            b = x;
        } else {
            a = x;
        }
    }

    *iter_count = iter;
    return x;
}


