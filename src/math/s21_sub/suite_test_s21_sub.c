// created by pizpotli
#include "../../test.h"

START_TEST(s21_sub_test1) {
  s21_decimal value_1 = {{2, 0, 0, 0}};

  s21_decimal value_2 = {{5, 0, 0, 0}};
  invert_bit_pointer(&value_2, 127);

  s21_decimal expected = {{7, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test2) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  invert_bit_pointer(&value_1, 127);

  s21_decimal value_2 = {{5, 0, 0, 0}};

  s21_decimal expected = {{7, 0, 0, 0}};
  invert_bit_pointer(&expected, 127);

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test3) {
  s21_decimal value_1 = {{2, 0, 0, 0}};

  s21_decimal value_2 = {{5, 0, 0, 0}};

  s21_decimal expected = {{3, 0, 0, 0}};
  invert_bit_pointer(&expected, 127);

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test4) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  invert_bit_pointer(&value_1, 127);

  s21_decimal value_2 = {{5, 0, 0, 0}};
  invert_bit_pointer(&value_2, 127);

  s21_decimal expected = {{3, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test5) {
  s21_decimal value_1 = {{45, 0, 0, 0}};
  scale(&value_1, 1);

  s21_decimal value_2 = {{193, 0, 0, 0}};
  scale(&value_2, 2);
  invert_bit_pointer(&value_2, 127);

  s21_decimal expected = {{643, 0, 0, 0}};
  scale(&expected, 2);

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test6) {
  s21_decimal value_1 = {{45, 0, 0, 0}};
  scale(&value_1, 1);
  invert_bit_pointer(&value_1, 127);

  s21_decimal value_2 = {{193, 0, 0, 0}};
  scale(&value_2, 2);
  invert_bit_pointer(&value_2, 127);

  s21_decimal expected = {{257, 0, 0, 0}};
  scale(&expected, 2);
  invert_bit_pointer(&expected, 127);

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_1, value_2, &got);

  ck_assert_int_eq(s21_is_equal(got, expected), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_sub_test7) {
  s21_decimal test_value_1;
  s21_decimal test_value_2;
  s21_decimal res;
  s21_decimal res_comp;
  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "101011");
  make_dec(&test_value_2, "101011");
  make_dec(&res_comp, "0");
  s21_sub(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);
}
END_TEST

// START_TEST(s21_sub_test8) {
//   s21_decimal value_1 = {{1746388992, 0, 0, 0}};
//   scale(&value_1, 5);
//   invert_bit_pointer(&value_1, 127);

//   s21_decimal value_2 = {{138448900, 1, 0, 0}};  // 4433416196
//   scale(&value_2, 5);
//   invert_bit_pointer(&value_2, 127);

//   s21_decimal expected = {{2687027204, 0, 0, 0}};
//   scale(&expected, 5);

//   s21_decimal got = {{0}};
//   int return_value = s21_sub(value_1, value_2, &got);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_int_eq(s21_is_equal(got, expected), 1);
// }
// END_TEST

START_TEST(s21_sub_test9) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  scale(&value_1, 15);

  s21_decimal value_2 = {{0, 0, 0, 0}};
  scale(&value_2, 23);

  s21_decimal expected = {{0, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test10) {
  s21_decimal value_1 = {{1234567, 0, 0, 0}};
  scale(&value_1, 16);
  invert_bit_pointer(&value_1, 127);

  s21_decimal value_2 = {{123, 0, 0, 0}};
  scale(&value_2, 16);

  s21_decimal expected = {{1234690, 0, 0, 0}};
  scale(&expected, 16);
  invert_bit_pointer(&expected, 127);

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test11) {
  s21_decimal value_1 = {{9876543, 0, 0, 0}};
  scale(&value_1, 5);

  s21_decimal value_2 = {{99, 0, 0, 0}};
  scale(&value_2, 6);

  s21_decimal expected = {{98765331, 0, 0, 0}};
  scale(&expected, 6);

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test12) {
  s21_decimal value_1 = {{9876543, 0, 0, 0}};
  scale(&value_1, 27);

  s21_decimal value_2 = {{99, 0, 0, 0}};
  scale(&value_2, 28);

  s21_decimal expected = {{98765331, 0, 0, 0}};
  scale(&expected, 28);

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

// START_TEST(s21_sub_test13) {
//   s21_decimal value_1 = {{2147483648, 0, 0, 0}};
//   scale(&value_1, 3);

//   s21_decimal value_2 = {{2147483648, 0, 0, 0}};
//   scale(&value_2, 3);
//   invert_bit_pointer(&value_2, 127);

//   s21_decimal expected = {{0, 1, 0, 0}};
//   scale(&expected, 3);

//   s21_decimal got = {{0}};
//   int return_value = s21_sub(value_1, value_2, &got);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_int_eq(s21_is_equal(got, expected), 1);
// }
// END_TEST

// START_TEST(s21_sub_test14) {
//   s21_decimal value_1 = {{10, 380977585, 32768, 0}};
//   scale(&value_1, 3);

//   s21_decimal value_2 = {{15, 3959422976, 0, 0}};
//   scale(&value_2, 3);
//   invert_bit_pointer(&value_2, 127);

//   s21_decimal expected = {{25, 45433265, 32769, 0}};
//   scale(&expected, 3);

//   s21_decimal got = {{0}};
//   int return_value = s21_sub(value_1, value_2, &got);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_int_eq(s21_is_equal(got, expected), 1);
// }
// END_TEST

// START_TEST(s21_sub_test15) {
//   s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
//   scale(&value_1, 20);

//   s21_decimal value_2 = {{1, 0, 0, 0}};
//   scale(&value_2, 20);
//   invert_bit_pointer(&value_2, 127);

//   s21_decimal got = {{0}};
//   int return_value = s21_sub(value_1, value_2, &got);
//   ck_assert_int_eq(return_value, 1);
// }
// END_TEST

START_TEST(s21_sub_test16) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  scale(&value_1, 28);

  s21_decimal value_2 = {{0, 0, 0, 0}};
  scale(&value_2, 28);

  s21_decimal expected = {{0, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test17) {
  s21_decimal value_1 = {
      {UINT_MAX, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950335

  s21_decimal value_2 = {{4, 0, 0, 0}};
  scale(&value_2, 1);

  s21_decimal expected = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test18) {
  s21_decimal value_1 = {
      {UINT_MAX, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950335

  s21_decimal value_2 = {{6, 0, 0, 0}};
  scale(&value_2, 1);

  s21_decimal expected = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test19) {
  s21_decimal value_1 = {
      {UINT_MAX, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950335

  s21_decimal value_2 = {{5, 0, 0, 0}};
  scale(&value_2, 1);

  s21_decimal expected = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test20) {
  s21_decimal value_1 = {
      {UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950334

  s21_decimal value_2 = {{5, 0, 0, 0}};
  scale(&value_2, 1);

  s21_decimal expected = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test21) {
  s21_decimal value_1 = {
      {UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950334

  s21_decimal value_2 = {{6, 0, 0, 0}};
  scale(&value_2, 1);

  s21_decimal expected = {{UINT_MAX - 2, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test22) {
  s21_decimal value_1 = {
      {UINT_MAX, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950335

  s21_decimal value_2 = {{4, 0, 0, 0}};
  scale(&value_2, 1);
  invert_bit_pointer(&value_2, 127);

  s21_decimal expected = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test23) {
  s21_decimal value_1 = {
      {UINT_MAX, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950335

  s21_decimal value_2 = {{6, 0, 0, 0}};
  scale(&value_2, 1);
  invert_bit_pointer(&value_2, 127);

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_sub_test25) {
  s21_decimal value_1 = {
      {UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950334

  s21_decimal value_2 = {{4, 0, 0, 0}};
  scale(&value_2, 1);
  invert_bit_pointer(&value_2, 127);

  s21_decimal expected = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test26) {
  s21_decimal value_1 = {
      {UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950334

  s21_decimal value_2 = {{5, 0, 0, 0}};
  scale(&value_2, 1);
  invert_bit_pointer(&value_2, 127);

  s21_decimal expected = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test27) {
  s21_decimal value_1 = {
      {UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950334

  s21_decimal value_2 = {{6, 0, 0, 0}};
  scale(&value_2, 1);
  invert_bit_pointer(&value_2, 127);

  s21_decimal expected = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test28) {
  s21_decimal value_1 = {
      {UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950334

  s21_decimal value_2 = {{501, 0, 0, 0}};
  scale(&value_2, 3);
  invert_bit_pointer(&value_2, 127);

  s21_decimal expected = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test29) {
  s21_decimal value_2 = {
      {UINT_MAX, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950335

  s21_decimal value_1 = {{4, 0, 0, 0}};
  scale(&value_1, 1);

  s21_decimal expected = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_2, value_1, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test30) {
  s21_decimal value_2 = {
      {UINT_MAX, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950335

  s21_decimal value_1 = {{6, 0, 0, 0}};
  scale(&value_1, 1);

  s21_decimal expected = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_2, value_1, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test31) {
  s21_decimal value_1 = {
      {UINT_MAX, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950335

  s21_decimal value_2 = {{5, 0, 0, 0}};
  scale(&value_2, 1);

  s21_decimal expected = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_2, value_1, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test32) {
  s21_decimal value_2 = {
      {UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950334

  s21_decimal value_1 = {{5, 0, 0, 0}};
  scale(&value_1, 1);

  s21_decimal expected = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_2, value_1, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test33) {
  s21_decimal value_2 = {
      {UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950334

  s21_decimal value_1 = {{6, 0, 0, 0}};
  scale(&value_1, 1);

  s21_decimal expected = {{UINT_MAX - 2, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_2, value_1, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test34) {
  s21_decimal value_2 = {
      {UINT_MAX, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950335

  s21_decimal value_1 = {{4, 0, 0, 0}};
  scale(&value_1, 1);
  invert_bit_pointer(&value_1, 127);

  s21_decimal expected = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_2, value_1, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test35) {
  s21_decimal value_2 = {
      {UINT_MAX, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950335

  s21_decimal value_1 = {{6, 0, 0, 0}};
  scale(&value_1, 1);
  invert_bit_pointer(&value_1, 127);

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_2, value_1, &got);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_sub_test37) {
  s21_decimal value_2 = {
      {UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950334

  s21_decimal value_1 = {{4, 0, 0, 0}};
  scale(&value_1, 1);
  invert_bit_pointer(&value_1, 127);

  s21_decimal expected = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_2, value_1, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test38) {
  s21_decimal value_2 = {
      {UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950334

  s21_decimal value_1 = {{5, 0, 0, 0}};
  scale(&value_1, 1);
  invert_bit_pointer(&value_1, 127);

  s21_decimal expected = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_2, value_1, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test39) {
  s21_decimal value_2 = {
      {UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950334

  s21_decimal value_1 = {{6, 0, 0, 0}};
  scale(&value_1, 1);
  invert_bit_pointer(&value_1, 127);

  s21_decimal expected = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_2, value_1, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_sub_test40) {
  s21_decimal value_1 = {
      {UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950334

  s21_decimal value_2 = {{501, 0, 0, 0}};
  scale(&value_2, 3);
  invert_bit_pointer(&value_1, 127);

  s21_decimal expected = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_sub(value_2, value_1, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

Suite *test_func_sub(void) {
  Suite *x;
  x = suite_create("check_s21_sub");

  TCase *s21_sub_case;

  s21_sub_case = tcase_create("s21_sub");
  suite_add_tcase(x, s21_sub_case);

  tcase_add_test(s21_sub_case, s21_sub_test1);
  tcase_add_test(s21_sub_case, s21_sub_test2);
  tcase_add_test(s21_sub_case, s21_sub_test3);
  tcase_add_test(s21_sub_case, s21_sub_test4);
  tcase_add_test(s21_sub_case, s21_sub_test5);
  tcase_add_test(s21_sub_case, s21_sub_test6);
  tcase_add_test(s21_sub_case, s21_sub_test7);
  // tcase_add_test(s21_sub_case, s21_sub_test8);
  tcase_add_test(s21_sub_case, s21_sub_test9);
  tcase_add_test(s21_sub_case, s21_sub_test10);
  tcase_add_test(s21_sub_case, s21_sub_test11);
  tcase_add_test(s21_sub_case, s21_sub_test12);
  // tcase_add_test(s21_sub_case, s21_sub_test13);
  // tcase_add_test(s21_sub_case, s21_sub_test14);
  // tcase_add_test(s21_sub_case, s21_sub_test15);
  tcase_add_test(s21_sub_case, s21_sub_test16);
  tcase_add_test(s21_sub_case, s21_sub_test17);
  tcase_add_test(s21_sub_case, s21_sub_test18);
  tcase_add_test(s21_sub_case, s21_sub_test19);
  tcase_add_test(s21_sub_case, s21_sub_test20);
  tcase_add_test(s21_sub_case, s21_sub_test21);
  tcase_add_test(s21_sub_case, s21_sub_test22);
  tcase_add_test(s21_sub_case, s21_sub_test23);
  tcase_add_test(s21_sub_case, s21_sub_test25);
  tcase_add_test(s21_sub_case, s21_sub_test26);
  tcase_add_test(s21_sub_case, s21_sub_test27);
  tcase_add_test(s21_sub_case, s21_sub_test28);
  tcase_add_test(s21_sub_case, s21_sub_test29);
  tcase_add_test(s21_sub_case, s21_sub_test30);
  tcase_add_test(s21_sub_case, s21_sub_test31);
  tcase_add_test(s21_sub_case, s21_sub_test32);
  tcase_add_test(s21_sub_case, s21_sub_test33);
  tcase_add_test(s21_sub_case, s21_sub_test34);
  tcase_add_test(s21_sub_case, s21_sub_test35);
  tcase_add_test(s21_sub_case, s21_sub_test37);
  tcase_add_test(s21_sub_case, s21_sub_test38);
  tcase_add_test(s21_sub_case, s21_sub_test39);
  tcase_add_test(s21_sub_case, s21_sub_test40);

  return x;
}

void suite_test_s21_sub(void) {
  Suite *x;
  SRunner *y;

  x = test_func_sub();
  y = srunner_create(x);
  srunner_run_all(y, CK_VERBOSE);
  srunner_free(y);
}
