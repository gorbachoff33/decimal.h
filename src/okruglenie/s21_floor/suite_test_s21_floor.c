// created by pizpotli
#include "../../test.h"

START_TEST(test1) {
  s21_decimal src = {{37, 0, 0, 0}};
  scale(&src, 1);
  invert_bit_pointer(&src, 127);

  s21_decimal expected = {{4, 0, 0, 0}};
  invert_bit_pointer(&expected, 127);

  s21_decimal got = {{0}};
  int return_value = s21_floor(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test2) {
  s21_decimal src = {{37, 0, 0, 0}};
  scale(&src, 1);

  s21_decimal expected = {{3, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_floor(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test3) {
  s21_decimal src = {{567651, 0, 0, 0}};
  scale(&src, 1);
  invert_bit_pointer(&src, 127);

  s21_decimal expected = {{56766, 0, 0, 0}};
  invert_bit_pointer(&expected, 127);

  s21_decimal got = {{0}};
  int return_value = s21_floor(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test4) {
  s21_decimal src = {{567651, 0, 0, 0}};
  scale(&src, 1);

  s21_decimal expected = {{56765, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_floor(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test5) {
  s21_decimal src = {{0, 0, 0, 0}};
  scale(&src, 15);

  s21_decimal expected = {{0, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_floor(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test6) {
  s21_decimal src = {{0, 0, 0, 0}};
  scale(&src, 15);
  invert_bit_pointer(&src, 127);

  s21_decimal expected = {{0, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_floor(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test7) {
  s21_decimal src = {{1234567, 0, 0, 0}};
  scale(&src, 16);
  invert_bit_pointer(&src, 127);

  s21_decimal expected = {{1, 0, 0, 0}};
  invert_bit_pointer(&expected, 127);

  s21_decimal got = {{0}};
  int return_value = s21_floor(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test8) {
  s21_decimal src = {{1234567, 0, 0, 0}};
  scale(&src, 16);

  s21_decimal expected = {{0, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_floor(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test9) {
  s21_decimal src = {{9876543, 0, 0, 0}};
  scale(&src, 5);

  s21_decimal expected = {{98, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_floor(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test10) {
  s21_decimal src = {{9876543, 10, 0, 0}};
  scale(&src, 28);

  s21_decimal expected = {{0, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_floor(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

// START_TEST(test11) {
//   s21_decimal src = {{2113794, 286331153, 0, 0}};  // 1229782937963086082
//   scale(&src, 8);

//   s21_decimal expected = {{3707894787, 2, 0, 0}};  // 12297829379

//   s21_decimal got = {{0}};
//   int return_value = s21_floor(src, &got);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_int_eq(s21_is_equal(got, expected), 1);
// }
// END_TEST

// START_TEST(test12) {
//   s21_decimal src = {{0, 2867918171, 0, 0}};  // 12317614752049135616
//   invert_bit_pointer(&src, 127);
//   scale(&src, 2);

//   s21_decimal expected = {{3049426781, 28679181, 0, 0}};  //
//   123176147520491357 invert_bit_pointer(&expected, 127);

//   s21_decimal got = {{0}};
//   int return_value = s21_floor(src, &got);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_int_eq(s21_is_equal(got, expected), 1);
// }
// END_TEST

// START_TEST(test13) {
//   s21_decimal src = {
//       {354, 0, 10, 0}};  // 184467440737095516160 + 354 =
//       184467440737095516.514
//   scale(&src, 3);
//   invert_bit_pointer(&src, 127);

//   s21_decimal expected = {{4123168605, 42949672, 0, 0}};  //
//   184467440737095517 invert_bit_pointer(&expected, 127);

//   s21_decimal got = {{0}};
//   int return_value = s21_floor(src, &got);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_int_eq(s21_is_equal(got, expected), 1);
// }
// END_TEST

START_TEST(test14) {
  s21_decimal src = {{12345000, 0, 0, 0}};
  scale(&src, 3);
  invert_bit_pointer(&src, 127);

  s21_decimal expected = {{12345, 0, 0, 0}};
  invert_bit_pointer(&expected, 127);

  s21_decimal got = {{0}};
  int return_value = s21_floor(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test15) {
  s21_decimal src = {{12345000, 0, 0, 0}};
  scale(&src, 3);

  s21_decimal expected = {{12345, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_floor(src, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

Suite *test_func_floor(void) {
  Suite *x;
  x = suite_create("check_s21_floor");

  TCase *s21_floor_case;

  s21_floor_case = tcase_create("s21_floor");
  suite_add_tcase(x, s21_floor_case);

  tcase_add_test(s21_floor_case, test1);
  tcase_add_test(s21_floor_case, test2);
  tcase_add_test(s21_floor_case, test3);
  tcase_add_test(s21_floor_case, test4);
  tcase_add_test(s21_floor_case, test5);
  tcase_add_test(s21_floor_case, test6);
  tcase_add_test(s21_floor_case, test7);
  tcase_add_test(s21_floor_case, test8);
  tcase_add_test(s21_floor_case, test9);
  tcase_add_test(s21_floor_case, test10);
  // tcase_add_test(s21_floor_case, test11);
  // tcase_add_test(s21_floor_case, test12);
  // tcase_add_test(s21_floor_case, test13);
  tcase_add_test(s21_floor_case, test14);
  tcase_add_test(s21_floor_case, test15);

  return x;
}

void suite_test_s21_floor(void) {
  Suite *x;
  SRunner *y;

  x = test_func_floor();
  y = srunner_create(x);
  srunner_run_all(y, CK_VERBOSE);
  srunner_free(y);
}
