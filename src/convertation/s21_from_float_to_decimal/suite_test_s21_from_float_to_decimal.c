// created by pizpotli
#include "../../test.h"

START_TEST(s21_float_to_decimal_test1) {
  float src = 3.7F;
  s21_decimal expected = {{37, 0, 0, 0}};
  scale(&expected, 1);

  s21_decimal got = {{0}};
  int return_value = s21_from_float_to_decimal(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_float_to_decimal_test2) {
  float src = -56765.1F;
  s21_decimal expected = {{567651, 0, 0, 0}};
  scale(&expected, 1);
  invert_bit_pointer(&expected, 127);

  s21_decimal got = {{0}};
  int return_value = s21_from_float_to_decimal(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_float_to_decimal_test3) {
  float src = 0.00000F;
  s21_decimal expected = {{0, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_from_float_to_decimal(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_float_to_decimal_test4) {
  float src = 0.00000001234567F;
  s21_decimal expected = {{1234567, 0, 0, 0}};
  scale(&expected, 14);
  s21_decimal got = {{0}};
  int return_value = s21_from_float_to_decimal(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_float_to_decimal_test5) {
  float src = 9876543.1F;
  s21_decimal expected = {{9876543, 0, 0, 0}};
  scale(&expected, 0);
  s21_decimal got = {{0}};
  int return_value = s21_from_float_to_decimal(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_float_to_decimal_test6) {
  float src = -9876543.7F;
  s21_decimal expected = {{9876544, 0, 0, 0}};
  scale(&expected, 0);
  invert_bit_pointer(&expected, 127);
  s21_decimal got = {{0}};
  int return_value = s21_from_float_to_decimal(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_float_to_decimal_test7) {
  float src = -9876543.5F;
  s21_decimal expected = {{9876544, 0, 0, 0}};
  scale(&expected, 0);
  invert_bit_pointer(&expected, 127);
  s21_decimal got = {{0}};
  int return_value = s21_from_float_to_decimal(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_float_to_decimal_test8) {
  float src = -9876542.5F;
  s21_decimal expected = {{9876542, 0, 0, 0}};
  scale(&expected, 0);
  invert_bit_pointer(&expected, 127);
  s21_decimal got = {{0}};
  int return_value = s21_from_float_to_decimal(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_float_to_decimal_test9) {
  float src = -9876542.50001F;
  s21_decimal expected = {{9876543, 0, 0, 0}};
  scale(&expected, 0);
  invert_bit_pointer(&expected, 127);
  s21_decimal got = {{0}};
  int return_value = s21_from_float_to_decimal(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_float_to_decimal_test10) {
  float src = NAN;

  s21_decimal got = {{0}};
  int return_value = s21_from_float_to_decimal(src, &got);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_float_to_decimal_test11) {
  float src = INFINITY;

  s21_decimal got = {{0}};
  int return_value = s21_from_float_to_decimal(src, &got);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_float_to_decimal_test12) {
  float src = -INFINITY;

  s21_decimal got = {{0}};
  int return_value = s21_from_float_to_decimal(src, &got);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_float_to_decimal_test13) {
  float src = 1.234e29;

  s21_decimal got = {{0}};
  int return_value = s21_from_float_to_decimal(src, &got);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_float_to_decimal_test14) {
  float src = 6.97e-28;

  s21_decimal got = {{0}};
  int return_value = s21_from_float_to_decimal(src, &got);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_float_to_decimal_test15) {
  float src = 1.55e-28;
  s21_decimal expected = {{2, 0, 0, 0}};
  scale(&expected, 28);

  s21_decimal got = {{0}};
  int return_value = s21_from_float_to_decimal(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_float_to_decimal_test16) {
  float src = 3456.45;

  int return_value = s21_from_float_to_decimal(src, NULL);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

Suite *test_func_float_to_decimal(void) {
  Suite *x;
  x = suite_create("check_s21_float_to_decimal");

  TCase *s21_float_to_decimal_case;

  s21_float_to_decimal_case = tcase_create("s21_float_to_decimal");
  suite_add_tcase(x, s21_float_to_decimal_case);

  tcase_add_test(s21_float_to_decimal_case, s21_float_to_decimal_test1);
  tcase_add_test(s21_float_to_decimal_case, s21_float_to_decimal_test2);
  tcase_add_test(s21_float_to_decimal_case, s21_float_to_decimal_test3);
  tcase_add_test(s21_float_to_decimal_case, s21_float_to_decimal_test4);
  tcase_add_test(s21_float_to_decimal_case, s21_float_to_decimal_test5);
  tcase_add_test(s21_float_to_decimal_case, s21_float_to_decimal_test6);
  tcase_add_test(s21_float_to_decimal_case, s21_float_to_decimal_test7);
  tcase_add_test(s21_float_to_decimal_case, s21_float_to_decimal_test8);
  tcase_add_test(s21_float_to_decimal_case, s21_float_to_decimal_test9);
  tcase_add_test(s21_float_to_decimal_case, s21_float_to_decimal_test10);
  tcase_add_test(s21_float_to_decimal_case, s21_float_to_decimal_test11);
  tcase_add_test(s21_float_to_decimal_case, s21_float_to_decimal_test12);
  tcase_add_test(s21_float_to_decimal_case, s21_float_to_decimal_test13);
  tcase_add_test(s21_float_to_decimal_case, s21_float_to_decimal_test14);
  tcase_add_test(s21_float_to_decimal_case, s21_float_to_decimal_test15);
  tcase_add_test(s21_float_to_decimal_case, s21_float_to_decimal_test16);

  return x;
}

void suite_test_s21_float_to_decimal(void) {
  Suite *x;
  SRunner *y;

  x = test_func_float_to_decimal();
  y = srunner_create(x);
  srunner_run_all(y, CK_VERBOSE);
  srunner_free(y);
}
