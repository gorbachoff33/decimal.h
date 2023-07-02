// created by pizpotli
#include "../s21_decimal.h"

/**
 * @brief вспомогательная функция для принта децимала
 *
 * @param str строка
 * @return char* возвращает инт в виде битовой строки
 */
char *revers(char *str) {
  char *tmp = NULL;
  tmp = calloc(33, sizeof(char));
  int j = 31;
  for (int i = 0; i < 32; i++, j--) {
    tmp[j] = str[i];
  }
  return tmp;
}

/**
 * @brief принтует децимал
 *
 * @param x децимал
 */
void print(s21_decimal x) {
  char str[34] = {0};
  for (int j = 3; j >= 0; j--) {
    memset(str, 0, sizeof(char));
    for (size_t i = 0; i < 32; i++) {
      if ((x.bits[j] & (1 << i)) == 0) {
        str[i] = '0';
      } else {
        str[i] = '1';
      }
    }
    char *c = revers(str);
    printf("|%s|", c);
  }
  printf("\n");
}

void set_bit1(s21_decimal *src, int i, int bit_value) {
  if (!bit_value) src->bits[i / 32] = ~src->bits[i / 32];
  int mask = 1 << (i % 32);
  src->bits[i / 32] = src->bits[i / 32] | mask;
  if (!bit_value) src->bits[i / 32] = ~src->bits[i / 32];
}

void make_dec(s21_decimal *value, char *str) {
  int i = 0;
  int k = strlen(str);
  for (; i < 96; i++) {
    if (k == i) {
      break;
    }
    set_bit1(value, i, str[k - 1 - i] - '0');
  }
  for (; i < 96; i++) {
    set_bit1(value, i, 0);
  }
}

void clean_dec(s21_decimal *dst) {
  dst->bits[0] = 0;
  dst->bits[1] = 0;
  dst->bits[2] = 0;
  dst->bits[3] = 0;
}

int get_scale(s21_decimal *dec) {
  return (0b11111111 << 16 & dec->bits[3]) >> 16;
}

void set_bit_add(s21_decimal value, int bit) {
  value.bits[bit / 32] = value.bits[bit / 32] | (1 << bit % 32);
}

int get_bit_pointer(s21_decimal *value, int bit) {
  return !!(value->bits[bit / 32] & (1u << (bit % 32)));
}

void clear_bit_pointer(s21_decimal *value, int bit) {
  value->bits[bit / 32] &= ~(1 << (bit % 32));
}

void set_bit_pointer(s21_decimal *value, int bit) {
  value->bits[bit / 32] |= (1 << (bit % 32));
}

void invert_bit_pointer(s21_decimal *value, int bit) {
  value->bits[bit / 32] ^= (1 << (bit % 32));
}

int get_bit(s21_decimal value, int bit) {
  return !!(value.bits[bit / 32] & (1u << (bit % 32)));
}

void set_bit(s21_decimal value, int bit) {
  value.bits[bit / 32] |= (1 << (bit % 32));
}

void set_znak_minys(s21_decimal *value) { value->bits[3] ^= (1 << 31); }

/**
 * @brief умножает децимал на 10
 *
 * @param value_1 децимал, который надо умножить
 * @param value результат
 */
void mul_10(s21_decimal value_1, s21_decimal *value) {
  s21_decimal tmp = {0};
  for (int i = 0; i < 4; i++) {
    value->bits[i] = value_1.bits[i];
  }
  int x = 0;
  int y = 0;
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 4; i++) {
      if (((value->bits[i] >> 31) & 1u) == 1) {
        x = 1;
      } else {
        x = 0;
      }
      value->bits[i] = value->bits[i] << 1;
      if (y == 1) {
        value->bits[i] |= 1 << 0;
        y = 0;
      }
      y = x;
    }
    if (j == 0) {
      for (int i = 0; i < 4; i++) {
        tmp.bits[i] = value->bits[i];
      }
    }
  }
  mul_10_plus(value, tmp, value);
}

