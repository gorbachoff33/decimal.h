// created by pizpotli
#include "../../test.h"

START_TEST(s21_mod_test1) {
  s21_decimal value_1 = {{402749110, 0, 0, 0}};
  s21_decimal value_2 = {{7426, 0, 0, 0}};
  s21_decimal expected = {{0, 0, 0, 0}};
  s21_decimal got = {{0}};
  int return_value = s21_mod(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mod_test2) {
  s21_decimal value_1 = {{755124480, 0, 0, 0}};
  invert_bit_pointer(&value_1, 127);
  s21_decimal value_2 = {{9999, 0, 0, 0}};
  invert_bit_pointer(&value_2, 127);
  s21_decimal expected = {{0, 0, 0, 0}};
  s21_decimal got = {{0}};
  int return_value = s21_mod(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mod_test3) {
  s21_decimal value_1 = {{1466216012, 103, 0, 0}};  // 443847847500
  s21_decimal value_2 = {{75553, 0, 0, 0}};
  s21_decimal expected = {{38285, 0, 0, 0}};
  s21_decimal got = {{0}};
  int return_value = s21_mod(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mod_test4) {
  s21_decimal dec1 = {0};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};
  dec1.bits[0] = 8;
  // 164471392.8219 % -2829034.112383 = 387414.303686
  // 164471392.8219
  // 00000000 00000000 00000001 01111110
  // 11110000 10010110 11100110 00011011
  // 00000000 00000100 00000000 00000000
  // -2829034.112383
  // 00000000 00000000 00000010 10010010
  // 10101111 10010010 11000101 01111111
  // 10000000 00000110 00000000 00000000
  // 387414.303686
  // 00000000 00000000 00000000 01011010
  // 00110011 10110001 00100011 11000110
  // 00000000 00000110 00000000 00000000
  s21_decimal true_ans = {{0, 0, 0, 0}};

  int status = s21_mod(dec1, dec2, &ans);
  int true_status = 3;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(s21_mod_test5) {
  s21_decimal value_1 = {{8685, 0, 0, 0}};
  scale(&value_1, 3);
  s21_decimal value_2 = {{193, 0, 0, 0}};
  scale(&value_2, 2);
  s21_decimal expected = {{965, 0, 0, 0}};
  scale(&expected, 3);
  s21_decimal got = {{0}};
  int return_value = s21_mod(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mod_test6) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  scale(&value_1, 1);
  invert_bit_pointer(&value_1, 127);
  s21_decimal value_2 = {{45, 0, 0, 0}};
  scale(&value_2, 2);
  s21_decimal expected = {{0, 0, 0, 0}};
  s21_decimal got = {{0}};
  int return_value = s21_mod(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mod_test7) {
  s21_decimal value_1 = {{1746388992, 0, 0, 0}};
  scale(&value_1, 10);
  s21_decimal value_2 = {{1, 0, 0, 0}};
  scale(&value_2, 5);
  s21_decimal expected = {{88992, 0, 0, 0}};
  scale(&expected, 10);
  s21_decimal got = {{0}};
  int return_value = s21_mod(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mod_test9) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  scale(&value_1, 15);
  s21_decimal value_2 = {{0, 0, 0, 0}};
  scale(&value_2, 23);
  invert_bit_pointer(&value_2, 127);
  s21_decimal got = {{0}};
  int return_value = s21_mod(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 3);
}
END_TEST

START_TEST(s21_mod_test10) {
  s21_decimal value_1 = {{0, 1, 0, 0}};  // 4294967296
  scale(&value_1, 6);
  s21_decimal value_2 = {{3, 0, 0, 0}};
  scale(&value_2, 3);
  s21_decimal expected = {{2296, 0, 0, 0}};
  scale(&expected, 6);
  s21_decimal got = {{0}};
  int return_value = s21_mod(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mod_test11) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  scale(&value_1, 28);
  s21_decimal value_2 = {{10, 0, 0, 0}};
  s21_decimal expected = {{1, 0, 0, 0}};
  s21_decimal got = {0};
  scale(&expected, 28);
  int return_value = s21_mod(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mod_test12) {
  s21_decimal value_1 = {{25, 0, 0, 0}};
  scale(&value_1, 28);
  s21_decimal value_2 = {{10, 0, 0, 0}};
  s21_decimal expected = {{25, 0, 0, 0}};
  scale(&expected, 28);
  s21_decimal got = {{0}};
  int return_value = s21_mod(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mod_test13) {
  s21_decimal value_1 = {{26, 0, 0, 0}};
  scale(&value_1, 28);
  s21_decimal value_2 = {{10, 0, 0, 0}};
  s21_decimal expected = {{26, 0, 0, 0}};
  scale(&expected, 28);
  s21_decimal got = {{0}};
  int return_value = s21_mod(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mod_test14) {
  s21_decimal value_1 = {{76, 0, 0, 0}};
  scale(&value_1, 28);
  s21_decimal value_2 = {{10, 0, 0, 0}};
  s21_decimal expected = {{76, 0, 0, 0}};
  scale(&expected, 28);
  s21_decimal got = {{0}};
  int return_value = s21_mod(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mod_test15) {
  s21_decimal value_1 = {{74, 0, 0, 0}};
  scale(&value_1, 28);
  s21_decimal value_2 = {{10, 0, 0, 0}};
  s21_decimal expected = {{74, 0, 0, 0}};
  scale(&expected, 28);
  s21_decimal got = {{0}};
  int return_value = s21_mod(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mod_test16) {
  s21_decimal value_1 = {{75, 0, 0, 0}};
  scale(&value_1, 28);
  s21_decimal value_2 = {{10, 0, 0, 0}};
  s21_decimal expected = {{75, 0, 0, 0}};
  scale(&expected, 28);
  s21_decimal got = {{0}};
  int return_value = s21_mod(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mod_test17) {
  s21_decimal value_1 = {{25001, 0, 0, 0}};
  scale(&value_1, 28);
  s21_decimal value_2 = {{10000, 0, 0, 0}};
  s21_decimal expected = {{25001, 0, 0, 0}};
  scale(&expected, 28);
  s21_decimal got = {{0}};
  int return_value = s21_mod(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mod_test18) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  scale(&value_2, 27);
  s21_decimal expected = {{0, 0, 0, 0}};
  s21_decimal got = {{0}};
  int return_value = s21_mod(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mod_test19) {
  s21_decimal value_1 = {{1234, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal got = {{0}};
  int return_value = s21_mod(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 3);
}
END_TEST

Suite *test_func_mod(void) {
  Suite *x;
  x = suite_create("check_s21_mod");

  TCase *s21_mod_case;

  s21_mod_case = tcase_create("s21_mod");
  suite_add_tcase(x, s21_mod_case);

  tcase_add_test(s21_mod_case, s21_mod_test1);
  tcase_add_test(s21_mod_case, s21_mod_test2);
  tcase_add_test(s21_mod_case, s21_mod_test3);
  tcase_add_test(s21_mod_case, s21_mod_test4);
  tcase_add_test(s21_mod_case, s21_mod_test5);
  tcase_add_test(s21_mod_case, s21_mod_test6);
  tcase_add_test(s21_mod_case, s21_mod_test7);
  tcase_add_test(s21_mod_case, s21_mod_test9);
  tcase_add_test(s21_mod_case, s21_mod_test10);
  tcase_add_test(s21_mod_case, s21_mod_test11);
  tcase_add_test(s21_mod_case, s21_mod_test12);
  tcase_add_test(s21_mod_case, s21_mod_test13);
  tcase_add_test(s21_mod_case, s21_mod_test14);
  tcase_add_test(s21_mod_case, s21_mod_test15);
  tcase_add_test(s21_mod_case, s21_mod_test16);
  tcase_add_test(s21_mod_case, s21_mod_test17);
  tcase_add_test(s21_mod_case, s21_mod_test18);
  tcase_add_test(s21_mod_case, s21_mod_test19);

  return x;
}

void suite_test_s21_mod(void) {
  Suite *x;
  SRunner *y;

  x = test_func_mod();
  y = srunner_create(x);
  srunner_run_all(y, CK_VERBOSE);
  srunner_free(y);
}
