#ifndef SRC_MATH_H
#define SRC_MATH_H

//#include <check.h>
#include <stdio.h>
#include <stdlib.h>

// числовые константы
#define S21_E 2.71828182845904523536
#define S21_EPSILON 1e-7
#define S21_NAN 0.0 / 0.0
#define S21_PI 3.14159265358979323846
#define S21_PI_2 1.57079632679489661923132169163975144
#define S21_PI_12 (S21_PI / 12.)
#define S21_PI_6 (S21_PI / 6.)

// макросы
#define S21_MIN_INF -__builtin_huge_vall()
#define S21_INF __builtin_huge_vall()
#define S21_NAN_VAL (__builtin_nanf(""))
#define S21_IS_NAN(x) __builtin_isnan(x)
#define S21_IS_INF(x) __builtin_isinf_sign(x)

int s21_abs(int x);
long double s21_floor(double x);
long double s21_ceil(double x);
long double s21_fabs(double x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);
long double s21_sqrt(double x);
long double s21_fmod(double x, double y);
long double s21_factorial(double x);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_pow(double base, double exp);

#endif  // SRC_MATH_H