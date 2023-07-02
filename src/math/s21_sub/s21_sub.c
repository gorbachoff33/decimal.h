// created btmp_val2 pizpotli
#include "../../s21_decimal.h"

int check_sub(s21_decimal *value, int *step);
int znak_one(s21_decimal *tmp_val1, s21_decimal tmp_val2, s21_decimal *result,
             int *step);
int znak_two(s21_decimal *tmp_val1, s21_decimal tmp_val2, s21_decimal *result,
             int *step);
int znak_three(s21_decimal *tmp_val1, s21_decimal *tmp_val2,
               s21_decimal *result, int *step);
int znak_four(s21_decimal *tmp_val1, s21_decimal *tmp_val2, s21_decimal *result,
              int *step);

/**
 * @brief вычитание
 *
 * @param value_1 уменьшаемое
 * @param value_2 вычитаемое
 * @param result разность
 * @return int код ошибки 0 - ОК, 1-число слишком велико или равно
 * бесконечности, 2-число слишком мало или равно отрицательной бесконечности
 */
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res_flag = 0, res_x = 0, znak = 0, step = 0;
  if (result == NULL) {
    res_flag = 2;
  } else if (check_plus(value_1) == 1 || check_plus(value_2) == 1) {
    res_flag = 1;
  } else if (check_minus(value_1) == 1 || check_minus(value_2) == 1) {
    res_flag = 2;
  } else if (check_zero(value_1) && check_zero(value_2)) {
    res_flag = 0;
    memset(result, 0, sizeof(s21_decimal));
  } else {
    memset(result, 0, sizeof(s21_decimal));
    s21_decimal tmp_val1 = {0}, tmp_val2 = {0};
    save(&tmp_val1, value_1);
    save(&tmp_val2, value_2);
    res_flag = norm_2(&tmp_val1, &tmp_val2);
    if (res_flag == -1) {
      if (check_stepen(value_1) == 0) {
        res_flag = rounding(&tmp_val1, &tmp_val2, result);
      } else if (check_stepen(value_2) == 0) {
        res_flag = rounding(&tmp_val2, &tmp_val1, result);
      } else {
        res_flag = 2;
      }
      res_x = 1;
    }
    if (res_x == 0) {
      step = check_stepen(tmp_val1);
      znak = check_znak_res(value_1, value_2);
      tmp_val1.bits[3] = 0;
      tmp_val2.bits[3] = 0;
      if (znak == 1 && res_x == 0) {
        res_flag = znak_one(&tmp_val1, tmp_val2, result, &step);
      }
      if (znak == 2 && res_x == 0) {
        res_flag = znak_two(&tmp_val1, tmp_val2, result, &step);
      }
      if (znak == 3 && res_x == 0) {
        res_flag = znak_three(&tmp_val1, &tmp_val2, result, &step);
      }
      if (znak == 4 && res_x == 0) {
        res_flag = znak_four(&tmp_val1, &tmp_val2, result, &step);
      }
    }
  }
  return res_flag;
}

/**
 * @brief проверяет на переполнение, делит на 10 децимал и понижает степень
 *
 * @param value децимал
 * @param step степень
 * @return int общий флаг для функции s21_sub, 0 - ОК, 1 - слишком большое число
 */
int check_sub(s21_decimal *value, int *step) {
  int res = 0;
  s21_decimal tmp = {0}, ten = {0}, tmp_mod = {0};
  ten.bits[0] = 10;
  while (value->bits[3] != 0 && *step > 0) {
    memset(&tmp, 0, sizeof(s21_decimal));
    tmp_mod = del(*value, ten, &tmp);
    save(value, tmp);
    *step = *step - 1;
  }
  if (value->bits[3] != 0 && *step == 0) {
    res = 1;
  } else {
    okruglenie(tmp_mod, value);
  }
  return res;
}

/**
 * @brief складывает отрицательные числа
 *
 * @param tmp_val1 1 децимал
 * @param tmp_val2 2 децимал
 * @param result результат
 * @param step степень
 * @return int общий флаг для функции s21_sub, 0 - ОК, 1 - слишком большое число
 */
