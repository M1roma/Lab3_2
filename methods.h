#ifndef METHOD.H
#define METHOD.H

/////////////////////////////////////////////////
//////       ПРОТОТИП ФУНКЦІЇ       /////////////
/////////////////////////////////////////////////

/**
 * @file methods.h
 * @brief Модуль чисельних методів розв'язання нелінійних рівнянь
 * @details Містить прототипи функцій для методу хорд та методу половинного ділення.
 */

/**
 * @brief Обчислення математичної функції f(x) для Варіанта 2
 * @param x Аргумент функції
 * @return Значення f(x) = 0.25*x^5 + 4*(x + 20)^4 - 2*x
 */
double f(double x);


/**
 * @brief Метод хорд для пошуку кореня нелінійного рівняння
 * @param a Ліва межа відрізка [a, b]
 * @param b Права межа відрізка [a, b]
 * @param eps Точність обчислень
 * @param debug_mode Прапорець виведення проміжних ітерацій (1 - так, 0 - ні)
 * @param iter_count Вказівник для збереження кількості виконаних ітерацій
 * @return Знайдений корінь рівняння
 */
double chord_method(double a, double b, double eps, double debug_mode, unsigned int *iter_count);

/**
 * @brief Метод половинного ділення
 * @param a Ліва межа відрізка [a, b]
 * @param b Права межа відрізка [a, b]
 * @param eps Точність обчислень
 * @param debug_mode Прапорець виведення проміжних ітерацій (1 - так, 0 - ні)
 * @param iter_count Вказівник для збереження кількості виконаних ітерацій
 * @return Знайдений корінь рівняння
 */
double bisection_method(double a, double b, double eps, double debug_mode, unsigned int *iter_count);



#endif
