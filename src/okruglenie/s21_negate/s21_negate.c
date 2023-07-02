// created by pizpotli
#include "../../s21_decimal.h"

/**
 * @brief Возвращает результат умножения указанного Decimal на -1
 * @param value_1 число
 * @param result результат
 * @return int код ошибки 0 - ОК, 1- ошибка вычисления
 */
int s21_negate(s21_decimal value, s21_decimal *result) {
  int res = 0;
  if (result == NULL) {
    res = 1;
  } else if (check_plus(value) == 1 || check_minus(value) == 1) {
    res = 1;
  } else {
    save(result, value);
    if (!check_zero(*result)) {
      invert_bit_pointer(result, 127);
    }
  }
  return res;
}
