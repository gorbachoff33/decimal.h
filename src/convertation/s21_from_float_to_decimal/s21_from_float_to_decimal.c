#include "../../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int res = 0;
  if (dst == NULL) {
    res = 1;
  } else if (src > MAX_DECIMAL || src < MIN_DECIMAL) {
    res = 1;
  } else if (isinf(src) || isnan(src)) {
    res = 1;
  } else {
    memset(dst, 0, sizeof(s21_decimal));
    if (src != 0) {
      int sign = *(int *)&src >> 31;
      int exp = ((*(int *)&src & ~0x80000000) >> 23) - 127;
      double temp = (double)fabs(src);
      int cnt = 0;
      for (; cnt < 28 && (int)temp / (int)pow(2, 21) == 0; temp *= 10, cnt++) {
      }
      temp = round(temp);
      if (cnt <= 28 && (exp > -94 && exp < 96)) {
        float_b mantissa = {0};

        temp = (float)temp;
        for (; fmod(temp, 10) == 0 && cnt > 0; cnt--, temp /= 10) {
        }
        mantissa.uns_float = temp;
        exp = ((*(int *)&mantissa.uns_float & ~0x80000000) >> 23) - 127;
        dst->bits[exp / 32] |= 1 << exp % 32;
        for (int i = exp - 1, j = 22; j >= 0; i--, j--)
          if ((mantissa.uns_int & (1 << j)) != 0)
            dst->bits[i / 32] |= 1 << i % 32;
        dst->bits[3] = (sign << 31) | (cnt << 16);
      }
    }
  }
  return res;
}
