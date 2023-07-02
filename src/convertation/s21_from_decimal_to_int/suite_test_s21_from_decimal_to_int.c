// created by pizpotli
#include "../../test.h"

START_TEST(s21_decimal_to_int_test1) {
  int expected = 3;
  s21_decimal src = {{37, 0, 0, 0}};
  scale(&src, 1);

  int got;
  int return_value = s21_from_decimal_to_int(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_decimal_to_int_test2) {
  int expected = -56765;
  s21_decimal src = {{567651, 0, 0, 0}};
  scale(&src, 1);
  invert_bit_pointer(&src, 127);

  int got;
  int return_value = s21_from_decimal_to_int(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_decimal_to_int_test3) {
  int expected = 0;
  s21_decimal src = {{0, 0, 0, 0}};

  int got;
  int return_value = s21_from_decimal_to_int(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_decimal_to_int_test4) {
  int expected = 0;
  s21_decimal src = {{1234567, 0, 0, 0}};
  scale(&src, 14);
  int got;
  int return_value = s21_from_decimal_to_int(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_decimal_to_int_test5) {
  int expected = 9876543;
  s21_decimal src = {{9876543, 0, 0, 0}};
  scale(&src, 0);
  int got;
  int return_value = s21_from_decimal_to_int(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_decimal_to_int_test6) {
  int expected = -9876543;
  s21_decimal src = {{98765437, 0, 0, 0}};
  scale(&src, 1);
  invert_bit_pointer(&src, 127);
  int got;
  int return_value = s21_from_decimal_to_int(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_decimal_to_int_test7) {
  int expected = -9876543;
  s21_decimal src = {{98765435, 0, 0, 0}};
  scale(&src, 1);
  invert_bit_pointer(&src, 127);
  int got;
  int return_value = s21_from_decimal_to_int(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_decimal_to_int_test8) {
  int expected = -9876542;
  s21_decimal src = {{98765425, 0, 0, 0}};
  scale(&src, 1);
  invert_bit_pointer(&src, 127);
  int got;
  int return_value = s21_from_decimal_to_int(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_decimal_to_int_test9) {
  int expected = -9876542;
  s21_decimal src = {{987654251, 0, 0, 0}};
  scale(&src, 2);
  invert_bit_pointer(&src, 127);
  int got;
  int return_value = s21_from_decimal_to_int(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_decimal_to_int_test10) {
  int expected = INT_MAX;
  s21_decimal src = {{INT_MAX, 0, 0, 0}};

  int got;
  int return_value = s21_from_decimal_to_int(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(s21_decimal_to_int_test11) {
  s21_decimal src = {{1, 0, 1, 0}};

  int got;
  int return_value = s21_from_decimal_to_int(src, &got);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_decimal_to_int_test12) {
  s21_decimal src = {{UINT_MAX, 0, 0, 0}};

  int got;
  int return_value = s21_from_decimal_to_int(src, &got);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

// START_TEST(s21_decimal_to_int_test13) {
//   int expected = -42949;
//   s21_decimal src = {{UINT_MAX, 0, 0, 0}};
//   scale(&src, 5);
//   invert_bit_pointer(&src, 127);
//   int got;
//   int return_value = s21_from_decimal_to_int(src, &got);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_int_eq(got, expected);
// }
// END_TEST

// START_TEST(s21_decimal_to_int_test14) {
//   int expected = -85899;
//   s21_decimal src = {{UINT_MAX, 1, 0, 0}};
//   scale(&src, 5);
//   invert_bit_pointer(&src, 127);
//   int got;
//   int return_value = s21_from_decimal_to_int(src, &got);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_int_eq(got, expected);
// }
// END_TEST

Suite *test_func_decimal_to_int(void) {
  Suite *x;
  x = suite_create("check_s21_decimal_to_int");

  TCase *s21_decimal_to_int_case;

  s21_decimal_to_int_case = tcase_create("s21_decimal_to_int");
  suite_add_tcase(x, s21_decimal_to_int_case);

  tcase_add_test(s21_decimal_to_int_case, s21_decimal_to_int_test1);
  tcase_add_test(s21_decimal_to_int_case, s21_decimal_to_int_test2);
  tcase_add_test(s21_decimal_to_int_case, s21_decimal_to_int_test3);
  tcase_add_test(s21_decimal_to_int_case, s21_decimal_to_int_test4);
  tcase_add_test(s21_decimal_to_int_case, s21_decimal_to_int_test5);
  tcase_add_test(s21_decimal_to_int_case, s21_decimal_to_int_test6);
  tcase_add_test(s21_decimal_to_int_case, s21_decimal_to_int_test7);
  tcase_add_test(s21_decimal_to_int_case, s21_decimal_to_int_test8);
  tcase_add_test(s21_decimal_to_int_case, s21_decimal_to_int_test9);
  tcase_add_test(s21_decimal_to_int_case, s21_decimal_to_int_test10);
  tcase_add_test(s21_decimal_to_int_case, s21_decimal_to_int_test11);
  tcase_add_test(s21_decimal_to_int_case, s21_decimal_to_int_test12);
  // tcase_add_test(s21_decimal_to_int_case, s21_decimal_to_int_test13);
  // tcase_add_test(s21_decimal_to_int_case, s21_decimal_to_int_test14);

  return x;
}

void suite_test_s21_decimal_to_int(void) {
  Suite *x;
  SRunner *y;

  x = test_func_decimal_to_int();
  y = srunner_create(x);
  srunner_run_all(y, CK_VERBOSE);
  srunner_free(y);
}
