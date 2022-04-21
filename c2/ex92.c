#include <assert.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/num.h"

typedef unsigned float_bits;


/**
 * @brief 计算 -f，如果是 NaN，返回 f
 *
 * @param f
 * @return float_bits
 */
float_bits float_negate(float_bits f)
{
  unsigned sign = f >> 31;
  unsigned exp = f >> 23 & 0xFF;
  unsigned frac = f & 0x7FFFFF;

  if (exp == 0 && frac != 0)
  {
    return f;
  }
  else
  {
    // 可以使用异或或者~
    return ((sign ^ 1) << 31) | (exp << 23) | frac;
  }
}

int main()
{
  float f1 = 0.1;
  float f2 = 1;
  float f3 = 10000;
  assert(u2f(float_negate(f2u(f1))) == -f1);
  assert(u2f(float_negate(f2u(f2))) == -f2);
  assert(u2f(float_negate(f2u(f3))) == -f3);

  return 0;
}