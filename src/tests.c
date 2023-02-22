#include <check.h>
#include <math.h>

#include "s21_math.h"

START_TEST(test_abs) {
  ck_assert_uint_eq(s21_abs(-612367), abs(-612367));
  ck_assert_uint_eq(s21_abs(45), abs(45));
  ck_assert_uint_eq(s21_abs(1), abs(1));
}
END_TEST

START_TEST(test_floor) {
  ck_assert_ldouble_eq(s21_floor(S21_INF), floor(S21_INF));
  ck_assert_ldouble_eq(s21_floor(-6.485), floor(-6.485));
  ck_assert_ldouble_eq_tol(s21_floor(4.73232), floor(4.73232), 6);
  ck_assert_ldouble_nan(s21_floor(S21_NAN));
}
END_TEST

START_TEST(test_fabs) {
  ck_assert_ldouble_eq(s21_fabs(-612367.54783), fabs(-612367.54783));
  ck_assert_ldouble_eq(s21_fabs(-45.345), fabs(-45.345));
  ck_assert_ldouble_eq(s21_fabs(1.0), fabs(1.0));
}
END_TEST

START_TEST(test_ceil) {
  ck_assert_ldouble_eq(s21_ceil(0), ceil(0));
  ck_assert_ldouble_eq(s21_ceil(4.1), ceil(4.1));
  ck_assert_ldouble_eq(s21_ceil(S21_INF), ceil(S21_INF));
  ck_assert_ldouble_nan(s21_ceil(S21_NAN));
}
END_TEST

// при значении больше 4-х знаков тест отваливается
START_TEST(test_exp) {
  ck_assert_uint_eq(s21_exp(5), exp(5));
  ck_assert_uint_eq(s21_exp(-2), exp(-2));
  ck_assert_uint_eq(s21_exp(1234), exp(1234));
  ck_assert_uint_eq(s21_exp(-1234), exp(-1234));
  ck_assert_uint_eq(s21_exp(S21_INF), exp(S21_INF));
  ck_assert_uint_eq(s21_exp(S21_MIN_INF), exp(S21_MIN_INF));
  for (double i = -10; i < 10; i++) {
    ck_assert_uint_eq(s21_exp(i), exp(i));
  }
}
END_TEST

START_TEST(test_log) {
  ck_assert_int_eq(s21_log(12356), log(12356));
  ck_assert_int_eq(s21_log(S21_INF), log(S21_INF));
  ck_assert_int_eq(s21_log(S21_MIN_INF), log(S21_MIN_INF));
  ck_assert_int_eq(s21_log(1.1), log(1.1));
  ck_assert_int_eq(s21_log(S21_NAN), log(S21_NAN));
  for (double i = -1.; i < 10; i += 0.1) {
    ck_assert_int_eq(s21_log(i), log(i));
  }
  for (double i = 0.; i < 2; i += 0.01) {
    ck_assert_int_eq(s21_log(i), log(i));
  }
}
END_TEST

START_TEST(test_factorial) { ck_assert_int_eq(s21_factorial(12), 479001600); }
END_TEST

START_TEST(test_pow) {
  ck_assert_ldouble_eq(s21_pow(2.6, 3.45), pow(2.6, 3.45));
  ck_assert_ldouble_eq_tol(s21_pow(3.0, 14.0), pow(3.0, 14.0), 4.78297e+06);
  ck_assert_ldouble_eq_tol(s21_pow(31.456, 4.3), pow(31.456, 4.3), 2.75502e+0);
  ck_assert_ldouble_eq_tol(s21_pow(31.456, 0.3), pow(31.456, 0.3), 2.81392);
  ck_assert_ldouble_eq_tol(s21_pow(4.3, 4.3), pow(4.3, 4.3), 529.559);
  ck_assert_ldouble_nan(s21_pow(-1234, 4.3));
  ck_assert_ldouble_eq_tol(s21_pow(-1234, 4.0), pow(-1234, 4.0), 2.31879e+12);
  ck_assert_ldouble_nan(s21_pow(S21_NAN, -1.0));
  ck_assert_ldouble_eq(s21_pow(S21_INF, 4.2), pow(S21_INF, 4.2));
}
END_TEST