/**
 * @brief складывает два децимала
 *
 * @param value_1 децимал 1
 * @param value_2 децимал 2
 * @param result результат сложения
 */
void mul_10_plus(s21_decimal *value_1, s21_decimal value_2,
                 s21_decimal *result) {
  s21_decimal tmp = {0};
  int edinica = 0;
  for (int i = 0; i < 128; i++) {
    if ((get_bit(*value_1, i) ^ get_bit(value_2, i)) == 1) {
      if (edinica == 0) {
        set_bit_pointer(&tmp, i);
      } else {
        clear_bit_pointer(&tmp, i);
      }
    } else if (get_bit(*value_1, i) == 0) {
      if (edinica == 0) {
        clear_bit_pointer(&tmp, i);
      } else {
        set_bit_pointer(&tmp, i);
        edinica = 0;
      }
    } else if (get_bit(*value_1, i) == 1) {
      if (edinica == 0) {
        edinica = 1;
        clear_bit_pointer(&tmp, i);
      } else {
        edinica = 1;
        set_bit_pointer(&tmp, i);
      }
    }
  }
  save(result, tmp);
}

/**
 * @brief делит децимал на 10
 *
 * @param value децимал
 */
void div_10(s21_decimal *value) {
  unsigned int res = 0;
  uint64_t tmp = 0;
  int div = 10;
  for (int i = 2; i >= 0; i--) {
    tmp = res * 4294967296 + value->bits[i];
    value->bits[i] = tmp / div;
    res = tmp - div * value->bits[i];
  }
}

/**
 * @brief смотрит знак
 * @param value число
 * @return int 0 - положительный, 1 - отрицительный
 */
int check_znak(s21_decimal value) {
  int res = 0;
  if (((value.bits[3] >> 31) & 1u) == 1) {
    res = 1;
  }
  return res;
}

/**
 * @brief проверяет на отрицательную бесконечность
 * @param value входящее число
 * @return int код ошибки 0 - FALSE, 1 - TRUE
 */
int check_minus(s21_decimal value) {
  int res = FALSE;
  int scale = 0;
  scale = check_stepen(value);
  for (int i = 0; i < 3; i++) {
    if (value.bits[i] == s21_INF_MIN) {
      res = TRUE;
      break;
    }
  }
  if (scale > 28) {
    res = TRUE;
  }
  return res;
}

/**
 * @brief проверяет на положительную бесконечность
 * @param value входящее число
 * @return int код ошибки 0 - FALSE, 1 - TRUE
 */
int check_plus(s21_decimal value) {
  int res = FALSE;
  for (int i = 0; i < 3; i++) {
    if (value.bits[i] == s21_INF_MAX) {
      res = TRUE;
      break;
    }
    if (value.bits[i] == s21_NAN) {
      res = TRUE;
      break;
    }
  }
  return res;
}

/**
 * @brief проверяет степень
 * @param value входное число
 * @return int результат степени или -1 если число > 28
 */
int check_stepen(s21_decimal value) {
  int x = 0;
  for (int i = 16, j = 0; i < 24; i++, j++) {
    if (value.bits[3] & 1 << i) {
      x ^= 1 << j;
    }
  }
  return x;
}

/**
 * @brief проверяет на ноль
 * @param value входящее число
 * @return int код ошибки 0 - FALSE, 1 - TRUE
 */
int check_zero(s21_decimal value) {
  int res = FALSE;
  if (value.bits[0] == 0 && value.bits[1] == 0 && value.bits[2] == 0) {
    res = TRUE;
  }
  return res;
}

/**
 * @brief сравнивает знаки
 * @param x 1 знак
 * @param y 2 знак
 * @return int результат 0 - все знаки '+', 1 - 1 число отрицательное, 2 - 2
 * число отрицительное, 3 - оба отрицительные
 */
int znak_result(int x, int y) {
  int res = 0;
  if (x == 1 && y == 0) {
    res = 1;
  }
  if (x == 0 && y == 1) {
    res = 2;
  }
  if (x == 1 && y == 1) {
    res = 3;
  }
  return res;
}

