// created by pizpotli
#include "../../test.h"

START_TEST(s21_truncate_test1) {
  s21_decimal src = {{37, 0, 0, 0}};
  scale(&src, 1);
  invert_bit_pointer(&src, 127);
  s21_decimal expected = {{3, 0, 0, 0}};
  invert_bit_pointer(&expected, 127);
  s21_decimal got = {{0}};
  int return_value = s21_truncate(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(check_stepen(got), 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_truncate_test2) {
  s21_decimal src = {{567651, 0, 0, 0}};
  scale(&src, 1);
  invert_bit_pointer(&src, 127);
  s21_decimal expected = {{56765, 0, 0, 0}};
  invert_bit_pointer(&expected, 127);
  s21_decimal got = {{0}};
  int return_value = s21_truncate(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(check_stepen(got), 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_truncate_test3) {
  s21_decimal src = {{0, 0, 0, 0}};
  scale(&src, 15);
  s21_decimal expected = {{0, 0, 0, 0}};
  s21_decimal got = {{0}};
  int return_value = s21_truncate(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(check_stepen(got), 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_truncate_test4) {
  s21_decimal src = {{1234567, 0, 0, 0}};
  scale(&src, 16);
  invert_bit_pointer(&src, 127);
  s21_decimal expected = {{0, 0, 0, 0}};
  invert_bit_pointer(&expected, 127);
  s21_decimal got = {{0}};
  int return_value = s21_truncate(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(check_stepen(got), 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_truncate_test5) {
  s21_decimal src = {{9876543, 0, 0, 0}};
  scale(&src, 5);
  s21_decimal expected = {{98, 0, 0, 0}};
  s21_decimal got = {{0}};
  int return_value = s21_truncate(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(check_stepen(got), 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_truncate_test6) {
  s21_decimal src = {{9876543, 10, 0, 0}};
  scale(&src, 28);
  s21_decimal expected = {{0, 0, 0, 0}};
  s21_decimal got = {{0}};
  int return_value = s21_truncate(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(check_stepen(got), 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

// START_TEST(s21_truncate_test7) {
//   s21_decimal src = {{2113794, 286331153, 0, 0}};
//   scale(&src, 8);
//   s21_decimal expected = {{3707894787, 2, 0, 0}};
//   s21_decimal got = {{0}};
//   int return_value = s21_truncate(src, &got);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_int_eq(check_stepen(got), 0);
//   ck_assert_int_eq(s21_is_equal(got, expected), 1);
// }
// END_TEST

// START_TEST(s21_truncate_test8) {
//   s21_decimal src = {{0, 2867918171, 0, 0}};
//   invert_bit_pointer(&src, 127);
//   scale(&src, 2);
//   s21_decimal expected = {{3049426780, 28679181, 0, 0}};
//   invert_bit_pointer(&expected, 127);
//   s21_decimal got = {{0}};
//   int return_value = s21_truncate(src, &got);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_int_eq(check_stepen(got), 0);
//   ck_assert_int_eq(s21_is_equal(got, expected), 1);
// }
// END_TEST

// START_TEST(s21_truncate_test9) {
//   s21_decimal src = {{354, 0, 10, 0}};
//   scale(&src, 3);
//   invert_bit_pointer(&src, 127);
//   s21_decimal expected = {{4123168604, 42949672, 0, 0}};
//   invert_bit_pointer(&expected, 127);
//   s21_decimal got = {{0}};
//   int return_value = s21_truncate(src, &got);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_int_eq(check_stepen(got), 0);
//   ck_assert_int_eq(s21_is_equal(got, expected), 1);
// }
// END_TEST

Suite *test_func_truncate(void) {
  Suite *x;
  x = suite_create("check_s21_truncate");

  TCase *s21_truncate_case;

  s21_truncate_case = tcase_create("s21_truncate");
  suite_add_tcase(x, s21_truncate_case);

  tcase_add_test(s21_truncate_case, s21_truncate_test1);
  tcase_add_test(s21_truncate_case, s21_truncate_test2);
  tcase_add_test(s21_truncate_case, s21_truncate_test3);
  tcase_add_test(s21_truncate_case, s21_truncate_test4);
  tcase_add_test(s21_truncate_case, s21_truncate_test5);
  tcase_add_test(s21_truncate_case, s21_truncate_test6);
  // tcase_add_test(s21_truncate_case, s21_truncate_test7);
  // tcase_add_test(s21_truncate_case, s21_truncate_test8);
  // tcase_add_test(s21_truncate_case, s21_truncate_test9);

  return x;
}

void suite_test_s21_truncate(void) {
  Suite *x;
  SRunner *y;

  x = test_func_truncate();
  y = srunner_create(x);
  srunner_run_all(y, CK_VERBOSE);
  srunner_free(y);
}