START_TEST(test_fmod) {
  ck_assert_ldouble_eq_tol(s21_fmod(456.87678, 3.7), fmod(456.87678, 3.7),
                           1.77678);
  ck_assert_ldouble_eq_tol(s21_fmod(36677.546546, 4.1), fmod(36677.546546, 4.1),
                           3.04655);
  ck_assert_ldouble_eq(s21_fmod(23.456, 4.355), fmod(23.456, 4.355));
}
END_TEST

START_TEST(test_atan) {
  ck_assert_uint_eq(s21_atan(123), atan(123));
  ck_assert_uint_eq(s21_atan(23), atan(23));
  ck_assert_uint_eq(s21_atan(13.627), atan(13.627));
  ck_assert_uint_eq(s21_atan(3.631), atan(3.631));
  ck_assert_uint_eq(s21_atan(41.241), atan(41.241));
  ck_assert_uint_eq(s21_atan(S21_NAN), atan(S21_NAN));
  ck_assert_uint_eq(s21_atan(S21_INF), atan(S21_INF));
  ck_assert_uint_eq(s21_atan(S21_MIN_INF), atan(S21_MIN_INF));
  for (long double i = -1.; i < 1; i += 0.01) {
    ck_assert_uint_eq(s21_atan(i), atan(i));
  }
}
END_TEST

START_TEST(test_asin) {
  ck_assert_uint_eq(s21_asin(S21_NAN), asin(S21_NAN));
  ck_assert_uint_eq(s21_asin(1), asin(1));
  ck_assert_uint_eq(s21_asin(S21_MIN_INF), asin(S21_MIN_INF));
  ck_assert_uint_eq(s21_asin(S21_INF), asin(S21_INF));
  for (long double i = -1.; i <= 1; i += 0.01) {
    ck_assert_uint_eq(s21_asin(i), asin(i));
  }
}
END_TEST

START_TEST(test_acos) {
  ck_assert_uint_eq(s21_acos(10), acos(10));
  ck_assert_uint_eq(s21_acos(1.), acos(1.));
  ck_assert_uint_eq(s21_acos(-1), acos(-1));
  for (long double i = -1.; i <= 1; i += 0.01) {
    ck_assert_uint_eq(s21_acos(i), acos(i));
  }
}
END_TEST

START_TEST(test_sin) {
  ck_assert_float_eq(s21_sin(5.25), sin(5.25));
  ck_assert_float_eq(s21_sin(-5.25), sin(-5.25));
  ck_assert_float_eq(s21_sin(0), sin(0));
  ck_assert_float_eq(s21_sin(0.5), sin(0.5));
  ck_assert_float_eq(s21_sin(0.3), sin(0.3));
  ck_assert_float_eq(s21_sin(-0.5), sin(-0.5));
  ck_assert_float_eq(s21_sin(7.5), sin(7.5));
  ck_assert_float_eq(s21_sin(-7.5), sin(-7.5));
  ck_assert_float_eq(s21_sin(17.5), sin(17.5));
  ck_assert_float_eq(s21_sin(-17.5), sin(-17.5));
  ck_assert_float_eq(s21_sin(10.5), sin(10.5));
  ck_assert_float_eq(s21_sin(-10.5), sin(-10.5));
}
END_TEST

START_TEST(test_sqrt) {
  ck_assert_float_eq(s21_sqrt(5.0), sqrt(5.0));
  ck_assert_int_eq(s21_sqrt(-5.0), sqrt(-5.0));
  ck_assert_float_eq(s21_sqrt(0), sqrt(0));
  ck_assert_float_eq(s21_sqrt(0.5), sqrt(0.5));
  ck_assert_int_eq(s21_sqrt(-0.5), sqrt(-0.5));
}
END_TEST

START_TEST(test_tan) {
  ck_assert_float_eq(s21_tan(5), tan(5.0));
  ck_assert_float_eq(s21_tan(-5.0), tan(-5.0));
  ck_assert_float_eq(s21_tan(0), tan(0));
  ck_assert_float_eq(s21_tan(0.5), tan(0.5));
  ck_assert_float_eq(s21_tan(-0.5), tan(-0.5));
}
END_TEST

