// created by pizpotli
#ifndef SRC_TEST_H_
#define SRC_TEST_H_

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_decimal.h"

void suite_test_s21_add(void);
void suite_test_s21_div(void);
void suite_test_s21_floor(void);
void suite_test_s21_decimal_to_float(void);
void suite_test_s21_decimal_to_int(void);
void suite_test_s21_float_to_decimal(void);
void suite_test_s21_int_to_decimal(void);
void suite_test_s21_equal(void);
void suite_test_s21_greater(void);
void suite_test_s21_greater_to_equal(void);
void suite_test_s21_less(void);
void suite_test_s21_less_or_equal(void);
void suite_test_s21_is_not_equal(void);
void suite_test_s21_mod(void);
void suite_test_s21_truncate(void);
void suite_test_s21_negate(void);
void suite_test_s21_mul(void);
void suite_test_s21_round(void);
void suite_test_s21_sub(void);

#endif  // SRC_TEST_H_