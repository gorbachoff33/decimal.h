#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DECIMAL 79228162514264337593543950335.0F
#define MIN_DECIMAL -79228162514264337593543950335.0F
#define TRUE 1
#define FALSE 0
#define s21_INF_MIN -1.0 / 0.0
#define s21_INF_MAX 1.0 / 0.0
#define s21_NAN 0.0 / 0.0

typedef struct {
  int bits[4];
} s21_decimal;

typedef union {
  float flt;
  unsigned int bits;
} lens_t;

typedef union {
  unsigned int uns_int;
  float uns_float;
} float_b;

void okruglenie_minus(s21_decimal tmp_val2, s21_decimal *result);
void okruglenie(s21_decimal tmp_val2, s21_decimal *result);
void print(s21_decimal x);
char *revers(char *str);
void clean_dec(s21_decimal *dst);
void make_dec(s21_decimal *value, char *str);
void set_bit1(s21_decimal *src, int i, int bit_value);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

int check_plus(s21_decimal value);
int check_minus(s21_decimal value);
int check_zero(s21_decimal value);
int check_znak(s21_decimal value);
int znak_result(int x, int y);
int check_stepen(s21_decimal value);
void div_10(s21_decimal *value);
void mul_10(s21_decimal value_1, s21_decimal *value);
void mul_10_plus(s21_decimal *value_1, s21_decimal value_2,
                 s21_decimal *result);
int get_bit_pointer(s21_decimal *value, int bit);
void clear_bit_pointer(s21_decimal *value, int bit);
void set_bit_pointer(s21_decimal *value, int bit);
void invert_bit_pointer(s21_decimal *value, int bit);
int get_bit(s21_decimal value, int bit);
void set_bit(s21_decimal value, int bit);
void scale(s21_decimal *tmp, int x);
void scale_zero(s21_decimal *tmp);
void save(s21_decimal *res, s21_decimal val);
int norm_2(s21_decimal *value_1, s21_decimal *value_2);
int normal(s21_decimal *value_1, s21_decimal *value_2, int *scale);
int normal_add(s21_decimal *value_1, s21_decimal *value_2, int *scale_2);
int norm_2_add(s21_decimal *value_1, s21_decimal *value_2);
s21_decimal del(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
s21_decimal del_add(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result);
s21_decimal mod_2(s21_decimal value_1, s21_decimal value_2);
void sdvig(s21_decimal *value);
void invert(s21_decimal *res, s21_decimal val);
int sravnenie_less(s21_decimal value_1, s21_decimal value_2);
int sravnenie_greater(s21_decimal value_1, s21_decimal value_2);
int sravnenie_equal(s21_decimal value_1, s21_decimal value_2);
void save_pointer(s21_decimal *res, s21_decimal *val);
void set_znak_minys(s21_decimal *value);
int get_scale(s21_decimal *dec);
void set_bit_add(s21_decimal value, int bit);
int bit_left(s21_decimal *dec);
int f2i(float x);
int mul(s21_decimal *val_1, s21_decimal val_2, s21_decimal *result, int *step);
int comparison(s21_decimal *val1, s21_decimal *val2);
int check_znak_res(s21_decimal value_1, s21_decimal value_2);
int rounding(s21_decimal *tmp_val1, s21_decimal *tmp_val2, s21_decimal *result);

#endif  // SRC_S21_DECIMAL_H_