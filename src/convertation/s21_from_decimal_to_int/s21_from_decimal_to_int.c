// created by pizpotli
#include "../../s21_decimal.h"

/**
 * @brief перевод из decimal в int
 * @param src входящее значение
 * @param dst итоговое значение decimal
 * @return int код ошибки: 0 - ОК, 1 - ошибка конвертации
 */
int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int res = 0;
  int znak = 0;
  s21_decimal tmp = {0};
  if (dst == NULL) {
    res = 1;
  } else if (check_plus(src) == 1 || check_minus(src) == 1) {
    res = 1;
  } else {
    *dst = 0;
    znak = check_znak(src);
    s21_truncate(src, &tmp);
    tmp.bits[3] = 0;
    if (tmp.bits[2] == 0 && tmp.bits[1] == 0) {
      if (tmp.bits[2] == 0 && tmp.bits[1] == 0) {
        if (get_bit(tmp, 31) == 0) {
          if (znak == 1) {
            tmp.bits[0] *= -1;
          }
          *dst = tmp.bits[0];
        } else {
          if (tmp.bits[0] == INT_MIN && znak == 1) {
            *dst = tmp.bits[0];
          } else {
            res = 1;
          }
        }
      } else {
        res = 1;
      }
    } else {
      res = 1;
    }
  }
  return res;
}
