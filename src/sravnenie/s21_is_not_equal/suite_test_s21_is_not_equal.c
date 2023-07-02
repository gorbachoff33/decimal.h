// created by pizpotli
#include "../../test.h"

START_TEST(s21_is_not_equal_test1) {
  s21_decimal value_1 = {{23768, 98732, 11123, 0}};
  s21_decimal value_2 = {{23768, 98732, 11123, 0}};
  scale(&value_1, 0);
  scale(&value_2, 0);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_is_not_equal_test2) {
  s21_decimal value_1 = {{23768, 98732, 11123, 0}};
  s21_decimal value_2 = {{23768, 98732, 11123, 0}};
  scale(&value_1, 10);
  scale(&value_2, 10);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_is_not_equal_test3) {
  s21_decimal value_1 = {{23768, 98732, 11123, 0}};
  s21_decimal value_2 = {{23768, 98732, 11123, 0}};
  scale(&value_1, 7);
  scale(&value_2, 10);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_test4) {
  s21_decimal value_1 = {{23768, 98732, 11123, 0}};
  s21_decimal value_2 = {{23768, 98732, 11123, 0}};
  scale(&value_1, 10);
  scale(&value_2, 5);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_test5) {
  s21_decimal value_1 = {{23768, 98732, 11123, 0}};
  s21_decimal value_2 = {{23768, 98732, 11123, 0}};
  invert_bit_pointer(&value_1, 127);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_test6) {
  s21_decimal value_1 = {{23768, 98732, 11123, 0}};
  s21_decimal value_2 = {{23768, 98732, 11123, 0}};
  invert_bit_pointer(&value_2, 127);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_test7) {
  s21_decimal value_1 = {{23768, 98732, 11123, 0}};
  s21_decimal value_2 = {{23768, 98732, 11123, 0}};
  invert_bit_pointer(&value_1, 127);
  invert_bit_pointer(&value_2, 127);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_is_not_equal_test8) {
  s21_decimal value_1 = {{4365454, 921, 988777, 0}};
  s21_decimal value_2 = {{4365454, 911, 988777, 0}};
  scale(&value_1, 5);
  scale(&value_2, 5);
  invert_bit_pointer(&value_1, 127);
  invert_bit_pointer(&value_2, 127);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_test9) {
  s21_decimal value_1 = {{4365454, 921, 98, 0}};
  s21_decimal value_2 = {{4365454, 921, 988777, 0}};
  scale(&value_1, 10);
  scale(&value_2, 10);
  invert_bit_pointer(&value_1, 127);
  invert_bit_pointer(&value_2, 127);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_test10) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  scale(&value_1, 10);
  scale(&value_2, 10);
  invert_bit_pointer(&value_2, 127);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_is_not_equal_test11) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  invert_bit_pointer(&value_1, 127);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_is_not_equal_test12) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  scale(&value_1, 19);
  scale(&value_2, 10);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_is_not_equal_test13) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  scale(&value_1, 10);
  scale(&value_2, 17);
  invert_bit_pointer(&value_1, 127);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_is_not_equal_test14) {
  s21_decimal value_1 = {{1, 2, 3, 0}};
  s21_decimal value_2 = {{1, 2, 3, 0}};
  scale(&value_1, 10);
  scale(&value_2, 17);
  invert_bit_pointer(&value_1, 127);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_test15) {
  s21_decimal value_1 = {{1, 3, 2, 0}};
  s21_decimal value_2 = {{1, 3, 2, 0}};
  scale(&value_1, 10);
  scale(&value_2, 17);
  invert_bit_pointer(&value_2, 127);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_test16) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{1, 3, 2, 0}};
  scale(&value_1, 10);
  scale(&value_2, 7);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_test17) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{1, 3, 2, 0}};
  scale(&value_1, 1);
  scale(&value_2, 20);
  invert_bit_pointer(&value_2, 127);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_test18) {
  s21_decimal value_1 = {{143, 0, 0, 0}};
  s21_decimal value_2 = {{14300, 0, 0, 0}};
  scale(&value_1, 1);
  scale(&value_2, 3);
  invert_bit_pointer(&value_1, 127);
  invert_bit_pointer(&value_2, 127);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 0);
}
END_TEST

