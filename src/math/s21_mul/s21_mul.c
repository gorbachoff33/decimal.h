// created by pizpotli
#include "../../s21_decimal.h"

int mul_1(s21_decimal *tmp, int znak, int *step, s21_decimal *val_1,
          s21_decimal *val_2);
int mul(s21_decimal *val_1, s21_decimal val_2, s21_decimal *result, int *step);

/**
 * @brief умножение
 *
 * @param value_1 1 множитель
 * @param value_2 2 множитель
 * @param result сумма
 * @return int код ошибки 0 - ОК, 1-число слишком велико или равно
 * бесконечности, 2-число слишком мало или равно отрицательной бесконечности
 */
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  int step = 0;
  int znak = 0;
  s21_decimal val_1 = {0};
  s21_decimal val_2 = {0};
  s21_decimal tmp = {0};
  if (result == NULL) {
    res = 2;
  } else if (check_plus(value_1) == 1 || check_plus(value_2) == 1) {
    res = 1;
  } else if (check_minus(value_1) == 1 || check_minus(value_2) == 1) {
    res = 2;
  } else if (check_zero(value_1) || check_zero(value_2)) {
    save(result, val_1);
  } else {
    if (znak_result(check_znak(value_1), check_znak(value_2)) == 1 ||
        znak_result(check_znak(value_1), check_znak(value_2)) == 2) {
      znak = 1;
    }
    step = (check_stepen(value_1) + check_stepen(value_2));
    save(&val_1, value_1);
    save(&val_2, value_2);
    val_1.bits[3] = 0;
    val_2.bits[3] = 0;
    res = mul(&val_1, val_2, &tmp, &step);
    if (res == 0) {
      res = mul_1(&tmp, znak, &step, &val_1, &val_2);
    }
  }
  if (res == 0) {
    save(result, tmp);
  }
  return res;
}

/**
 * @brief умножает два децимала с заполнением bits[3], если 32 бит 1 то делит на
 * 10 число и общее число которое плюсуется и уменьшает степень
 * @param result результат
 * @param step степень
 * @return int общий флаг функции s21_mul: 0 - ОК, 1 - переполнение
 */
int mul(s21_decimal *val_1, s21_decimal val_2, s21_decimal *result, int *step) {
  int res_flag = 0;
  s21_decimal tmp = {0};
  s21_decimal res = {0};
  s21_decimal tmp_del = {{10, 0, 0, 0}};
  save(&tmp, *val_1);
  memset(val_1, 0, sizeof(s21_decimal));
  for (int i = 0; i < 95; i++) {
    if (get_bit(val_2, i) == 1) {
      mul_10_plus(val_1, tmp, val_1);
      if (get_bit_pointer(val_1, 127) == 1) {
        del(*val_1, tmp_del, &res);
        save(val_1, res);
        memset(&res, 0, sizeof(s21_decimal));
        del(tmp, tmp_del, &res);
        save(&tmp, res);
        memset(&res, 0, sizeof(s21_decimal));
        *step = *step - 1;
        if (*step < 0) {
          res_flag = 1;
          break;
        }
      }
    }
    sdvig(&tmp);
  }
  if (res_flag == 0) {
    save(result, *val_1);
  }
  return res_flag;
}

/**
 * @brief смотрит переполнение, если оно есть то делит на 10 и уменьшает степень
 *
 * @return int общий флаг для функции s21_mul: 0 - ОК, 2 - переполнение
 */
int mul_1(s21_decimal *tmp, int znak, int *step, s21_decimal *val_1,
          s21_decimal *val_2) {
  s21_decimal tmp_mod = {0}, tmp_del = {0}, tmp_tmp;
  tmp_del.bits[0] = 10;
  int res = 0;
  save(&tmp_tmp, *tmp);
  if (tmp->bits[3] != 0 && *step > 0) {
    while (tmp->bits[3] != 0 && *step > 0) {
      memset(&tmp_tmp, 0, sizeof(s21_decimal));
      tmp_mod = del(*tmp, tmp_del, &tmp_tmp);
      save(tmp, tmp_tmp);
      *step = *step - 1;
    }
  }
  if (tmp->bits[3] != 0 && *step >= 0) {
    if (znak == 1) {
      res = 2;
    } else {
      res = 1;
    }
  }
  if (*step > 28) {
    save(val_2, *tmp);
    while (*step > 28 && !(check_zero(*val_2))) {
      memset(val_1, 0, sizeof(s21_decimal));
      save(val_1, *val_2);
      memset(val_2, 0, sizeof(s21_decimal));
      tmp_mod = del(*val_1, tmp_del, val_2);
      if (!check_zero(*val_2)) {
        *step = *step - 1;
      }
      if (!check_zero(*val_2)) {
        save(tmp, *val_2);
      }
    }
    okruglenie(tmp_mod, tmp);
  }
  if (znak == 1 && !check_zero(*tmp)) {
    invert_bit_pointer(tmp, 127);
  }
  if (*step < 29) {
    scale(tmp, *step);
  } else {
    res = 2;
  }
  return res;
}