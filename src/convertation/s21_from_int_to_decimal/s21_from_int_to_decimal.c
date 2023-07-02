// created by pizpotli
#include "../../s21_decimal.h"

/**
 * @brief перевод из int в decimal
 * @param src входящее значение
 * @param dst итоговое значение decimal
 * @param tmp смотрит знак
 * @return int код ошибки: 0 - ОК, 1 - ошибка конвертации
 */
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int res = 0;
  if (dst == NULL || src == s21_INF_MAX || src == s21_INF_MIN ||
      src == s21_NAN) {
    res = 1;
  } else {
    memset(dst, 0, sizeof(int));
    int tmp = 0;
    if (src < 0) {
      if (src != INT_MIN) {
        tmp = src;
        tmp *= -1;
      }
      invert_bit_pointer(dst, 127);
    } else {
      if (src > 0) {
        tmp = src;
      }
    }
    dst->bits[0] = tmp;
  }
  return res;
}