int znak_one(s21_decimal *tmp_val1, s21_decimal tmp_val2, s21_decimal *result,
             int *step) {
  int res_flag = 0;
  mul_10_plus(tmp_val1, tmp_val2, result);
  res_flag = check_sub(result, step);
  if (res_flag == 0) {
    if (!check_zero(*result)) {
      invert_bit_pointer(result, 127);
      scale(result, *step);
    }
  } else {
    memset(result, 0, sizeof(s21_decimal));
  }
  return res_flag;
}

/**
 * @brief складывает положительные числа
 *
 * @param tmp_val1 1 децимал
 * @param tmp_val2 2 децимал
 * @param result результат
 * @param step степень
 * @return int общий флаг для функции s21_sub, 0 - ОК, 1 - слишком большое число
 */
int znak_two(s21_decimal *tmp_val1, s21_decimal tmp_val2, s21_decimal *result,
             int *step) {
  int res_flag = 0;
  mul_10_plus(tmp_val1, tmp_val2, result);
  res_flag = check_sub(result, step);
  if (res_flag == 0) {
    if (!check_zero(*result)) {
      scale(result, *step);
    }
  } else {
    memset(result, 0, sizeof(s21_decimal));
  }
  return res_flag;
}

/**
 * @brief из большего вычитает меньшее и ответ отрицательный
 *
 * @param tmp_val1 1 децимал
 * @param tmp_val2 2 децимал
 * @param result результат
 * @param step степень
 * @return int общий флаг для функции s21_sub, 0 - ОК, 1 - слишком большое число
 */
int znak_three(s21_decimal *tmp_val1, s21_decimal *tmp_val2,
               s21_decimal *result, int *step) {
  s21_decimal one = {0};
  one.bits[0] = 1;
  int res_flag = 0;
  if (comparison(tmp_val1, tmp_val2) == 1) {
    invert(tmp_val2, *tmp_val2);
    mul_10_plus(tmp_val1, *tmp_val2, result);
    mul_10_plus(result, one, result);
    res_flag = check_sub(result, step);
    if (res_flag == 0) {
      if (!check_zero(*result)) {
        invert_bit_pointer(result, 127);
        scale(result, *step);
      }
    } else {
      memset(result, 0, sizeof(s21_decimal));
    }
  } else {
    invert(tmp_val1, *tmp_val1);
    mul_10_plus(tmp_val2, *tmp_val1, result);
    mul_10_plus(result, one, result);
    res_flag = check_sub(result, step);
    if (res_flag == 0) {
      if (!check_zero(*result)) {
        scale(result, *step);
      }
    } else {
      memset(result, 0, sizeof(s21_decimal));
    }
  }
  return res_flag;
}

/**
 * @brief из большего вычитает меньшее и знак положительный
 *
 * @param tmp_val1 1 децимал
 * @param tmp_val2 2 децимал
 * @param result результат
 * @param step степень
 * @return int общий флаг для функции s21_sub, 0 - ОК, 1 - слишком большое число
 */
int znak_four(s21_decimal *tmp_val1, s21_decimal *tmp_val2, s21_decimal *result,
              int *step) {
  s21_decimal one = {0};
  one.bits[0] = 1;
  int res_flag = 0;
  if (comparison(tmp_val1, tmp_val2) == 1) {
    invert(tmp_val2, *tmp_val2);
    mul_10_plus(tmp_val1, *tmp_val2, result);
    mul_10_plus(result, one, result);
    res_flag = check_sub(result, step);
    if (res_flag == 0) {
      if (!check_zero(*result)) {
        scale(result, *step);
      }
    } else {
      memset(result, 0, sizeof(s21_decimal));
    }
  } else {
    invert(tmp_val1, *tmp_val1);
    mul_10_plus(tmp_val2, *tmp_val1, result);
    mul_10_plus(result, one, result);
    res_flag = check_sub(result, step);
    if (res_flag == 0) {
      if (!check_zero(*result)) {
        invert_bit_pointer(result, 127);
        scale(result, *step);
      }
    } else {
      memset(result, 0, sizeof(s21_decimal));
    }
  }
  return res_flag;
}
