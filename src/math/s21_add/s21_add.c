// created by pizpotli
#include "../../s21_decimal.h"

void add_1(s21_decimal value_1_copy, s21_decimal value_2_copy,
           s21_decimal *result);
void add_2(s21_decimal *value_2_copy, s21_decimal *value_2_copy_del,
           s21_decimal *tmp_del, s21_decimal *tmp_4);

/**
 * @brief сложение
 *
 * @param value_1 1-е слогаемое
 * @param value_2 2-е слогаемое
 * @param result сумма
 * @return int код ошибки 0 - ОК, 1-число слишком велико или равно
 * бесконечности, 2-число слишком мало или равно отрицательной бесконечности
 */
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_decimal ten = {0}, tmp_4 = {0}, tmp = {0}, tmp_del = {0};
  s21_decimal result_tmp = {0}, value_1_copy = {0}, value_2_copy = {0},
              value_2_copy_del = {0};
  ten.bits[0] = 10;
  int res = 0, flag = 0, znak = 0, flag_normal = -15, step_1 = 0,
      step_result = 0, step_2 = 0;
  if (result == NULL) {
    res = 2;
  } else if (check_plus(value_1) == 1 || check_plus(value_2) == 1) {
    res = 1;
  } else if (check_minus(value_1) == 1 || check_minus(value_2) == 1) {
    res = 2;
  } else if ((check_zero(value_1) == 1) && (check_zero(value_2) == 1)) {
    save(result, result_tmp);
    res = 0;
  } else {
    memset(result, 0, sizeof(s21_decimal));
    save(&value_1_copy, value_1);
    save(&value_2_copy, value_2);
    if ((get_bit(value_1_copy, 127) ^ get_bit(value_2_copy, 127)) == 1) {
      flag = 1;
      if (get_bit(value_1_copy, 127) == 1) {
        invert_bit_pointer(&value_1_copy, 127);
        res = s21_sub(value_2_copy, value_1_copy, result);
      } else {
        invert_bit_pointer(&value_2_copy, 127);
        res = s21_sub(value_1_copy, value_2_copy, result);
      }
    }
    if (flag != 1) {
      if (get_bit(value_1, 127) == 1 && flag == 0) {
        znak = -1;  // сложение отрицательных чисел
      }
      step_1 = check_stepen(value_1_copy);
      step_result = check_stepen(value_1_copy);  // запоминаем степень
      step_2 = check_stepen(value_2_copy);
      if (step_1 != step_2) {
        flag_normal = norm_2_add(&value_1_copy, &value_2_copy);
        step_result = check_stepen(
            value_1_copy);  // перезаписываем степень после нормализации
      }
      if (flag_normal != -1) {
        if (flag == 1) {
        } else {
          add_1(value_1_copy, value_2_copy, result);
        }
        if (get_bit_pointer(result, 96) == 1) {
          if (step_result != 0) {  // проверяем 96 бит и если степень не 0 то
                                   // делить на 10 и округлить
            step_result--;
            save_pointer(&tmp, result);

            memset(result, 0, sizeof(s21_decimal));
            tmp_4 = del(tmp, ten, result);
            save(&tmp, *result);
            okruglenie(tmp_4, &tmp);

            save_pointer(result, &tmp);

          } else {
            res = 1;  // записать ошибку по переполнению
          }
        }
        scale(result, step_result);  // кладем степень в резалт
        if (znak == -1) {
          set_bit_pointer(result, 127);  // кладем минус
        }
      } else {  // если  нормализация вернула -1 для комбинации + +
        save(&value_1_copy, value_1);
        save(&value_2_copy, value_2);
        if (s21_is_greater(value_1_copy, value_2_copy) == 1 &&
            get_bit(value_1_copy, 127) == 0 &&
            get_bit(value_2_copy, 127) == 0) {
          add_2(&value_2_copy, &value_2_copy_del, &tmp_del, &tmp_4);
          save(&tmp, value_1_copy);
          res = 0;
          save(&tmp_4, tmp_del);
        }

        if (s21_is_greater(value_1_copy, value_2_copy) == 0 &&
            get_bit(value_1_copy, 127) == 0 &&
            get_bit(value_2_copy, 127) == 0) {
          add_2(&value_1_copy, &value_2_copy_del, &tmp_del, &tmp_4);
          save(&tmp, value_2_copy);
          res = 0;
          save(&tmp_4, tmp_del);
        }
        okruglenie(tmp_4, &tmp);
        if (get_bit(tmp, 96) == 0) {
          save(result, tmp);
        } else {
          res = 1;
        }
      }
    }
  }
  return res;
}

/**
 * @brief складывает 2 числа
 *
 * @param value_1_copy 1 децимал
 * @param value_2_copy 2 децимал
 * @param result результат
 */
void add_1(s21_decimal value_1_copy, s21_decimal value_2_copy,
           s21_decimal *result) {
  int edinica = 0;
  for (int i = 0; i <= 96; i++) {
    if ((get_bit(value_1_copy, i) ^ get_bit(value_2_copy, i)) ==
        1) {  // комбинация 1^0 или 0^1
      if (edinica == 0) {
        set_bit_pointer(result,
                        i);  // в res кладем 1 и ничего не запоминаем
      } else {
        clear_bit_pointer(result, i);  // кладем 0
      }
    } else if (get_bit(value_1_copy, i) == 0) {  // комбинация 0 0
      if (edinica == 0) {
        clear_bit_pointer(result, i);  // кладем 0
      } else {
        set_bit_pointer(result, i);  // в res кладем 1  из памяти
        edinica = 0;  // затираем так как все положили
      }
    } else if (get_bit(value_1_copy, i) == 1) {  // комбинация 1 1
      if (edinica == 0) {
        edinica = 1;
        clear_bit_pointer(result, i);  // кладем 0
      } else {
        edinica = 1;  // сохраняем новую единицу так как  комбинация 1 1
        set_bit_pointer(result, i);  // в res кладем 1  из памяти
      }
    }
  }
}

void add_2(s21_decimal *value_copy, s21_decimal *value_2_copy_del,
           s21_decimal *tmp_del, s21_decimal *tmp_4) {
  s21_decimal ten = {{10, 0, 0, 0}};
  while (check_stepen(*value_copy) > 0) {
    int d = check_stepen(*value_copy);
    *tmp_4 = del_add(*value_copy, ten, value_2_copy_del);
    mul_10_plus(tmp_del, *tmp_4, tmp_del);
    save(value_copy, *value_2_copy_del);
    d--;
    scale(value_copy, d);
  }
}
