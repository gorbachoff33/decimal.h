// created by pizpotli
#include "../../s21_decimal.h"

/**
 * @brief проверяет больше ли 1 число
 *
 * @param value 1 число
 * @param result 2 число
 * @return int результат true или false
 */
int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int res = TRUE;
  int x = 0;
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  if (!check_plus(value_1) && !check_plus(value_2) && !check_minus(value_1) &&
      !check_minus(value_2)) {
    x = znak_result(check_znak(value_1), check_znak(value_2));
    if (check_zero(value_1) && check_zero(value_2)) {
      res = FALSE;
    } else {
      if (x == 0) {
        if (sravnenie_greater(value_1, value_2) &&
            (check_stepen(value_1) < (check_stepen(value_2)))) {
          res = TRUE;
        } else {
          save(&val1, value_1);
          save(&val2, value_2);
          norm_2(&val1, &val2);
          res = sravnenie_greater(val1, val2);
        }
      }
      if (x == 1) {
        res = FALSE;
      }
      if (x == 2) {
        res = TRUE;
      }
      if (x == 3) {
        save(&val1, value_1);
        save(&val2, value_2);
        norm_2(&val1, &val2);
        res = sravnenie_greater(val2, val1);
      }
    }
  } else {
    res = FALSE;
  }
  return res;
}