/**
 * @brief записывает степень в децимал
 *
 * @param tmp децимал
 * @param x степень которую надо записать
 */
void scale(s21_decimal *tmp, int x) {
  for (int i = 0, j = 16; i < 8; i++, j++) {
    if (x & 1 << i) {
      tmp->bits[3] ^= 1 << j;
    }
  }
}

/**
 * @brief  обнуляет степень
 *
 * @param tmp децимал
 */
void scale_zero(s21_decimal *tmp) {
  for (int i = 0, j = 16; i < 8; i++, j++) {
    tmp->bits[3] &= ~(1 << j);
  }
}

/**
 * @brief копирует децимал в децимал
 *
 * @param res результат
 * @param val децимал
 */
void save(s21_decimal *res, s21_decimal val) {
  for (int i = 0; i < 4; i++) {
    res->bits[i] = 0;
  }
  for (int i = 0; i < 4; i++) {
    res->bits[i] = val.bits[i];
  }
}

/**
 * @brief нормализация децималов
 *
 * @param value_1 1 децимал
 * @param value_2 2 децимал
 * @return int 0 - ОК, -1 - слишком большая разница в децималах
 */
int norm_2(s21_decimal *value_1, s21_decimal *value_2) {
  int flag = 0;
  int scale_1 = check_stepen(*value_1);
  int scale_2 = check_stepen(*value_2);
  int tmp_scale = 0;
  if (scale_1 < scale_2) {
    tmp_scale = scale_2 - scale_1;
    flag = normal(value_1, value_2, &tmp_scale);
  } else if (scale_1 > scale_2) {
    tmp_scale = scale_1 - scale_2;
    flag = normal(value_2, value_1, &tmp_scale);
  }
  return flag;
}

/**
 * @brief вторая часть нормализации
 *
 * @param value_1 1 децимал
 * @param value_2 2 децимал
 * @param scale_2 разница в степенях
 * @return int 0 - ОК, -1 - слишком большая разница в децималах
 */
int normal(s21_decimal *value_1, s21_decimal *value_2, int *scale_2) {
  int flag = 0;
  int scale_1 = check_stepen(*value_1);
  s21_decimal tmp_1 = {0};
  s21_decimal tmp_2 = {0};
  s21_decimal tmp_3 = {0};
  s21_decimal tmp_4 = {0};
  s21_decimal tmp_mod = {0};
  tmp_3.bits[0] = 10;
  save(&tmp_1, *value_1);
  save(&tmp_2, *value_2);
  tmp_1.bits[3] = tmp_2.bits[3] = 0;
  while (*scale_2 > 0) {
    mul_10(tmp_1, &tmp_1);
    if (tmp_1.bits[3] << 16 == 0) {
      save(value_1, tmp_1);
      *scale_2 = *scale_2 - 1;
      scale_1 += 1;
    } else {
      break;
    }
  }
  if (*scale_2 > 0) {
    while (*scale_2 > 0) {
      memset(&tmp_1, 0, sizeof(s21_decimal));
      tmp_4 = del(tmp_2, tmp_3, &tmp_1);
      if (!check_zero(tmp_1)) {
        save(value_2, tmp_1);
        save(&tmp_mod, tmp_4);
        save(&tmp_2, tmp_1);
        *scale_2 = *scale_2 - 1;
        if (*scale_2 == 0 && tmp_4.bits[0] == 5) {
          memset(&tmp_mod, 0, sizeof(s21_decimal));
          tmp_mod.bits[0] = 1;
          if (get_bit_pointer(value_2, 0) == 1) {
            mul_10_plus(value_2, tmp_mod, value_2);
          }
        }
        if (*scale_2 == 0 && tmp_4.bits[0] > 5) {
          memset(&tmp_mod, 0, sizeof(s21_decimal));
          tmp_mod.bits[0] = 1;
          if (get_bit_pointer(value_2, 0) == 0) {
            invert_bit_pointer(value_2, 0);
          } else {
            mul_10_plus(value_2, tmp_mod, value_2);
          }
        }
      } else {
        break;
        flag = -1;
      }
    }
  }
  scale_zero(value_2);
  scale_zero(value_1);
  scale(value_1, scale_1);
  scale(value_2, scale_1);
  if (*scale_2 > 0) {
    flag = -1;
  }
  return flag;
}

