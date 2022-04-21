#include <assert.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/num.h"

typedef unsigned float_bits;

/**
 * @brief 计算 2*f
 * 非规格化的数 * 2 可能会变成规格化
 * 但是不用特殊处理，因为非规格化数 exp 全是 0，左移一位最多刚好变成 1
 *
 * @param f
 * @return float_bits
 */
float_bits float_twice(float_bits f)
{
  unsigned sig = f >> 31;
  unsigned exp = f >> 23 & 0xFF;
  unsigned frac = f & 0x7FFFFF;

  int is_NAN_or_oo = (exp == 0xFF);
  if (is_NAN_or_oo)
  {
    return f;
  }

  if (exp == 0)
  {
    /* 非规格化数 */
    frac <<= 1;
  }
  else if (exp == 0xFF - 1)
  {
    /* 变成无穷 */
    exp = 0xFF;
    frac = 0;
  }
  else
  {
    /* 规格化数 */
    exp += 1;
  }

  return sig << 31 | exp << 23 | frac;
}

int main()
{
  float_bits f1 = 0x007FFFFF;
  assert(u2f(float_twice(f1)) == u2f(f1) * 2);

  return 0;
}