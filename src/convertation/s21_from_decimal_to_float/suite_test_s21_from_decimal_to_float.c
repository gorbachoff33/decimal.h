// created by pizpotli
#include "../../test.h"

START_TEST(s21_decimal_to_float_test1) {
  float expected = 3.7;
  s21_decimal src = {{37, 0, 0, 0}};
  scale(&src, 1);
  float got;
  int return_value = s21_from_decimal_to_float(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_float_eq(got, expected);
}
END_TEST
START_TEST(test1) {
  float expected = 3.7F;
  s21_decimal src = {{37, 0, 0, 0}};
  scale(&src, 1);
  float got;
  int return_value = s21_from_decimal_to_float(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_float_eq(got, expected);
}
END_TEST

START_TEST(test2) {
  float expected = -56765.1F;
  s21_decimal src = {{567651, 0, 0, 0}};
  scale(&src, 1);
  invert_bit_pointer(&src, 127);

  float got;
  int return_value = s21_from_decimal_to_float(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_float_eq(got, expected);
}
END_TEST

START_TEST(test3) {
  float expected = 0.00000F;
  s21_decimal src = {{0, 0, 0, 0}};

  float got;
  int return_value = s21_from_decimal_to_float(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_float_eq(got, expected);
}
END_TEST

START_TEST(test4) {
  float expected = 0.00000001234567F;
  s21_decimal src = {{1234567, 0, 0, 0}};
  scale(&src, 14);
  float got;
  int return_value = s21_from_decimal_to_float(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_float_eq(got, expected);
}
END_TEST

START_TEST(test5) {
  float expected = 9876543.0F;
  s21_decimal src = {{9876543, 0, 0, 0}};
  scale(&src, 0);
  float got;
  int return_value = s21_from_decimal_to_float(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_float_eq(got, expected);
}
END_TEST

START_TEST(test6) {
  float expected = -9876544.0F;
  s21_decimal src = {{98765437, 0, 0, 0}};
  scale(&src, 1);
  invert_bit_pointer(&src, 127);
  float got;
  int return_value = s21_from_decimal_to_float(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_float_eq(got, expected);
}
END_TEST

START_TEST(test7) {
  float expected = -9876544.0F;
  s21_decimal src = {{98765435, 0, 0, 0}};
  scale(&src, 1);
  set_znak_minys(&src);
  float got;
  int return_value = s21_from_decimal_to_float(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_float_eq(got, expected);
}
END_TEST

START_TEST(test8) {
  float expected = -9876542.0F;
  s21_decimal src = {{98765425, 0, 0, 0}};
  scale(&src, 1);
  set_znak_minys(&src);
  float got;
  int return_value = s21_from_decimal_to_float(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_float_eq(got, expected);
}
END_TEST

START_TEST(test9) {
  float expected = -9876543.0F;
  s21_decimal src = {{987654251, 0, 0, 0}};
  scale(&src, 2);
  set_znak_minys(&src);
  float got;
  int return_value = s21_from_decimal_to_float(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_float_eq_tol(got, expected, 6);
}
END_TEST

START_TEST(test10) {
  s21_decimal src = {{987654251, 0, 0, 0}};
  scale(&src, 2);
  set_znak_minys(&src);

  int return_value = s21_from_decimal_to_float(src, NULL);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

Suite *test_func_decimal_to_float(void) {
  Suite *x;
  x = suite_create("check_s21_decimal_to_float");

  TCase *s21_decimal_to_float_case;

  s21_decimal_to_float_case = tcase_create("s21_decimal_to_float");
  suite_add_tcase(x, s21_decimal_to_float_case);

  tcase_add_test(s21_decimal_to_float_case, s21_decimal_to_float_test1);
  tcase_add_test(s21_decimal_to_float_case, test1);
  tcase_add_test(s21_decimal_to_float_case, test2);
  tcase_add_test(s21_decimal_to_float_case, test3);
  tcase_add_test(s21_decimal_to_float_case, test4);
  tcase_add_test(s21_decimal_to_float_case, test5);
  tcase_add_test(s21_decimal_to_float_case, test6);
  tcase_add_test(s21_decimal_to_float_case, test7);
  tcase_add_test(s21_decimal_to_float_case, test8);
  tcase_add_test(s21_decimal_to_float_case, test9);
  tcase_add_test(s21_decimal_to_float_case, test10);
  return x;
}

void suite_test_s21_decimal_to_float(void) {
  Suite *x;
  SRunner *y;

  x = test_func_decimal_to_float();
  y = srunner_create(x);
  srunner_run_all(y, CK_VERBOSE);
  srunner_free(y);
}