/**
 * @brief делит децимал на децимал
 *
 * @param value_1 1 децимал
 * @param value_2 2 децимал
 * @param result результат деления нацело
 * @return s21_decimal остаток от деления
 */
s21_decimal del(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_decimal one = {0};
  one.bits[0] = 1;
  s21_decimal tmp2 = {0};
  s21_decimal tmp = {0};

  for (int j = 3; j >= 0; j--) {
    for (int i = 31; i >= 0; i--) {
      if (((result->bits[3] >> 31) & 1u) == 1) {
        j = 0;
        break;
      }
      sdvig(&tmp);
      sdvig(result);
      if (((result->bits[3] >> 31) & 1u) == 1) {
        j = 0;
        break;
      }
      if (((value_1.bits[j] >> i) & 1u) == 1) {
        tmp.bits[0] |= 1 << 0;  // записывает бит
      }

      if ((sravnenie_less(value_2, tmp) || sravnenie_equal(value_2, tmp))) {
        memset(&tmp2, 0, sizeof(s21_decimal));
        invert(&tmp2, value_2);  // tmp2.bits[0] = ~(value_2.bits[0] << 0);//
                                 // инвертирует число
        mul_10_plus(&tmp, tmp2, &tmp2);  // вычитает
        mul_10_plus(&tmp2, one, &tmp);   // прибавляет 1
        result->bits[0] |= 1 << 0;       // записывает бит
        mul_10_plus(&tmp2, one, &tmp2);
      } else {
        save(&tmp2, tmp);  // tmp2.bits[0] = tmp.bits[0];
      }
    }
  }
  return tmp2;
}

/**
 * @brief инвертирует биты в децимале
 *
 * @param res результат инвертирования
 * @param val децимал
 */
void invert(s21_decimal *res, s21_decimal val) {
  s21_decimal tmp = {0};
  for (int i = 0; i < 4; i++) {
    tmp.bits[i] = ~(val.bits[i] << 0);
  }
  save(res, tmp);
}

/**
 * @brief делает сдвиг без потери 31 бита
 *
 * @param value децимал
 */
void sdvig(s21_decimal *value) {
  int x = 0;
  int y = 0;
  for (int i = 0; i < 4; i++) {
    if (((value->bits[i] >> 31) & 1u) == 1) {
      x = 1;
    } else {
      x = 0;
    }
    value->bits[i] = value->bits[i] << 1;
    if (y == 1) {
      value->bits[i] |= 1 << 0;
      y = 0;
    }
    y = x;
  }
}

/**
 * @brief смотрит меньше ли 1 децимал, чем второй, без учета степени
 *
 * @param value_1 1 децимал
 * @param value_2 2 децимал
 * @return int 0 - FALSE, 1 - TRUE
 */
int sravnenie_less(s21_decimal value_1, s21_decimal value_2) {
  int res = TRUE;
  int x = 0;
  int y = 0;
  for (int i = 95; i >= 0; i--) {
    if (get_bit(value_1, i) == 1) {
      x = 1;
    } else {
      x = 0;
    }
    if (get_bit(value_2, i) == 1) {
      y = 1;
    } else {
      y = 0;
    }
    if (x < y) {
      res = TRUE;
      break;
    }
    if (x > y) {
      res = FALSE;
      break;
    }
    if (i == 0) {
      res = FALSE;
    }
  }
  return res;
}

/**
 * @brief смотрит больше ли 1 децимал, чем второй, без учета степени
 *
 * @param value_1 1 децимал
 * @param value_2 2 децимал
 * @return int 0 - FALSE, 1 - TRUE
 */
