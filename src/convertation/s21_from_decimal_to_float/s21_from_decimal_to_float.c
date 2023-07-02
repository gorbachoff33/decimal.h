// created by pizpotli
#include "../../s21_decimal.h"

/**
 * @brief перевод из decimal в float
 * @param src входящее значение
 * @param dst итоговое значение decimal
 * @return int код ошибки: 0 - ОК, 1 - ошибка конвертации
 */
int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int res = 0;
  int scel = 0;
  short int flag_stop = 0;
  if (dst == NULL) {
    res = 1;
    flag_stop = 1;
  }
  if (check_plus(src) == 1 || check_minus(src) == 1) {
    res = 1;
  } else if (flag_stop == 0) {
    *dst = 0;
    for (int i = 0; i < 96; i++) {
      if (get_bit(src, i) == 1) {
        *dst += pow(2, i);
      }
    }
    scel = check_stepen(src);
    double tmp_dst = *dst;
    while (scel != 0) {
      tmp_dst /= 10;
      scel--;
    }
    *dst = tmp_dst;
    if (get_bit(src, 127) == 1) {
      *dst = *dst * (-1);
    }
  }
  return res;
}
