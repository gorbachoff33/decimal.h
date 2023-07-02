// created by pizpotli
#include "../../s21_decimal.h"

/**
 * @brief проверяет меньше или = 1 число
 *
 * @param value 1 число
 * @param result 2 число
 * @return int результат true или false
 */
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int res = TRUE;
  if (s21_is_greater(value_1, value_2) == TRUE) {
    res = FALSE;
  }
  return res;
}