int sravnenie_greater(s21_decimal value_1, s21_decimal value_2) {
  int res = TRUE;
  int x = 0;
  int y = 0;
  for (int i = 95; i >= 0; i--) {
    if (get_bit(value_1, i) == 1) {
      x = 1;
    } else {
      x = 0;
    }
    if (get_bit(value_2, i) == 1) {
      y = 1;
    } else {
      y = 0;
    }
    if (x > y) {
      res = TRUE;
      break;
    }
    if (x < y) {
      res = FALSE;
      break;
    }
    if (i == 0) {
      res = FALSE;
    }
  }
  return res;
}

/**
 * @brief сравнивает на равенство 2 децимала, без учета степени
 *
 * @param value_1 1 децимал
 * @param value_2 2 децимал
 * @return int 0 - FALSE, 1 - TRUE
 */
int sravnenie_equal(s21_decimal value_1, s21_decimal value_2) {
  int res = TRUE;
  for (int i = 95; i >= 0; i--) {
    if (get_bit(value_1, i) != get_bit(value_2, i)) {
      res = FALSE;
      break;
    }
  }
  return res;
}

void save_pointer(s21_decimal *res, s21_decimal *val) {
  for (int i = 0; i < 4; i++) {
    res->bits[i] = val->bits[i];
  }
}

int bit_left(s21_decimal *dec) {
  int res = get_bit(*dec, 95);
  s21_decimal base = *dec;
  for (int i = 95; i >= 0; i--) {
    if (i != 0) {
      set_bit(base, i);
    } else {
      set_bit_add(base, i);
    }
  }
  return res;
}

int f2i(float x) { return ((lens_t){.flt = x}).bits; }

/**
 * @brief вспомогательная функция мод, не учитывает переполнение деления
 *
 * @param value_1  делимое
 * @param value_2  делитель
 * @return s21_decimal остаток
 */
s21_decimal mod_2(s21_decimal value_1, s21_decimal value_2) {
  s21_decimal one = {0};
  one.bits[0] = 1;
  s21_decimal tmp2 = {0};
  s21_decimal tmp = {0};
  for (int j = 2; j >= 0; j--) {
    for (int i = 31; i >= 0; i--) {
      sdvig(&tmp);
      if (((value_1.bits[j] >> i) & 1u) == 1) {
        tmp.bits[0] |= 1 << 0;  // записывает бит
      }

      if ((sravnenie_less(value_2, tmp) || sravnenie_equal(value_2, tmp))) {
        memset(&tmp2, 0, sizeof(s21_decimal));
        invert(&tmp2, value_2);  // tmp2.bits[0] = ~(value_2.bits[0] << 0);//
                                 // инвертирует число
        mul_10_plus(&tmp, tmp2, &tmp2);  // вычитает
        memset(&tmp, 0, sizeof(s21_decimal));
        mul_10_plus(&tmp2, one, &tmp);  // прибавляет 1
        mul_10_plus(&tmp2, one, &tmp2);
      } else {
        save(&tmp2, tmp);  // tmp2.bits[0] = tmp.bits[0];
      }
    }
  }
  return tmp2;
}

int norm_2_add(s21_decimal *value_1, s21_decimal *value_2) {
  int flag = 0;
  int scale_1 = check_stepen(*value_1);
  int scale_2 = check_stepen(*value_2);
  int tmp_scale = 0;
  if (scale_1 < scale_2) {
    tmp_scale = scale_2 - scale_1;
    flag = normal_add(value_1, value_2, &tmp_scale);
  } else if (scale_1 > scale_2) {
    tmp_scale = scale_1 - scale_2;
    flag = normal_add(value_2, value_1, &tmp_scale);
  }
  return flag;
}

/**
 * @brief вторая часть нормализации
 *
 * @param value_1 1 децимал
 * @param value_2 2 децимал
 * @param scale_2 разница в степенях
 * @return int 0 - ОК, -1 - слишком большая разница в децималах
 */
