// created by pizpotli
#include "../../test.h"

START_TEST(s21_int_to_decimal_test1) {
  int src = 37;
  s21_decimal expected = {{37, 0, 0, 0}};
  s21_decimal got = {{0}};
  int return_value = s21_from_int_to_decimal(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_int_to_decimal_test2) {
  int src = -567651;
  s21_decimal expected = {{567651, 0, 0, 0}};
  invert_bit_pointer(&expected, 127);

  s21_decimal got = {{0}};
  int return_value = s21_from_int_to_decimal(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_int_to_decimal_test3) {
  int src = 0;
  s21_decimal expected = {{0, 0, 0, 0}};
  s21_decimal got = {{0}};
  int return_value = s21_from_int_to_decimal(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_int_to_decimal_test4) {
  int src = 1234567;
  s21_decimal expected = {{1234567, 0, 0, 0}};
  s21_decimal got = {{0}};
  int return_value = s21_from_int_to_decimal(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_int_to_decimal_test5) {
  int src = INT_MAX;
  s21_decimal expected = {{INT_MAX, 0, 0, 0}};
  s21_decimal got = {{0}};
  int return_value = s21_from_int_to_decimal(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_int_to_decimal_test6) {
  int src = -9876543;
  s21_decimal expected = {{9876543, 0, 0, 0}};
  invert_bit_pointer(&expected, 127);
  s21_decimal got = {{0}};
  int return_value = s21_from_int_to_decimal(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

Suite *test_func_int_to_decimal(void) {
  Suite *x;
  x = suite_create("check_s21_int_to_decimal");

  TCase *s21_int_to_decimal_case;

  s21_int_to_decimal_case = tcase_create("s21_int_to_decimal");
  suite_add_tcase(x, s21_int_to_decimal_case);

  tcase_add_test(s21_int_to_decimal_case, s21_int_to_decimal_test1);
  tcase_add_test(s21_int_to_decimal_case, s21_int_to_decimal_test2);
  tcase_add_test(s21_int_to_decimal_case, s21_int_to_decimal_test3);
  tcase_add_test(s21_int_to_decimal_case, s21_int_to_decimal_test4);
  tcase_add_test(s21_int_to_decimal_case, s21_int_to_decimal_test5);
  tcase_add_test(s21_int_to_decimal_case, s21_int_to_decimal_test6);

  return x;  //
}

void suite_test_s21_int_to_decimal(void) {
  Suite *x;
  SRunner *y;

  x = test_func_int_to_decimal();
  y = srunner_create(x);
  srunner_run_all(y, CK_VERBOSE);
  srunner_free(y);
}
