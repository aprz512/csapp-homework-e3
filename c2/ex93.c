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
  unsigned sign = f >> 31;
  unsigned exp = f >> 23 & 0xFF;
  unsigned frac = f & 0x7FFFFF;

// not a number
  if (exp == 0 && frac != 0)
  {
    return f;
  }
  else
  {
    return  (exp << 23) | frac;
  }
}

int main()
{
  /**
   * @brief
   *
   */

  return 0;
}