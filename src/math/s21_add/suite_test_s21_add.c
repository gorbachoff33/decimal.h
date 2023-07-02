#include "../../test.h"

START_TEST(s21_add_test1) { ck_assert_int_eq(1, 1); }
END_TEST

START_TEST(s21_add_test2) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  // invert_bit_pointer(&value_1, 127);
  s21_decimal value_2 = {{5, 0, 0, 0}};

  s21_decimal expected = {{15, 0, 0, 0}};
  // invert_bit_pointer(&expected, 127);
  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_add_test2_5) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  // invert_bit_pointer(&value_1, 127);

  s21_decimal value_2 = {{5, 0, 0, 0}};
  // invert_bit_pointer(&value_2, 127);

  s21_decimal expected = {{7, 0, 0, 0}};
  // invert_bit_pointer(&expected, 127);

  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_add_test3) {
  s21_decimal value_1 = {{2, 0, 0, 0}};

  s21_decimal value_2 = {{5, 0, 0, 0}};
  // invert_bit_pointer(&value_1,127);

  s21_decimal expected = {{7, 0, 0, 0}};
  // invert_bit_pointer(&expected,127);

  s21_decimal got = {{0}};
  // int return_value = s21_add(value_1, value_2, &got);
  // ck_assert_int_eq(return_value, 0);
  s21_add(value_1, value_2, &got);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_add_test4) {  // вычитание
  s21_decimal value_1 = {{2, 0, 0, 0}};
  invert_bit_pointer(&value_1, 127);

  s21_decimal value_2 = {{5, 0, 0, 0}};

  s21_decimal expected = {{3, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  // s21_add(value_1, value_2, &got);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_add_test5) {
  s21_decimal value_1 = {{45, 0, 0, 0}};
  scale(&value_1, 1);

  s21_decimal value_2 = {{193, 0, 0, 0}};
  scale(&value_2, 2);

  s21_decimal expected = {{643, 0, 0, 0}};
  scale(&expected, 2);

  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_add_test6) {  // нужно вычитание
  s21_decimal value_1 = {{45, 0, 0, 0}};
  scale(&value_1, 1);
  invert_bit_pointer(&value_1, 127);

  s21_decimal value_2 = {{193, 0, 0, 0}};
  scale(&value_2, 2);

  s21_decimal expected = {{257, 0, 0, 0}};
  scale(&expected, 2);
  invert_bit_pointer(&expected, 127);

  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  // s21_add(value_1, value_2, &got);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_add_test7) {
  s21_decimal value_1 = {{1746388992, 0, 0, 0}};
  scale(&value_1, 5);

  s21_decimal value_2 = {{2687027204u, 0, 0, 0}};
  scale(&value_2, 5);

  s21_decimal expected = {{138448900, 1, 0, 0}};  // 4433416196
  scale(&expected, 5);

  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_add_test8) {  // нужно вычитание
  s21_decimal value_1 = {{1746388992, 0, 0, 0}};
  scale(&value_1, 5);
  invert_bit_pointer(&value_1, 127);

  s21_decimal value_2 = {{138448900, 1, 0, 0}};  // 4433416196
  scale(&value_2, 5);

  s21_decimal expected = {{2687027204u, 0, 0, 0}};
  scale(&expected, 5);

  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  // s21_add(value_1, value_2, &got);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_add_test9) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  scale(&value_1, 15);

  s21_decimal value_2 = {{0, 0, 0, 0}};
  scale(&value_2, 23);
  invert_bit_pointer(&value_2, 127);

  s21_decimal expected = {{0, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  // s21_add(value_1, value_2, &got);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_add_test10) {
  s21_decimal value_1 = {{1234567, 0, 0, 0}};
  scale(&value_1, 16);
  invert_bit_pointer(&value_1, 127);

  s21_decimal value_2 = {{123, 0, 0, 0}};
  scale(&value_2, 16);
  invert_bit_pointer(&value_2, 127);

  s21_decimal expected = {{1234690, 0, 0, 0}};
  scale(&expected, 16);
  invert_bit_pointer(&expected, 127);

  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  // s21_add(value_1, value_2, &got);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test11) {
  s21_decimal value_1 = {{9876543, 0, 0, 0}};  // нужно вычитание
  scale(&value_1, 5);

  s21_decimal value_2 = {{99, 0, 0, 0}};
  scale(&value_2, 6);
  invert_bit_pointer(&value_2, 127);

  s21_decimal expected = {{98765331, 0, 0, 0}};
  scale(&expected, 6);

  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test12) {  // нужно вычитаниие
  s21_decimal value_1 = {{9876543, 0, 0, 0}};
  scale(&value_1, 27);

  s21_decimal value_2 = {{99, 0, 0, 0}};
  scale(&value_2, 28);
  invert_bit_pointer(&value_2, 127);

  s21_decimal expected = {{98765331, 0, 0, 0}};
  scale(&expected, 28);

  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test14) {
  s21_decimal value_1 = {{10, 380977585, 32768, 0}};
  scale(&value_1, 3);

  s21_decimal value_2 = {{15, 3959422976u, 0, 0}};
  scale(&value_2, 3);

  s21_decimal expected = {{25, 45433265, 32769, 0}};
  scale(&expected, 3);

  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test16) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  scale(&value_1, 28);

  s21_decimal value_2 = {{0, 0, 0, 0}};
  scale(&value_2, 28);
  invert_bit_pointer(&value_2, 127);

  s21_decimal expected = {{0, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test17) {  // вычитание
  s21_decimal value_1 = {
      {UINT_MAX, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950335

  s21_decimal value_2 = {{4, 0, 0, 0}};
  scale(&value_2, 1);
  invert_bit_pointer(&value_2, 127);

  s21_decimal expected = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test18) {  // вычитание
  s21_decimal value_1 = {
      {UINT_MAX, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950335

  s21_decimal value_2 = {{6, 0, 0, 0}};
  scale(&value_2, 1);
  invert_bit_pointer(&value_2, 127);

  s21_decimal expected = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};
  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test19) {  // вычитание
  s21_decimal value_1 = {
      {UINT_MAX, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950335

  s21_decimal value_2 = {{5, 0, 0, 0}};
  scale(&value_2, 1);
  invert_bit_pointer(&value_2, 127);

  s21_decimal expected = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test20) {  // вычитание
  s21_decimal value_1 = {
      {UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950334

  s21_decimal value_2 = {{5, 0, 0, 0}};
  scale(&value_2, 1);
  invert_bit_pointer(&value_2, 127);

  s21_decimal expected = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

// START_TEST(test21) {
//   s21_decimal value_1 = {
//       {UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};  //
//       79228162514264337593543950334

//   s21_decimal value_2 = {{6, 0, 0, 0}};
//   scale(&value_2, 1);
//   invert_bit_pointer(&value_2, 127);

//   s21_decimal expected = {{UINT_MAX - 2, UINT_MAX, UINT_MAX, 0}};

//   s21_decimal got = {{0}};
//   int return_value = s21_add(value_1, value_2, &got);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_int_eq(s21_is_equal(got, expected), 1);
// }
// END_TEST

START_TEST(test22) {
  s21_decimal value_1 = {
      {UINT_MAX, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950335
  s21_decimal value_2 = {{4, 0, 0, 0}};
  scale(&value_2, 1);
  s21_decimal expected = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test23) {
  s21_decimal value_1 = {
      {UINT_MAX, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950335

  s21_decimal value_2 = {{6, 0, 0, 0}};
  scale(&value_2, 1);

  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);

  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(test25) {
  s21_decimal value_1 = {
      {UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950334

  s21_decimal value_2 = {{4, 0, 0, 0}};
  scale(&value_2, 1);

  s21_decimal expected = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test26) {
  s21_decimal value_1 = {
      {UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950334

  s21_decimal value_2 = {{5, 0, 0, 0}};
  scale(&value_2, 1);

  s21_decimal expected = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test27) {
  s21_decimal value_1 = {
      {UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950334

  s21_decimal value_2 = {{6, 0, 0, 0}};
  scale(&value_2, 1);

  s21_decimal expected = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test28) {
  s21_decimal value_1 = {
      {UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950334

  s21_decimal value_2 = {{501, 0, 0, 0}};
  scale(&value_2, 3);

  s21_decimal expected = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test29) {
  s21_decimal value_2 = {
      {UINT_MAX, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950335

  s21_decimal value_1 = {{4, 0, 0, 0}};
  scale(&value_1, 1);
  invert_bit_pointer(&value_1, 127);

  s21_decimal expected = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_add(value_2, value_1, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test30) {  // вычитание
  s21_decimal value_2 = {
      {UINT_MAX, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950335

  s21_decimal value_1 = {{6, 0, 0, 0}};
  scale(&value_1, 1);
  invert_bit_pointer(&value_1, 127);

  s21_decimal expected = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_add(value_2, value_1, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test31) {  // вычет
  s21_decimal value_2 = {
      {UINT_MAX, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950335

  s21_decimal value_1 = {{5, 0, 0, 0}};
  scale(&value_1, 1);
  invert_bit_pointer(&value_1, 127);

  s21_decimal expected = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_add(value_2, value_1, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test32) {  //  вычет
  s21_decimal value_2 = {
      {UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950334

  s21_decimal value_1 = {{5, 0, 0, 0}};
  scale(&value_1, 1);
  invert_bit_pointer(&value_1, 127);

  s21_decimal expected = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_add(value_2, value_1, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test33) {
  s21_decimal value_2 = {
      {UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950334

  s21_decimal value_1 = {{6, 0, 0, 0}};
  scale(&value_1, 1);
  invert_bit_pointer(&value_1, 127);

  s21_decimal expected = {{UINT_MAX - 2, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_add(value_2, value_1, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test34) {
  s21_decimal value_2 = {
      {UINT_MAX, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950335

  s21_decimal value_1 = {{4, 0, 0, 0}};
  scale(&value_1, 1);

  s21_decimal expected = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_add(value_2, value_1, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test35) {
  s21_decimal value_2 = {
      {UINT_MAX, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950335

  s21_decimal value_1 = {{6, 0, 0, 0}};
  scale(&value_1, 1);

  s21_decimal got = {{0}};
  int return_value = s21_add(value_2, value_1, &got);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(test37) {
  s21_decimal value_2 = {
      {UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950334

  s21_decimal value_1 = {{4, 0, 0, 0}};
  scale(&value_1, 1);

  s21_decimal expected = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_add(value_2, value_1, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test38) {
  s21_decimal value_2 = {
      {UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950334

  s21_decimal value_1 = {{5, 0, 0, 0}};
  scale(&value_1, 1);

  s21_decimal expected = {{UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_add(value_2, value_1, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test39) {
  s21_decimal value_2 = {
      {UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950334

  s21_decimal value_1 = {{6, 0, 0, 0}};
  scale(&value_1, 1);

  s21_decimal expected = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_add(value_2, value_1, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test40) {
  s21_decimal value_2 = {
      {UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950334

  s21_decimal value_1 = {{501, 0, 0, 0}};
  scale(&value_1, 3);

  s21_decimal expected = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_add(value_2, value_1, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test41) {
  s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX}};
  value_1.bits[0] = s21_INF_MAX;  // - бесконечность

  s21_decimal value_2 = {{5, 0, 0, 0}};

  s21_decimal expected = {0};

  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 2);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test42) {
  s21_decimal value_1 = {
      {UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX}};  // + бесконечность
  invert_bit_pointer(&value_1, 127);
  scale(&value_1, 29);

  s21_decimal value_2 = {{5, 0, 0, 0}};

  // s21_decimal expected = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 2);
  // ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(test43) {  // новый тест
  s21_decimal value_2 = {
      {UINT_MAX - 1, UINT_MAX, UINT_MAX, 0}};  // 79228162514264337593543950334

  s21_decimal value_1 = {{501, 0, 0, 0}};
  scale(&value_1, 3);

  s21_decimal expected = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_add(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

Suite *test_func_add(void) {
  Suite *x;
  x = suite_create("check_s21_add");

  TCase *s21_add_case;

  s21_add_case = tcase_create("s21_add");
  suite_add_tcase(x, s21_add_case);

  tcase_add_test(s21_add_case, s21_add_test1);
  tcase_add_test(s21_add_case, s21_add_test2);
  tcase_add_test(s21_add_case, s21_add_test2_5);
  tcase_add_test(s21_add_case, s21_add_test3);
  tcase_add_test(s21_add_case, s21_add_test4);  // вычитание
  tcase_add_test(s21_add_case, s21_add_test5);
  tcase_add_test(s21_add_case, s21_add_test6);  // вычитание
  tcase_add_test(s21_add_case, s21_add_test7);
  tcase_add_test(s21_add_case, s21_add_test8);  // вычитание
  tcase_add_test(s21_add_case, s21_add_test9);
  tcase_add_test(s21_add_case, s21_add_test10);
  tcase_add_test(s21_add_case, test11);  // вычитание
  tcase_add_test(s21_add_case, test12);  // вычитание
  // tcase_add_test(s21_add_case, test13);
  tcase_add_test(s21_add_case, test14);
  // tcase_add_test(s21_add_case, test15);
  tcase_add_test(s21_add_case, test16);
  tcase_add_test(s21_add_case, test17);  // вычитание
  tcase_add_test(s21_add_case, test18);  // вычитание
  tcase_add_test(s21_add_case, test19);  // вычитание
  tcase_add_test(s21_add_case, test20);  // вычитание
  // tcase_add_test(s21_add_case, test21);
  tcase_add_test(s21_add_case, test22);
  tcase_add_test(s21_add_case, test23);
  // tcase_add_test(s21_add_case, test24);
  tcase_add_test(s21_add_case, test25);
  tcase_add_test(s21_add_case, test26);
  tcase_add_test(s21_add_case, test27);
  tcase_add_test(s21_add_case, test28);
  tcase_add_test(s21_add_case, test29);  // вычитание
  tcase_add_test(s21_add_case, test30);  // вычитание
  tcase_add_test(s21_add_case, test31);  // вычитание
  tcase_add_test(s21_add_case, test32);  // вычитание
  tcase_add_test(s21_add_case, test33);  // вычитание
  tcase_add_test(s21_add_case, test34);
  tcase_add_test(s21_add_case, test35);
  // tcase_add_test(s21_add_case, test36);
  tcase_add_test(s21_add_case, test37);
  tcase_add_test(s21_add_case, test38);
  tcase_add_test(s21_add_case, test39);
  tcase_add_test(s21_add_case, test40);
  tcase_add_test(s21_add_case, test41);
  tcase_add_test(s21_add_case, test42);
  tcase_add_test(s21_add_case, test43);

  return x;
}

void suite_test_s21_add(void) {
  Suite *x;
  SRunner *y;
  x = test_func_add();
  y = srunner_create(x);
  srunner_run_all(y, CK_VERBOSE);
  srunner_free(y);
}