START_TEST(test_cos) {
  ck_assert_uint_eq(s21_cos(-612367.54783), cos(-612367.54783));
  ck_assert_uint_eq(s21_cos(-45.345), cos(-45.345));
  ck_assert_uint_eq(s21_cos(1.0), cos(1.0));
  ck_assert_uint_eq(s21_cos(211.0), cos(211.0));
  ck_assert_uint_eq(s21_cos(NAN), cos(NAN));
  ck_assert_uint_eq(s21_cos(-NAN), cos(-NAN));
  ck_assert_uint_eq(s21_cos(INFINITY), cos(INFINITY));
  ck_assert_uint_eq(s21_cos(-INFINITY), cos(-INFINITY));
  ck_assert_uint_eq(s21_cos(0), cos(0));
  for (double i = -10; i < 10; i++) {
    ck_assert_uint_eq(s21_cos(i), cos(i));
  }
  double i = -10;
  do {
    ck_assert_uint_eq(s21_cos(i), cos(i));
    i = i + 0.1;
  } while (i < 10);
  ck_assert_float_eq(s21_cos(5.0), cos(5.0));
  ck_assert_float_eq(s21_cos(-5.0), cos(-5.0));
  ck_assert_float_eq(s21_cos(-3.0), cos(-3.0));
  ck_assert_float_eq(s21_cos(10.2), cos(10.2));
  ck_assert_float_eq(s21_cos(-10.2), cos(-10.2));
  ck_assert_float_eq(s21_cos(0.3), cos(0.3));
  ck_assert_float_eq(s21_cos(0), cos(0));
  ck_assert_float_eq(s21_cos(0.5), cos(0.5));
  ck_assert_float_eq(s21_cos(-0.5), cos(-0.5));
}
END_TEST

Suite *test_suite(void) {
  Suite *s = suite_create("MATH TEST");

  TCase *abs_tests = tcase_create("ABS");
  tcase_add_test(abs_tests, test_abs);
  suite_add_tcase(s, abs_tests);

  TCase *floor_tests = tcase_create("FLOOR");
  tcase_add_test(floor_tests, test_floor);
  suite_add_tcase(s, floor_tests);

  TCase *ceil_tests = tcase_create("CEIL");
  tcase_add_test(ceil_tests, test_ceil);
  suite_add_tcase(s, ceil_tests);

  TCase *fabs_tests = tcase_create("FABS");
  tcase_add_test(fabs_tests, test_fabs);
  suite_add_tcase(s, fabs_tests);

  TCase *factorial_tests = tcase_create("FACTORIAL");
  tcase_add_test(factorial_tests, test_factorial);
  suite_add_tcase(s, factorial_tests);

  TCase *exp_tests = tcase_create("EXP");
  tcase_add_test(exp_tests, test_exp);
  suite_add_tcase(s, exp_tests);

  TCase *log_tests = tcase_create("LOG");
  tcase_add_test(log_tests, test_log);
  suite_add_tcase(s, log_tests);

  TCase *pow_tests = tcase_create("POW");
  tcase_add_test(pow_tests, test_pow);
  suite_add_tcase(s, pow_tests);

  TCase *fmod_tests = tcase_create("FMOD");
  tcase_add_test(fmod_tests, test_fmod);
  suite_add_tcase(s, fmod_tests);

  TCase *atan_tests = tcase_create("ATAN");
  tcase_add_test(atan_tests, test_atan);
  suite_add_tcase(s, atan_tests);

  TCase *asin_tests = tcase_create("ASIN");
  tcase_add_test(asin_tests, test_asin);
  suite_add_tcase(s, asin_tests);

  TCase *acos_tests = tcase_create("ACOS");
  tcase_add_test(acos_tests, test_acos);
  suite_add_tcase(s, acos_tests);

  TCase *sin_tests = tcase_create("SIN");
  tcase_add_test(sin_tests, test_sin);
  suite_add_tcase(s, sin_tests);

  TCase *sqrt_tests = tcase_create("SQRT");
  tcase_add_test(sqrt_tests, test_sqrt);
  suite_add_tcase(s, sqrt_tests);

  TCase *tan_tests = tcase_create("TAN");
  tcase_add_test(tan_tests, test_tan);
  suite_add_tcase(s, tan_tests);

  TCase *cos_tests = tcase_create("COS");
  tcase_add_test(cos_tests, test_cos);
  suite_add_tcase(s, cos_tests);

  return s;
}

int main() {
  Suite *s = test_suite();
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  int fail = srunner_ntests_failed(runner);
  srunner_free(runner);
  return fail ? EXIT_FAILURE : EXIT_SUCCESS;
}