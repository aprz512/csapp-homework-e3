#include <assert.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/num.h"

typedef unsigned float_bits;

/**
 * @brief 计算f的绝对值
 *
 * @param f
 * @return float_bits
 */
float_bits float_absval(float_bits f)
{
  // unsigned sign = f >> 31;
  // unsigned exp = f >> 23 & 0xFF;
  unsigned frac = f & 0x7FFFFF;

  // not a number
  if (exp == 0 && frac != 0)
  {
    return f;
  }
  else
  {
    return f & 0x7FFFFFFF;
  }
}

int main()
{
  float f1 = -0.1;
  float f2 = -1;
  float f3 = 10000;

  printf("%f\n", u2f(float_absval(f2u(f1))));
  // 靠，只接受整形
  printf("%f\n", abs(f1));
  
  assert(u2f(float_absval(f2u(f1))) == -f1);
  assert(u2f(float_absval(f2u(f2))) == -f2);
  assert(u2f(float_absval(f2u(f3))) == f3);

  return 0;
}