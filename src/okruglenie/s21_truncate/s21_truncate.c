// created by pizpotli
#include "../../s21_decimal.h"

/**
 * @brief преобразование в int
 * @param value_1 число double
 * @param result результат
 * @return int код ошибки 0 - ОК, 1- ошибка вычисления
 */
int s21_truncate(s21_decimal value, s21_decimal *result) {
  int res = 0;
  int scale = 0;
  s21_decimal tmp = {0}, ten = {0};
  ten.bits[0] = 10;
  if (result == NULL) {
    res = 1;
  } else if (check_plus(value) == 1 || check_minus(value) == 1) {
    res = 1;
  } else if (check_zero(value)) {
    memset(result, 0, sizeof(s21_decimal));
  } else {
    save(result, value);
    scale = check_stepen(value);
    result->bits[3] = 0;
    while (scale > 0) {
      memset(&tmp, 0, sizeof(s21_decimal));
      del(*result, ten, &tmp);
      save(result, tmp);
      scale -= 1;
    }
    if (check_znak(value)) {
      invert_bit_pointer(result, 127);
    }
  }
  return res;
}
