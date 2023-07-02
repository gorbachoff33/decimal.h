// created by pizpotli
#include "../../test.h"

START_TEST(s21_div_test1) {
  s21_decimal value_1 = {{402749110, 0, 0, 0}};
  int return_value = 0;
  s21_decimal value_2 = {{7426, 0, 0, 0}};
  s21_decimal expected = {{54235, 0, 0, 0}};
  s21_decimal got = {{0}};
  return_value = s21_div(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_div_test2) {
  s21_decimal value_1 = {{755124480, 0, 0, 0}};
  invert_bit_pointer(&value_1, 127);
  int return_value = 0;
  s21_decimal value_2 = {{9999, 0, 0, 0}};
  invert_bit_pointer(&value_2, 127);
  s21_decimal expected = {{75520, 0, 0, 0}};
  s21_decimal got = {{0}};
  return_value = s21_div(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_div_test3) {
  s21_decimal value_1 = {{1466216012, 103, 0, 0}};  // 443847847500
  int return_value = 0;
  s21_decimal value_2 = {{75555, 0, 0, 0}};
  invert_bit_pointer(&value_2, 127);
  s21_decimal expected = {{5874500, 0, 0, 0}};
  invert_bit_pointer(&expected, 127);
  s21_decimal got = {{0}};
  return_value = s21_div(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_div_test5) {
  s21_decimal value_1 = {{8685, 0, 0, 0}};
  scale(&value_1, 3);
  int return_value = 0;
  s21_decimal value_2 = {{193, 0, 0, 0}};
  scale(&value_2, 2);
  s21_decimal expected = {{45, 0, 0, 0}};
  scale(&expected, 1);
  s21_decimal got = {{0}};
  return_value = s21_div(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_div_test6) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  scale(&value_1, 1);
  invert_bit_pointer(&value_1, 127);
  int return_value = 0;
  s21_decimal value_2 = {{45, 0, 0, 0}};
  scale(&value_2, 2);
  s21_decimal expected = {{0, 0, 0, 0}};
  s21_decimal got = {{0}};
  return_value = s21_div(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_div_test7) {
  s21_decimal value_1 = {{1746388992, 0, 0, 0}};
  scale(&value_1, 10);
  int return_value = 0;
  s21_decimal value_2 = {{1, 0, 0, 0}};
  scale(&value_2, 5);
  s21_decimal expected = {{1746388992, 0, 0, 0}};
  scale(&expected, 5);
  s21_decimal got = {{0}};
  return_value = s21_div(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_div_test8) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 14;

  // 14/(-9) = -1.5555555555 5555555555 55555556
  // 00110010 01000011 01000001 00000100
  // 01100000 10101011 01011001 00001000
  // 11000011 10001110 00111000 11100100
  // 00000000 00011100 00000000 00000000
  s21_decimal true_ans = {{0, 0, 0, 0}};
  // 15555555555555555555555555556
  // 15555555555555555555555555555
  // 1555555555555555555555555556
  // 15555555555555555555555555550
  // 15555555555555555555555555550
  // 15555555555555555555555555551
  // 1555555555555555555555555550
  // 1555555555555555555555555551

  int status = s21_div(dec1, dec2, &ans);

  int true_status = 3;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(s21_div_test9) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  scale(&value_1, 15);
  int return_value = 0;
  s21_decimal value_2 = {{0, 0, 0, 0}};
  scale(&value_2, 23);
  invert_bit_pointer(&value_2, 127);
  s21_decimal got = {{0}};
  return_value = s21_div(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 3);
}
END_TEST

START_TEST(s21_div_test10) {
  s21_decimal value_1 = {{0, 1, 0, 0}};
  scale(&value_1, 6);
  int return_value = 0;
  s21_decimal value_2 = {{2, 0, 0, 0}};
  scale(&value_2, 3);
  s21_decimal expected = {{2147483648u, 0, 0, 0}};
  scale(&expected, 3);
  s21_decimal got = {{0}};
  return_value = s21_div(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_div_test11) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  scale(&value_1, 28);
  int return_value = 0;
  s21_decimal value_2 = {{10, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};
  s21_decimal got = {{0}};
  return_value = s21_div(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 2);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_div_test12) {
  s21_decimal value_1 = {{25, 0, 0, 0}};
  scale(&value_1, 28);
  int return_value = 0;
  s21_decimal value_2 = {{10, 0, 0, 0}};
  s21_decimal expected = {{2, 0, 0, 0}};
  scale(&expected, 28);
  s21_decimal got = {{0}};
  return_value = s21_div(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_div_test13) {
  s21_decimal value_1 = {{26, 0, 0, 0}};
  scale(&value_1, 28);
  int return_value = 0;
  s21_decimal value_2 = {{10, 0, 0, 0}};
  s21_decimal expected = {{3, 0, 0, 0}};
  scale(&expected, 28);
  s21_decimal got = {{0}};
  return_value = s21_div(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_div_test14) {
  s21_decimal value_1 = {{76, 0, 0, 0}};
  scale(&value_1, 28);
  int return_value = 0;
  s21_decimal value_2 = {{10, 0, 0, 0}};
  s21_decimal expected = {{8, 0, 0, 0}};
  scale(&expected, 28);
  s21_decimal got = {{0}};
  return_value = s21_div(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_div_test15) {
  s21_decimal value_1 = {{74, 0, 0, 0}};
  scale(&value_1, 28);
  int return_value = 0;
  s21_decimal value_2 = {{10, 0, 0, 0}};
  s21_decimal expected = {{7, 0, 0, 0}};
  scale(&expected, 28);
  s21_decimal got = {{0}};
  return_value = s21_div(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_div_test16) {
  s21_decimal value_1 = {{75, 0, 0, 0}};
  scale(&value_1, 28);
  int return_value = 0;
  s21_decimal value_2 = {{10, 0, 0, 0}};
  s21_decimal expected = {{8, 0, 0, 0}};
  scale(&expected, 28);

  s21_decimal got = {{0}};
  return_value = s21_div(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_div_test17) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  int return_value = 0;
  s21_decimal value_2 = {{1, 0, 0, 0}};
  scale(&value_2, 28);
  s21_decimal got = {{0}};
  return_value = s21_div(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

Suite *test_func_div(void) {
  Suite *x;
  x = suite_create("check_s21_div");

  TCase *s21_div_case;

  s21_div_case = tcase_create("s21_div");
  suite_add_tcase(x, s21_div_case);

  tcase_add_test(s21_div_case, s21_div_test1);
  tcase_add_test(s21_div_case, s21_div_test2);
  tcase_add_test(s21_div_case, s21_div_test3);
  tcase_add_test(s21_div_case, s21_div_test5);
  tcase_add_test(s21_div_case, s21_div_test6);
  tcase_add_test(s21_div_case, s21_div_test7);
  tcase_add_test(s21_div_case, s21_div_test8);
  tcase_add_test(s21_div_case, s21_div_test9);
  tcase_add_test(s21_div_case, s21_div_test10);
  tcase_add_test(s21_div_case, s21_div_test11);
  tcase_add_test(s21_div_case, s21_div_test12);
  tcase_add_test(s21_div_case, s21_div_test13);
  tcase_add_test(s21_div_case, s21_div_test14);
  tcase_add_test(s21_div_case, s21_div_test15);
  tcase_add_test(s21_div_case, s21_div_test16);
  tcase_add_test(s21_div_case, s21_div_test17);

  return x;
}

void suite_test_s21_div(void) {
  Suite *x;
  SRunner *y;

  x = test_func_div();
  y = srunner_create(x);
  srunner_run_all(y, CK_VERBOSE);
  srunner_free(y);
}
