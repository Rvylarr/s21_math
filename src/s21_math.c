#include "s21_math.h"
// вычисляет абсолютное значение целого числа
int s21_abs(int x) { return x > 0 ? x : -x; }
// возвращает ближайшее целое число, не превышающее заданное значение
long double s21_floor(double x) {
  if (x == S21_INF)
    x = S21_INF;
  else if (!S21_IS_NAN(x)) {
    long double rounded_x = (long long int)x;
    if (s21_fabs(x - rounded_x) > 0. && s21_fabs(x) > 0.)
      if (x < 0.) {
        rounded_x -= 1;
      }
    x = rounded_x;
  }
  return x;
}
// возвращает ближайшее целое число, не меньшее заданного значения
long double s21_ceil(double x) {
  if (S21_IS_INF(x))
    x = S21_INF;
  else if (S21_IS_NAN(x))
    x = S21_NAN;
  else if (!S21_IS_NAN(x) || !-S21_IS_INF(x) || x != 0) {
    long double rounded_x = (long long int)x;
    if (s21_fabs(x) > 0. && x != rounded_x) {
      if (x > 0.) {
        rounded_x += 1;
      }
    }
    x = rounded_x;
  }
  return x;
}

// вычисляет абсолютное значение числа с плавающей точкой
long double s21_fabs(double x) {
  if (x == x) {
    if (x == S21_MIN_INF || x == S21_INF) x = 0;
    if (x < 0) x = -x;
  }
  return x;
}
// вычисляет синус
long double s21_sin(double x) {
  if (S21_IS_NAN(x) || S21_IS_INF(x)) return S21_NAN_VAL;
  if (s21_fabs(x) < S21_EPSILON) return x;
  while (s21_fabs(x) > 2 * S21_PI) {
    if (x > 0)
      x -= 2 * S21_PI;
    else
      x += 2 * S21_PI;
  }
  if (x >= S21_PI / 2 && x <= S21_PI / 2 + S21_EPSILON) return 0.0;
  long double res = (long double)x;
  long double factor = 1.0L;
  long double ch = res;
  int i = 1;
  while (s21_fabs(ch / factor) > 1e-100 && i < 100) {
    factor *= ((2 * i) * (2 * i + 1));
    ch *= -1.0L * (long double)x * (long double)x;
    res += ch / factor;
    i++;
  }
  return res;
}
// вычисляет косинус
long double s21_cos(double x) {
  long double res = (long double)x;
  if (S21_IS_NAN(x) || S21_IS_INF(x)) {
    res = S21_NAN_VAL;
  } else {
    int cosZero = 0;
    if ((x) == 0) cosZero = 1;

    while (x > S21_PI || x < -S21_PI) {
      x += x > S21_PI ? -2 * S21_PI : 2 * S21_PI;
    }

    x = (S21_PI / 2 - x);
    res = (long double)x;
    long double factor = 1.0L;
    long double ch = res;
    int i = 1;
    while (s21_fabs(ch / factor) > 1e-100 && i < 100) {
      factor *= ((2 * i) * (2 * i + 1));
      ch *= -1.0L * (long double)x * (long double)x;
      res += ch / factor;
      i++;
    }
    if (cosZero == 1) {
      res = 1.0;
    }
  }
  return res;
}
// вычисляет тангенс
long double s21_tan(double x) {
  if (S21_IS_NAN(x) || S21_IS_INF(x)) return S21_NAN_VAL;
  return s21_sin(x) / s21_cos(x);
}
// вычисляет арксинус
long double s21_asin(double x) {
  if (x != x || x > 1.0 || x < -1.0) {
    x = S21_NAN;
  } else if (x == 1) {
    x = S21_PI_2;
  } else if (x == -1) {
    x = -S21_PI_2;
  } else {
    x = s21_atan(x / s21_sqrt(1 - x * x));
  }
  return x;
}
// вычисляет арккосинус
long double s21_acos(double x) {
  if (x != x || x > 1.0 || x < -1.0) {
    x = S21_NAN;
  } else if (x == 1) {
    x = 0;
  } else if (x == -1) {
    x = S21_PI;
  } else {
    x = S21_PI_2 - s21_asin(x);
  }
  return x;
}
// вычисляет арктангенс
long double s21_atan(double x) {
  int znak = 0, invertation = 0, step = 0;
  long double res = 0, x_square = x * x;
  if (x != x) {
    res = -S21_NAN;
  } else if (x == S21_INF) {
    res = S21_PI_2;
  } else if (x == S21_MIN_INF) {
    res = -S21_PI_2;
  } else {
    if (x < 0.) {
      x *= -1;
      znak++;
    }
    if (x > 1.) {
      x = 1. / x;
      invertation++;
    }
    while (x > S21_PI_12) {
      step++;
      res = 1. / (x + s21_sqrt(3));
      x = (x * s21_sqrt(3) - 1) * res;
    }
    x_square = x * x;
    res = x_square + 1.4087812F;
    res = 0.55913709F / res;
    res += 0.60310579F;
    res -= 0.05160454F * x_square;
    res *= x;
    while (step > 0) {
      res += S21_PI_6;
      step--;
    }
    if (invertation) res = S21_PI_2 - res;
    if (znak) res *= -1;
  }
  return res;
}
// вычисляет квадратный корень
long double s21_sqrt(double x) {
  long double y = 4, z = 0;
  if (x == 0) {
    return 0;
  } else {
    while (s21_fabs(y - z) > S21_EPSILON) {
      if (x < 0) {
        y = -S21_NAN_VAL;
        break;
      }
      z = y;
      y = (z + x / z) / 2;
    }
  }
  return y;
}
// остаток операции деления с плавающей точкой
long double s21_fmod(double x, double y) {
  unsigned long long int res = 0;
  long double mem = x;

  if (y == 0) x = S21_NAN;
  if (x == x && y == y) {
    x = s21_fabs(x);
    y = s21_fabs(y);
    res = x / y;
    x = x - res * y;
    x = mem < 0 ? -x : x;
  }
  return y != y ? S21_NAN : x;
}
// факториализация
long double s21_factorial(double x) {
  if (x == x) {
    if (x == 0)
      x = 1;
    else
      x = x * s21_factorial(x - 1);
  }
  return x;
}
// возвращает значение e, возведенное в заданную степень
long double s21_exp(double x) {
  long double snowball = 1;
  long double num = 1;
  int i = 1;

  if (x == x) {
    if (x == S21_INF) x = S21_INF;
    if (x == S21_MIN_INF)
      x = 0;
    else {
      long double xx = x;
      if (xx < 0) xx = -x;
      while (s21_fabs(num) > 1e-15) {
        num *= x / i;  // слагаемое
        i++;
        snowball += num;
      }
      x = snowball;
      if (xx < 0) x = 1 / x;
    }
  }
  if (x == S21_MIN_INF) x = 0;
  return x;
}
// вычисляет натуральный логарифм
long double s21_log(double x) {
  long double num = 0, result = x;
  double previous = 0;
  int ex_pow = 0;

  if (result == result && result >= 0) {
    if (s21_fabs(result) < S21_EPSILON)
      result = S21_MIN_INF;
    else if (result == S21_INF)
      result = S21_INF;
    else if (result == S21_MIN_INF || result == 0)
      result = S21_NAN;
    else if (result > 0) {
      for (; result >= S21_E; result /= S21_E, ex_pow++) continue;
      for (int i = 0; i < 100; i++) {
        previous = num;
        num = previous +
              2 * ((result - s21_exp(previous)) / (result + s21_exp(previous)));
      }
      result = num + ex_pow;
    }
  } else
    result = S21_NAN;
  return result;
}
// возводит число в заданную степень
long double s21_pow(double base, double exp) {
  long double result = 0;

  if (base == 1 || exp == 0 || (base == -1 && (exp == S21_INF))) {
    result = 1;
  } else if ((s21_fabs(base) < 1 && exp == S21_MIN_INF) ||
             (s21_fabs(base) > 1 && exp == S21_INF) ||
             (base == S21_MIN_INF &&
              ((exp > 0 && (int)exp % 2 == 0) || exp == S21_INF)) ||
             (base == S21_INF && exp > 0)) {
    result = S21_INF;
  } else if ((base < 0 && (int)exp - exp != 0) ||
             (base != base && exp != exp)) {
    result = S21_NAN;
  } else if ((base == 0 && exp > 0) || (base == S21_MIN_INF && exp < 0) ||
             (s21_fabs(base) > 1 && exp == S21_MIN_INF) ||
             (s21_fabs(base) < 1 && exp == S21_INF) ||
             (base == S21_MIN_INF && (exp < 0 && (int)exp % 2 == 0))) {
    result = 0;
  } else if (base == S21_MIN_INF && (exp > 0 && (int)exp % 2 != 0)) {
    result = S21_MIN_INF;
  } else {
    if (base < 0) {
      base = -base;
      result = s21_exp(exp * s21_log(base));
      result = s21_fmod(exp, 2) != 0 ? -result : result;
    } else
      result = s21_exp(exp * s21_log(base));
  }
  return result;
}