// created by pizpotli
#include "../../s21_decimal.h"

/**
 * @brief Округляет указанное Decimal число до ближайшего целого числа в сторону
 * отрицательной бесконечности
 *
 * @param value число которое надо округлить
 * @param result результат
 * @return int код ошибки 0-ok, 1-ошибка вычисления
 */
int s21_floor(s21_decimal value, s21_decimal *result) {
  int res = 0, flag = 0;
  int znak = 0, step = 0;
  znak = check_znak(value);
  step = check_stepen(value);
  s21_decimal tmp = {0}, tmp_res = {0}, tmp_mod = {0}, delim = {0}, base = {0};
  delim.bits[0] = 10;
  base.bits[0] = 1;
  if (result == NULL) {
    res = 1;
  } else if ((check_stepen(value) > 28)) {
    res = 1;
  } else {
    if (value.bits[0] == 0 && value.bits[1] == 0 && value.bits[2] == 0) {
      s21_truncate(value, result);
    } else if (check_znak(value) == 1 && znak == 1 && step > 0) {
      save(&tmp, value);
      tmp.bits[3] = 0;
      while (step > 0) {
        tmp_mod = del(tmp, delim, &tmp_res);
        if (tmp_mod.bits[0] != 0) {
          flag = 1;
        }
        save(&tmp, tmp_res);
        memset(&tmp_res, 0, sizeof(s21_decimal));
        step--;
      }
      s21_truncate(value, result);
      if (flag == 1) {
        s21_sub(*result, base, result);
      }
    } else {
      s21_truncate(value, result);
    }
  }
  return res;
}
