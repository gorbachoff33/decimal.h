// created by pizpotli
#include "../../test.h"

START_TEST(s21_round_test1) {
  s21_decimal src = {{37, 0, 0, 0}};
  scale(&src, 1);
  invert_bit_pointer(&src, 127);

  s21_decimal expected = {{4, 0, 0, 0}};
  invert_bit_pointer(&expected, 127);

  s21_decimal got = {{0}};
  int return_value = s21_round(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_round_test2) {
  s21_decimal src = {{37, 0, 0, 0}};
  scale(&src, 1);

  s21_decimal expected = {{4, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_round(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_round_test3) {
  s21_decimal src = {{567651, 0, 0, 0}};
  scale(&src, 1);
  invert_bit_pointer(&src, 127);

  s21_decimal expected = {{56765, 0, 0, 0}};
  invert_bit_pointer(&expected, 127);

  s21_decimal got = {{0}};
  int return_value = s21_round(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_round_test4) {
  s21_decimal src = {{567651, 0, 0, 0}};
  scale(&src, 1);

  s21_decimal expected = {{56765, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_round(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_round_test5) {
  s21_decimal src = {{0, 0, 0, 0}};
  scale(&src, 15);

  s21_decimal expected = {{0, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_round(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_round_test6) {
  s21_decimal src = {{0, 0, 0, 0}};
  scale(&src, 15);
  invert_bit_pointer(&src, 127);

  s21_decimal expected = {{0, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_round(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_round_test7) {
  s21_decimal src = {{1234567, 0, 0, 0}};
  scale(&src, 16);
  invert_bit_pointer(&src, 127);

  s21_decimal expected = {{0, 0, 0, 0}};
  invert_bit_pointer(&expected, 127);

  s21_decimal got = {{0}};
  int return_value = s21_round(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_round_test8) {
  s21_decimal src = {{1234567, 0, 0, 0}};
  scale(&src, 16);

  s21_decimal expected = {{0, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_round(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_round_test9) {
  s21_decimal src = {{9876543, 0, 0, 0}};
  scale(&src, 5);

  s21_decimal expected = {{99, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_round(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_round_test10) {
  s21_decimal src = {{9876543, 10, 0, 0}};
  scale(&src, 28);

  s21_decimal expected = {{0, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_round(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

// START_TEST(s21_round_test11) {
//   s21_decimal src = {{2113794, 286331153, 0, 0}};  // 1229782937963086082
//   scale(&src, 8);

//   s21_decimal expected = {{3707894788, 2, 0, 0}};  // 12297829380

//   s21_decimal got = {{0}};
//   int return_value = s21_round(src, &got);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_int_eq(s21_is_equal(got, expected), 1);
// }
// END_TEST

// START_TEST(s21_round_test12) {
//   s21_decimal src = {{0, 2867918171, 0, 0}};  // 12317614752049135616
//   invert_bit_pointer(&src, 127);
//   scale(&src, 2);

//   s21_decimal expected = {{3049426780, 28679181, 0, 0}};  //
//   123176147520491356 invert_bit_pointer(&expected, 127);

//   s21_decimal got = {{0}};
//   int return_value = s21_round(src, &got);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_int_eq(s21_is_equal(got, expected), 1);
// }
// END_TEST

// START_TEST(s21_round_test13) {
//   s21_decimal src = {
//       {354, 0, 10, 0}};  // 184467440737095516160 + 354 =
//       184467440737095516.514
//   scale(&src, 3);
//   invert_bit_pointer(&src, 127);

//   s21_decimal expected = {{4123168604, 42949672, 0, 0}};  //
//   184467440737095516 invert_bit_pointer(&expected, 127);

//   s21_decimal got = {{0}};
//   int return_value = s21_round(src, &got);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_int_eq(s21_is_equal(got, expected), 1);
// }
// END_TEST

START_TEST(s21_round_test14) {
  s21_decimal src = {{12345000, 0, 0, 0}};
  scale(&src, 3);
  invert_bit_pointer(&src, 127);

  s21_decimal expected = {{12345, 0, 0, 0}};
  invert_bit_pointer(&expected, 127);

  s21_decimal got = {{0}};
  int return_value = s21_round(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_round_test15) {
  s21_decimal src = {{12345000, 0, 0, 0}};
  scale(&src, 3);

  s21_decimal expected = {{12345, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_round(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_round_test16) {
  s21_decimal src = {{12344999, 0, 0, 0}};
  scale(&src, 3);

  s21_decimal expected = {{12345, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_round(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_round_test17) {
  s21_decimal src = {{12345001, 0, 0, 0}};
  scale(&src, 3);

  s21_decimal expected = {{12345, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_round(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

Suite *test_func_round(void) {
  Suite *x;
  x = suite_create("check_s21_round");

  TCase *s21_round_case;

  s21_round_case = tcase_create("s21_round");
  suite_add_tcase(x, s21_round_case);

  tcase_add_test(s21_round_case, s21_round_test1);
  tcase_add_test(s21_round_case, s21_round_test2);
  tcase_add_test(s21_round_case, s21_round_test3);
  tcase_add_test(s21_round_case, s21_round_test4);
  tcase_add_test(s21_round_case, s21_round_test5);
  tcase_add_test(s21_round_case, s21_round_test6);
  tcase_add_test(s21_round_case, s21_round_test7);
  tcase_add_test(s21_round_case, s21_round_test8);
  tcase_add_test(s21_round_case, s21_round_test9);
  tcase_add_test(s21_round_case, s21_round_test10);
  // tcase_add_test(s21_round_case, s21_round_test11);
  // tcase_add_test(s21_round_case, s21_round_test12);
  // tcase_add_test(s21_round_case, s21_round_test13);
  tcase_add_test(s21_round_case, s21_round_test14);
  tcase_add_test(s21_round_case, s21_round_test15);
  tcase_add_test(s21_round_case, s21_round_test16);
  tcase_add_test(s21_round_case, s21_round_test17);

  return x;
}

void suite_test_s21_round(void) {
  Suite *x;
  SRunner *y;

  x = test_func_round();
  y = srunner_create(x);
  srunner_run_all(y, CK_VERBOSE);
  srunner_free(y);
}
