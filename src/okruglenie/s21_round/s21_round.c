// created by pizpotli
#include "../../s21_decimal.h"

/**
 * @brief Округляет Decimal до ближайшего целого числа
 * @param value_1 число
 * @param result результат
 * @return int код ошибки 0 - ОК, 1- ошибка вычисления
 */
int s21_round(s21_decimal value, s21_decimal *result) {
  int res = 0;
  int step = 0;
  int znak = 0;
  s21_decimal tmp = {0};
  s21_decimal tmp2 = {0};
  s21_decimal tmp_del = {0};
  s21_decimal tmp_mod = {0};
  tmp_del.bits[0] = 10;
  if (result == NULL) {
    res = 1;
  } else if (check_plus(value) == 1 || check_minus(value) == 1) {
    res = 1;
  } else {
    step = check_stepen(value);
    znak = check_znak(value);
    save(&tmp, value);
    tmp.bits[3] = 0;
    for (; step > 0; step--) {
      memset(&tmp_mod, 0, sizeof(s21_decimal));
      memset(&tmp2, 0, sizeof(s21_decimal));
      tmp_mod = del(tmp, tmp_del, &tmp2);
      save(&tmp, tmp2);
    }
    if (tmp_mod.bits[0] == 5) {
      memset(&tmp_mod, 0, sizeof(s21_decimal));
      tmp_mod.bits[0] = 1;
      if (get_bit_pointer(&tmp, 0) == 1) {
        mul_10_plus(&tmp, tmp_mod, &tmp);
      }
    }
    if (tmp_mod.bits[0] > 5) {
      memset(&tmp_mod, 0, sizeof(s21_decimal));
      tmp_mod.bits[0] = 1;
      if (get_bit_pointer(&tmp, 0) == 0) {
        invert_bit_pointer(&tmp, 0);
      } else {
        mul_10_plus(&tmp, tmp_mod, &tmp);
      }
    }
    if (znak == 1) {
      invert_bit_pointer(&tmp, 127);
    }
    save(result, tmp);
  }
  return res;
}
