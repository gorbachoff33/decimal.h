// created by pizpotli
#include "../../s21_decimal.h"

/**
 * @brief остаток деления
 *
 * @param value_1 1 делимое
 * @param value_2 2 делитель
 * @param result остаток
 * @return int код ошибки 0 - ОК, 1-число слишком велико или равно
 * бесконечности, 2-число слишком мало или равно отрицательной бесконечности,
 * 3-деление на 0
 */
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  int scale1 = 0;
  s21_decimal val_1 = {0};
  s21_decimal val_2 = {0};
  save(&val_1, value_1);
  save(&val_2, value_2);
  if (result == NULL) {
    res = 2;
  } else if (check_plus(value_1) == 1 || check_plus(value_2) == 1) {
    res = 1;
  } else if (check_minus(value_1) == 1 || check_minus(value_2) == 1) {
    res = 2;
  } else if (check_zero(value_2) == 1) {
    res = 3;
  } else {
    memset(result, 0, sizeof(s21_decimal));
    if (get_bit(val_1, 127) == 1) {
      invert_bit_pointer(&val_1, 127);
    }
    if (get_bit(val_2, 127) == 1) {
      invert_bit_pointer(&val_2, 127);
    }
    if (s21_is_less(val_1, val_2)) {
      save(result, value_1);
    } else {
      res = norm_2(&val_1, &val_2);
      if (res == -1) {
        scale1 = check_stepen(value_2);
        *result = mod_2(val_1, val_2);
        if (!check_zero(*result)) {
          scale(result, scale1);
        }
        res = 0;
      } else {
        for (int i = 0; i < 4; i++) {
          result->bits[i] = 0;
        }
        scale1 = check_stepen(val_1);
        val_1.bits[3] = 0;
        val_2.bits[3] = 0;
        *result = mod_2(val_1, val_2);
        scale(result, scale1);
      }
    }
  }
  return res;
}
