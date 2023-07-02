// created by pizpotli
#include "../../test.h"

START_TEST(s21_mul_test1) {
  s21_decimal value_1 = {{54235, 0, 0, 0}};

  s21_decimal value_2 = {{7426, 0, 0, 0}};

  s21_decimal expected = {{402749110, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_mul(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mul_test2) {
  s21_decimal value_1 = {{75520, 0, 0, 0}};
  invert_bit_pointer(&value_1, 127);

  s21_decimal value_2 = {{9999, 0, 0, 0}};
  invert_bit_pointer(&value_2, 127);

  s21_decimal expected = {{755124480, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_mul(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mul_test3) {
  s21_decimal value_1 = {{5874500, 0, 0, 0}};

  s21_decimal value_2 = {{75555, 0, 0, 0}};
  invert_bit_pointer(&value_2, 127);

  s21_decimal expected = {{1466216012, 103, 0, 0}};  // 443847847500
  invert_bit_pointer(&expected, 127);

  s21_decimal got = {{0}};
  int return_value = s21_mul(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mul_test4) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 5;
  dec1.bits[1] = 0;
  dec1.bits[2] = 0;
  dec1.bits[3] = 3670016;  // 20 знаков после запятой

  dec2.bits[0] = 1;
  dec2.bits[1] = 0;
  dec2.bits[2] = 0;
  dec2.bits[3] = 3670016;  // 16 знаков после запятой

  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 0;
  true_ans.bits[1] = 0;
  true_ans.bits[2] = 0;
  true_ans.bits[3] = 0;

  int status = s21_mul(dec1, dec2, &ans);
  int true_status = 2;
  ck_assert_int_eq(status, true_status);
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
}
END_TEST

START_TEST(s21_mul_test5) {
  s21_decimal value_1 = {{45, 0, 0, 0}};
  scale(&value_1, 1);

  s21_decimal value_2 = {{193, 0, 0, 0}};
  scale(&value_2, 2);

  s21_decimal expected = {{8685, 0, 0, 0}};
  scale(&expected, 3);

  s21_decimal got = {{0}};
  int return_value = s21_mul(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mul_test6) {
  s21_decimal value_1 = {{45, 0, 0, 0}};
  scale(&value_1, 1);
  invert_bit_pointer(&value_1, 127);

  s21_decimal value_2 = {{0, 0, 0, 0}};
  scale(&value_2, 2);

  s21_decimal expected = {{0, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_mul(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mul_test7) {
  s21_decimal value_1 = {{1746388992, 0, 0, 0}};
  scale(&value_1, 5);

  s21_decimal value_2 = {{1, 0, 0, 0}};
  scale(&value_2, 5);

  s21_decimal expected = {{1746388992, 0, 0, 0}};
  scale(&expected, 10);

  s21_decimal got = {{0}};
  int return_value = s21_mul(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

// START_TEST(s21_mul_test8) {
//   s21_decimal value_1 = {{8685, 65536, 0, 0}};  // 281474976719341
//   scale(&value_1, 5);
//   invert_bit_pointer(&value_1, 127);

//   s21_decimal value_2 = {{138448900, 1, 0, 0}};  // 4433416196
//   scale(&value_2, 3);

//   s21_decimal expected = {
//       {4132820916, 2416190212, 67648, 0}};  // 1247895720556249335846836
//   scale(&expected, 8);
//   invert_bit_pointer(&expected, 127);

//   s21_decimal got = {{0}};
//   int return_value = s21_mul(value_1, value_2, &got);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_int_eq(s21_is_equal(got, expected), 1);
// }
// END_TEST

START_TEST(s21_mul_test9) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  scale(&value_1, 15);

  s21_decimal value_2 = {{0, 0, 0, 0}};
  scale(&value_2, 23);
  invert_bit_pointer(&value_2, 127);

  s21_decimal expected = {{0, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_mul(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mul_test10) {
  s21_decimal value_1 = {{1234567, 0, 0, 0}};
  scale(&value_1, 15);

  s21_decimal value_2 = {{123, 0, 0, 0}};
  scale(&value_2, 15);

  s21_decimal expected = {{1518517, 0, 0, 0}};  // 151851741 scale 30
  scale(&expected, 28);

  s21_decimal got = {{0}};
  int return_value = s21_mul(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mul_test11) {
  s21_decimal value_1 = {{1234567, 0, 0, 0}};
  scale(&value_1, 15);

  s21_decimal value_2 = {{123, 0, 0, 0}};
  scale(&value_2, 15);

  s21_decimal expected = {{1518517, 0, 0, 0}};  // 151851741 scale 30
  scale(&expected, 28);

  s21_decimal got = {{0}};
  int return_value = s21_mul(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mul_test12) {
  s21_decimal value_1 = {{9876543, 0, 0, 0}};
  scale(&value_1, 13);

  s21_decimal value_2 = {{99, 0, 0, 0}};
  scale(&value_2, 17);

  s21_decimal expected = {{9777778, 0, 0, 0}};  // 977777757 scale 30
  scale(&expected, 28);

  s21_decimal got = {{0}};
  int return_value = s21_mul(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

// START_TEST(s21_mul_test13) {
//   s21_decimal value_1 = {{2147483648, 0, 0, 0}};
//   scale(&value_1, 3);

//   s21_decimal value_2 = {{2, 0, 0, 0}};
//   scale(&value_2, 3);

//   s21_decimal expected = {{0, 1, 0, 0}};
//   scale(&expected, 6);

//   s21_decimal got = {{0}};
//   int return_value = s21_mul(value_1, value_2, &got);
//   ck_assert_int_eq(return_value, 0);
//   ck_assert_int_eq(s21_is_equal(got, expected), 1);
// }
// END_TEST

START_TEST(s21_mul_test14) {
  s21_decimal value_1 = {{426, 0, 0, 0}};
  scale(&value_1, 3);

  s21_decimal value_2 = {{13, 0, 0, 0}};
  scale(&value_2, 27);

  s21_decimal expected = {{55, 0, 0, 0}};  // 5538 scale 30
  scale(&expected, 28);

  s21_decimal got = {{0}};
  int return_value = s21_mul(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mul_test15) {
  s21_decimal value_1 = {{426, 0, 0, 0}};
  scale(&value_1, 3);

  s21_decimal value_2 = {{13, 0, 0, 0}};
  scale(&value_2, 26);

  s21_decimal expected = {{554, 0, 0, 0}};  // 5538 scale 29
  scale(&expected, 28);

  s21_decimal got = {{0}};
  int return_value = s21_mul(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mul_test16) {
  s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};

  s21_decimal value_2 = {{2, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_mul(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(s21_mul_test17) {
  s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};

  s21_decimal value_2 = {{2, 0, 0, 0}};
  invert_bit_pointer(&value_2, 127);

  s21_decimal got = {{0}};
  int return_value = s21_mul(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(s21_mul_test18) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  scale(&value_1, 1);

  s21_decimal value_2 = {{1, 0, 0, 0}};
  scale(&value_2, 28);

  s21_decimal expected = {{0, 0, 0, 0}};

  s21_decimal got = {{0}};
  int return_value = s21_mul(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 2);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mul_test19) {
  s21_decimal value_1 = {{9, 0, 0, 0}};
  scale(&value_1, 1);
  s21_decimal value_2 = {{1, 0, 0, 0}};
  scale(&value_2, 28);
  s21_decimal expected = {{0, 0, 0, 0}};
  s21_decimal got = {{0}};
  int return_value = s21_mul(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 2);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mul_test20) {
  s21_decimal value_1 = {{15, 0, 0, 0}};
  scale(&value_1, 1);

  s21_decimal value_2 = {{1, 0, 0, 0}};
  scale(&value_2, 28);

  s21_decimal expected = {{2, 0, 0, 0}};
  scale(&expected, 28);

  s21_decimal got = {{0}};
  int return_value = s21_mul(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mul_test21) {
  s21_decimal value_1 = {{14, 0, 0, 0}};
  scale(&value_1, 1);

  s21_decimal value_2 = {{1, 0, 0, 0}};
  scale(&value_2, 28);

  s21_decimal expected = {{1, 0, 0, 0}};
  scale(&expected, 28);

  s21_decimal got = {{0}};
  int return_value = s21_mul(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mul_test22) {
  s21_decimal value_1 = {{16, 0, 0, 0}};
  scale(&value_1, 1);

  s21_decimal value_2 = {{1, 0, 0, 0}};
  scale(&value_2, 28);

  s21_decimal expected = {{2, 0, 0, 0}};
  scale(&expected, 28);

  s21_decimal got = {{0}};
  int return_value = s21_mul(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mul_test23) {
  s21_decimal value_1 = {{65, 0, 0, 0}};
  scale(&value_1, 1);

  s21_decimal value_2 = {{1, 0, 0, 0}};
  scale(&value_2, 28);

  s21_decimal expected = {{6, 0, 0, 0}};
  scale(&expected, 28);

  s21_decimal got = {{0}};
  int return_value = s21_mul(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

START_TEST(s21_mul_test24) {
  s21_decimal value_1 = {{6501, 0, 0, 0}};
  scale(&value_1, 3);

  s21_decimal value_2 = {{1, 0, 0, 0}};
  scale(&value_2, 28);

  s21_decimal expected = {{6, 0, 0, 0}};
  scale(&expected, 28);

  s21_decimal got = {{0}};
  int return_value = s21_mul(value_1, value_2, &got);
  ck_assert_int_eq(return_value, 0);
  ck_assert_int_eq(s21_is_equal(got, expected), 1);
}
END_TEST

Suite *test_func_mul(void) {
  Suite *x;
  x = suite_create("check_s21_mul");

  TCase *s21_mul_case;

  s21_mul_case = tcase_create("s21_mul");
  suite_add_tcase(x, s21_mul_case);

  tcase_add_test(s21_mul_case, s21_mul_test1);
  tcase_add_test(s21_mul_case, s21_mul_test2);
  tcase_add_test(s21_mul_case, s21_mul_test3);
  tcase_add_test(s21_mul_case, s21_mul_test4);
  tcase_add_test(s21_mul_case, s21_mul_test5);
  tcase_add_test(s21_mul_case, s21_mul_test6);
  tcase_add_test(s21_mul_case, s21_mul_test7);
  // tcase_add_test(s21_mul_case, s21_mul_test8);
  tcase_add_test(s21_mul_case, s21_mul_test9);
  tcase_add_test(s21_mul_case, s21_mul_test10);
  tcase_add_test(s21_mul_case, s21_mul_test11);
  tcase_add_test(s21_mul_case, s21_mul_test12);
  // tcase_add_test(s21_mul_case, s21_mul_test13);
  tcase_add_test(s21_mul_case, s21_mul_test14);
  tcase_add_test(s21_mul_case, s21_mul_test15);
  tcase_add_test(s21_mul_case, s21_mul_test16);
  tcase_add_test(s21_mul_case, s21_mul_test17);
  tcase_add_test(s21_mul_case, s21_mul_test18);
  tcase_add_test(s21_mul_case, s21_mul_test19);
  tcase_add_test(s21_mul_case, s21_mul_test20);
  tcase_add_test(s21_mul_case, s21_mul_test21);
  tcase_add_test(s21_mul_case, s21_mul_test22);
  tcase_add_test(s21_mul_case, s21_mul_test23);
  tcase_add_test(s21_mul_case, s21_mul_test24);

  return x;
}

void suite_test_s21_mul(void) {
  Suite *x;
  SRunner *y;

  x = test_func_mul();
  y = srunner_create(x);
  srunner_run_all(y, CK_VERBOSE);
  srunner_free(y);
}