int normal_add(s21_decimal *value_1, s21_decimal *value_2, int *scale_2) {
  int flag = 0;
  int scale_1 = check_stepen(*value_1);
  s21_decimal tmp_1 = {0};
  s21_decimal tmp_2 = {0};
  s21_decimal tmp_3 = {0};
  s21_decimal tmp_4 = {0};
  tmp_3.bits[0] = 10;
  save(&tmp_1, *value_1);
  save(&tmp_2, *value_2);
  tmp_1.bits[3] = tmp_2.bits[3] = 0;
  while (*scale_2 > 0) {
    mul_10(tmp_1, &tmp_1);
    if (tmp_1.bits[3] << 16 == 0) {
      save(value_1, tmp_1);
      *scale_2 = *scale_2 - 1;
      scale_1 += 1;
    } else {
      break;
    }
  }
  if (*scale_2 > 0) {
    while (*scale_2 > 0) {
      tmp_4 = del(tmp_2, tmp_3, &tmp_1);
      div_10(&tmp_2);
      if (check_zero(tmp_2) == FALSE) {
        save(value_2, tmp_2);
        *scale_2 = *scale_2 - 1;
      } else {
        break;
      }
    }
  }
  if (tmp_4.bits[0] > 5) {
    if ((value_2->bits[0] & (1 << 0)) == 0) {
      value_2->bits[0] ^= 1 << 1;
    } else if (((value_2->bits[0] & (1 << 0)) == 1)) {
      tmp_4.bits[0] = 1;
      mul_10_plus(value_2, tmp_4, value_2);
    }
  }
  scale_zero(value_2);
  scale_zero(value_1);
  scale(value_1, scale_1);
  scale(value_2, scale_1);
  if (*scale_2 > 0) {
    flag = -1;
  }
  return flag;
}

/**
 * @brief плюсовое деление
 *
 * @param value_1 делитель
 * @param value_2 делимое
 * @param result частное
 * @return s21_decimal остаток
 */
s21_decimal del_add(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result) {
  s21_decimal one = {0};
  one.bits[0] = 1;
  s21_decimal tmp2 = {0};
  s21_decimal tmp = {0};
  for (int j = 0; j >= 0; j--) {
    for (int i = 31; i >= 0; i--) {
      if (((result->bits[3] >> 31) & 1u) == 1) {
        j = 0;
        break;
      }
      sdvig(&tmp);
      sdvig(result);
      if (((value_1.bits[j] >> i) & 1u) == 1) {
        tmp.bits[0] |= 1 << 0;  // записывает бит
      }

      if ((sravnenie_less(value_2, tmp) || sravnenie_equal(value_2, tmp))) {
        memset(&tmp2, 0, sizeof(s21_decimal));
        invert(&tmp2, value_2);  // tmp2.bits[0] = ~(value_2.bits[0] << 0);//
                                 // инвертирует число
        mul_10_plus(&tmp, tmp2, &tmp2);  // вычитает
        mul_10_plus(&tmp2, one, &tmp);   // прибавляет 1
        result->bits[0] |= 1 << 0;       // записывает бит
        mul_10_plus(&tmp2, one, &tmp2);
      } else {
        save(&tmp2, tmp);  // tmp2.bits[0] = tmp.bits[0];
      }
    }
  }
  return tmp2;
}

/**
 * @brief
 *  Функция проверки знаков числа
 * если 1, то - +/ +
 * если 2, то + -/ +
 * если 3, то - -/ -
 * если 4, то + +/ -
 * @param value_1 вводимое децимал число 1
 * @param value_2 вводимое децимал число 2
 * @return int возврат результата
 */
int check_znak_res(s21_decimal value_1, s21_decimal value_2) {
  int val1 = check_znak(value_1);
  int val2 = check_znak(value_2);
  int res = 0;
  if (val1 == 1 && val2 == 0) {
    res = 1;
  } else if (val1 == 0 && val2 == 1) {
    res = 2;
  } else if (val1 == 1 && val2 == 1) {
    res = 3;
  } else if (val1 == 0 && val2 == 0) {
    res = 4;
  }
  return res;
}

