// created by pizpotli
#include "../../s21_decimal.h"

void div_0(s21_decimal *val_1, s21_decimal *val_2, s21_decimal *res,
           s21_decimal *res_tmp, s21_decimal *tmp2, s21_decimal *tmp,
           int *step);
s21_decimal div_1(s21_decimal *res_tmp, s21_decimal *tmp, int *step,
                  s21_decimal *res, s21_decimal val_2);
int div_per(s21_decimal *res, int *step);
void div_plus(s21_decimal *val_1, s21_decimal val_2, int *step);

/**
 * @brief деление decimal на decimal
 *
 * @param value_1 делимое
 * @param value_2 делитель
 * @param result частное
 * @return int код ошибки 0 - ОК, 1-число слишком велико или равно
 * бесконечности, 2-число слишком мало или равно отрицательной бесконечности,
 * 3-деление на 0
 */
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_decimal val_1 = {0}, val_2 = {0}, tmp = {0}, tmp2 = {0}, res = {0},
              res_tmp = {0};
  int step = 0, znak = 0, res_flag = 0;
  save(&val_1, value_1);
  save(&val_2, value_2);
  if (result == NULL) {
    res_flag = 2;
  } else if (check_plus(value_1) == 1 || check_plus(value_2) == 1) {
    res_flag = 1;
  } else if (check_minus(value_1) == 1 || check_minus(value_2) == 1) {
    res_flag = 2;
  } else if (check_zero(value_2) == 1) {
    res_flag = 3;
  } else {
    save(&val_1, value_1);
    save(&val_2, value_2);
    if (znak_result(check_znak(val_1), check_znak(val_2)) == 1 ||
        znak_result(check_znak(val_1), check_znak(val_2)) == 2) {
      znak = 1;
    }
    res_flag = norm_2(&val_1, &val_2);
    if (res_flag == -1) {
      if (check_stepen(value_1) > check_stepen(value_2)) {
        res_flag = 2;
      } else {
        res_flag = 1;
      }
    } else {
      div_0(&val_1, &val_2, &res, &res_tmp, &tmp2, &tmp, &step);
      div_per(&res, &step);
      if (znak == 1 && !check_zero(res)) {
        res.bits[3] |= 1 << 31;
      }
      scale(&res, step);
      if (res_flag == 0) {
        save(result, res);
      }
    }
  }
  return res_flag;
}

void div_0(s21_decimal *val_1, s21_decimal *val_2, s21_decimal *res,
           s21_decimal *res_tmp, s21_decimal *tmp2, s21_decimal *tmp,
           int *step) {
  s21_decimal one = {0};
  one.bits[0] = 1;
  val_1->bits[3] = 0;
  val_2->bits[3] = 0;
  div_plus(val_1, *val_2, step);
  memset(tmp, 0, sizeof(s21_decimal));
  memset(tmp2, 0, sizeof(s21_decimal));
  *tmp = del(*val_1, *val_2, res);
  save(res_tmp, *res);
  if (!check_zero(*tmp)) {
    *tmp2 = div_1(res_tmp, tmp, step, res, *val_2);
  }
  okruglenie(*tmp2, res);
  one.bits[0] = 10;
  memset(tmp, 0, sizeof(s21_decimal));
  while (check_zero(del(*res, one, tmp)) && (*step > 0) &&
         s21_is_greater_or_equal(*res, one)) {
    memset(res_tmp, 0, sizeof(s21_decimal));
    del(*res, one, res_tmp);
    save(res, *res_tmp);
    *step = *step - 1;
    memset(tmp, 0, sizeof(s21_decimal));
  }
}

/**
 * @brief записывает дробную часть
 *
 * @return s21_decimal возвращает остаток с помощью которого округляем
 */
s21_decimal div_1(s21_decimal *res_tmp, s21_decimal *tmp, int *step,
                  s21_decimal *res, s21_decimal val_2) {
  s21_decimal tmp2 = {0};
  while (res_tmp->bits[3] == 0 && !check_zero(*tmp) && *step < 28) {
    mul_10(*tmp, tmp);
    mul_10(*res_tmp, res_tmp);
    if (s21_is_greater_or_equal(*tmp, val_2)) {
      memset(&tmp2, 0, sizeof(s21_decimal));
      *tmp = del(*tmp, val_2, &tmp2);
      mul_10_plus(res_tmp, tmp2, res_tmp);
    }
    if (res_tmp->bits[3] == 0) {
      save(res, *res_tmp);
      *step = *step + 1;
    }
  }
  if (check_zero(*tmp)) {
    memset(&tmp2, 0, sizeof(s21_decimal));
  }
  return tmp2;
}

/**
 * @brief смотрит переполнение, делит на 10 и уменьшает скейл
 *
 * @param res децимал
 * @param step степень
 * @return int 0 - ок, 1 - число слишком велико
 */
int div_per(s21_decimal *res, int *step) {
  int res_flag = 0;
  s21_decimal ten = {0}, tmp = {0};
  ten.bits[0] = 10;
  if (res->bits[3] != 0 && *step > 0) {
    while (res->bits[3] != 0 && *step > 0) {
      memset(&tmp, 0, sizeof(s21_decimal));
      del(*res, ten, &tmp);
      save(res, tmp);
      *step = *step - 1;
    }
    if (res->bits[3] != 0 && *step >= 0) {
      res_flag = 1;
    }
  }
  return res_flag;
}

/**
 * @brief смотрит если делимое меньше то умножает на 10 и увеличивает общую
 * степень
 *
 * @param val_1 делимое
 * @param val_2 делитель
 * @param step степень
 */
void div_plus(s21_decimal *val_1, s21_decimal val_2, int *step) {
  if (sravnenie_less(*val_1, val_2)) {
    *step = check_stepen(*val_1);
    while ((sravnenie_less(*val_1, val_2) || sravnenie_equal(*val_1, val_2)) &&
           !check_zero(*val_1)) {
      mul_10(*val_1, val_1);
      *step = *step + 1;
    }
  }
}