START_TEST(s21_is_not_equal_test19) {
  s21_decimal value_1 = {{143, 92, 873, 0}};
  s21_decimal value_2 = {{143, 92, 876, 0}};
  scale(&value_1, 5);
  scale(&value_2, 5);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_test20) {
  s21_decimal value_1 = {{143, 5, 876, 0}};
  s21_decimal value_2 = {{143, 92, 876, 0}};
  scale(&value_1, 20);
  scale(&value_2, 20);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_test21) {
  s21_decimal value_1 = {{99, 92, 876, 0}};
  s21_decimal value_2 = {{143, 92, 876, 0}};
  scale(&value_1, 20);
  scale(&value_2, 20);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_test22) {
  s21_decimal value_1 = {{143, 92, 54673, 0}};
  s21_decimal value_2 = {{143, 92, 876, 0}};
  scale(&value_1, 5);
  scale(&value_2, 5);
  invert_bit_pointer(&value_1, 127);
  invert_bit_pointer(&value_2, 127);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_test23) {
  s21_decimal value_1 = {{143, 588, 876, 0}};
  s21_decimal value_2 = {{143, 92, 876, 0}};
  scale(&value_1, 20);
  scale(&value_2, 20);
  invert_bit_pointer(&value_1, 127);
  invert_bit_pointer(&value_2, 127);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

START_TEST(s21_is_not_equal_test24) {
  s21_decimal value_1 = {{992, 92, 876, 0}};
  s21_decimal value_2 = {{143, 92, 876, 0}};
  scale(&value_1, 20);
  scale(&value_2, 20);
  invert_bit_pointer(&value_1, 127);
  invert_bit_pointer(&value_2, 127);
  ck_assert_int_eq(s21_is_not_equal(value_1, value_2), 1);
}
END_TEST

Suite *test_func_is_not_equal(void) {
  Suite *x;
  x = suite_create("check_s21_is_not_equal");

  TCase *s21_is_not_equal_case;

  s21_is_not_equal_case = tcase_create("s21_is_not_equal");
  suite_add_tcase(x, s21_is_not_equal_case);

  tcase_add_test(s21_is_not_equal_case, s21_is_not_equal_test1);
  tcase_add_test(s21_is_not_equal_case, s21_is_not_equal_test2);
  tcase_add_test(s21_is_not_equal_case, s21_is_not_equal_test3);
  tcase_add_test(s21_is_not_equal_case, s21_is_not_equal_test4);
  tcase_add_test(s21_is_not_equal_case, s21_is_not_equal_test5);
  tcase_add_test(s21_is_not_equal_case, s21_is_not_equal_test6);
  tcase_add_test(s21_is_not_equal_case, s21_is_not_equal_test7);
  tcase_add_test(s21_is_not_equal_case, s21_is_not_equal_test8);
  tcase_add_test(s21_is_not_equal_case, s21_is_not_equal_test9);
  tcase_add_test(s21_is_not_equal_case, s21_is_not_equal_test10);
  tcase_add_test(s21_is_not_equal_case, s21_is_not_equal_test11);
  tcase_add_test(s21_is_not_equal_case, s21_is_not_equal_test12);
  tcase_add_test(s21_is_not_equal_case, s21_is_not_equal_test13);
  tcase_add_test(s21_is_not_equal_case, s21_is_not_equal_test14);
  tcase_add_test(s21_is_not_equal_case, s21_is_not_equal_test15);
  tcase_add_test(s21_is_not_equal_case, s21_is_not_equal_test16);
  tcase_add_test(s21_is_not_equal_case, s21_is_not_equal_test17);
  tcase_add_test(s21_is_not_equal_case, s21_is_not_equal_test18);
  tcase_add_test(s21_is_not_equal_case, s21_is_not_equal_test19);
  tcase_add_test(s21_is_not_equal_case, s21_is_not_equal_test20);
  tcase_add_test(s21_is_not_equal_case, s21_is_not_equal_test21);
  tcase_add_test(s21_is_not_equal_case, s21_is_not_equal_test22);
  tcase_add_test(s21_is_not_equal_case, s21_is_not_equal_test23);
  tcase_add_test(s21_is_not_equal_case, s21_is_not_equal_test24);

  return x;
}

void suite_test_s21_is_not_equal(void) {
  Suite *x;
  SRunner *y;

  x = test_func_is_not_equal();
  y = srunner_create(x);
  srunner_run_all(y, CK_VERBOSE);
  srunner_free(y);
}