int comparison(s21_decimal *val1, s21_decimal *val2) {
  int itog = 0;
  for (int i = 96; i >= 0; i--) {
    if (get_bit(*val1, i) > (get_bit(*val2, i))) {
      itog = 1;
      break;
    } else if ((get_bit(*val1, i)) < (get_bit(*val2, i))) {
      itog = -1;
      break;
    }
  }
  return itog;
}

int rounding(s21_decimal *tmp_val1, s21_decimal *tmp_val2,
             s21_decimal *result) {
  int scale = 0, res_flag = 0, znak = 0, last_x = 0;
  s21_decimal tmp = {0}, ten = {0};
  if (s21_is_less(*tmp_val1, *tmp_val2)) {
    znak = check_znak(*tmp_val2);
  } else {
    znak = check_znak(*tmp_val1);
  }
  last_x = check_znak_res(*tmp_val1, *tmp_val2);
  ten.bits[0] = 10;
  scale = check_stepen(*tmp_val2);
  while (scale > 1) {
    memset(&tmp, 0, sizeof(s21_decimal));
    del(*tmp_val2, ten, &tmp);
    save(tmp_val2, tmp);
  }
  if (tmp_val2->bits[2] == 0 && tmp_val2->bits[1] == 0) {
    if (tmp_val2->bits[0] > 9) {
      res_flag = 1;
    } else if (tmp_val2->bits[0] == 0) {
      save(result, *tmp_val1);
      res_flag = 0;
    } else {
      save(result, *tmp_val1);
      result->bits[3] = 0;
      if (tmp_val2->bits[0] < 5 && tmp_val2->bits[0] > 0) {
        save(result, *tmp_val1);
        res_flag = 0;
      }
      if (last_x < 3) {
        okruglenie(*tmp_val2, result);
      } else {
        okruglenie_minus(*tmp_val2, result);
      }
      if (result->bits[3] != 0) {
        res_flag = 1;
        memset(result, 0, sizeof(s21_decimal));
      } else {
        if (last_x > 2) {
          if (!check_zero(*result)) {
            if (znak == 1) {
              invert_bit_pointer(result, 127);
            }
          }
        }
      }
    }
  }
  return res_flag;
}

/**
 * @brief округление
 *
 * @param tmp_val2 децимал с остатком
 * @param result результат
 */
void okruglenie(s21_decimal tmp_val2, s21_decimal *result) {
  s21_decimal ten = {0};
  ten.bits[0] = 1;
  if (tmp_val2.bits[2] == 0 && tmp_val2.bits[1] == 0) {
    if (tmp_val2.bits[0] == 5) {
      if (get_bit_pointer(result, 0) == 1) {
        mul_10_plus(result, ten, result);
      }
    }
    if (tmp_val2.bits[0] > 5) {
      if (get_bit_pointer(result, 0) == 0) {
        invert_bit_pointer(result, 0);
      } else {
        mul_10_plus(result, ten, result);
      }
    }
  }
}

/**
 * @brief округление для вычитания
 *
 * @param tmp_val2 децимал с остатком
 * @param result результат
 */
void okruglenie_minus(s21_decimal tmp_val2, s21_decimal *result) {
  s21_decimal ten = {0}, ten1 = {0};
  ten.bits[0] = 1;
  ten1.bits[0] = 1;
  invert(&ten1, ten1);
  if (tmp_val2.bits[2] == 0 && tmp_val2.bits[1] == 0) {
    if (tmp_val2.bits[0] == 5) {
      if (get_bit_pointer(result, 0) == 1) {
        mul_10_plus(result, ten1, result);
        mul_10_plus(result, ten, result);
      }
    }
    if (tmp_val2.bits[0] > 5) {
      mul_10_plus(result, ten1, result);
      mul_10_plus(result, ten, result);
    }
  }
}
