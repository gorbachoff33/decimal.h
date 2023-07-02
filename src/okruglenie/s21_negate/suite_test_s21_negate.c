// created by pizpotli
#include "../../test.h"

START_TEST(test1) {
  s21_decimal src = {{37, 0, 0, 0}};
  s21_decimal expected = {{37, 0, 0, 0}};
  scale(&expected, 1);
  scale(&src, 1);

  invert_bit_pointer(&expected, 127);

  s21_decimal got = {{0}};
  int return_value = s21_negate(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test2) {
  s21_decimal src = {{567651, 0, 0, 0}};
  s21_decimal expected = {{567651, 0, 0, 0}};
  scale(&expected, 1);
  scale(&src, 1);

  invert_bit_pointer(&expected, 127);

  s21_decimal got = {{0}};
  int return_value = s21_negate(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test3) {
  s21_decimal src = {{0, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};

  invert_bit_pointer(&expected, 127);
  s21_decimal got = {{0}};
  int return_value = s21_negate(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test4) {
  s21_decimal src = {{1234567, 0, 0, 0}};
  s21_decimal expected = {{1234567, 0, 0, 0}};
  scale(&expected, 14);
  scale(&src, 14);

  invert_bit_pointer(&expected, 127);

  s21_decimal got = {{0}};
  int return_value = s21_negate(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test5) {
  s21_decimal src = {{9876543, 0, 0, 0}};
  s21_decimal expected = {{9876543, 0, 0, 0}};
  scale(&expected, 15);
  scale(&src, 15);
  invert_bit_pointer(&expected, 127);

  s21_decimal got = {{0}};
  int return_value = s21_negate(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test6) {
  s21_decimal src = {{9876544, 0, 0, 0}};
  s21_decimal expected = {{9876544, 0, 0, 0}};
  scale(&expected, 28);
  scale(&src, 28);
  invert_bit_pointer(&expected, 127);

  s21_decimal got = {{0}};
  int return_value = s21_negate(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test7) {
  s21_decimal src = {{9876544, 8786876, 23, 0}};
  s21_decimal expected = {{9876544, 8786876, 23, 0}};
  scale(&expected, 1);
  scale(&src, 1);
  invert_bit_pointer(&expected, 127);

  s21_decimal got = {{0}};
  int return_value = s21_negate(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test8) {
  s21_decimal src = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal expected = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  scale(&expected, 3);
  scale(&src, 3);
  invert_bit_pointer(&expected, 127);

  s21_decimal got = {{0}};
  int return_value = s21_negate(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

Suite *test_func_negate(void) {
  Suite *x;
  x = suite_create("check_s21_negate");

  TCase *s21_negate_case;

  s21_negate_case = tcase_create("s21_negate");
  suite_add_tcase(x, s21_negate_case);

  tcase_add_test(s21_negate_case, test1);
  tcase_add_test(s21_negate_case, test2);
  tcase_add_test(s21_negate_case, test3);
  tcase_add_test(s21_negate_case, test4);
  tcase_add_test(s21_negate_case, test5);
  tcase_add_test(s21_negate_case, test6);
  tcase_add_test(s21_negate_case, test7);
  tcase_add_test(s21_negate_case, test8);

  return x;
}

void suite_test_s21_negate(void) {
  Suite *x;
  SRunner *y;

  x = test_func_negate();
  y = srunner_create(x);
  srunner_run_all(y, CK_VERBOSE);
  srunner_free(y);
}
