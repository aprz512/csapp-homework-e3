#include <assert.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/num.h"

typedef unsigned float_bits;

/**
 * @brief 计算   0.5 * f
 * 规格化的数 / 2 可能会变成规格化数，判断 exp == 1 时，右移即可
 *
 *
 * @param f
 * @return float_bits
 */
float_bits float_half(float_bits f)
{
  unsigned sig = f >> 31;
  unsigned rest = f & 0x7FFFFFFF;
  unsigned exp = f >> 23 & 0xFF;
  unsigned frac = f & 0x7FFFFF;

  int is_NAN_or_oo = (exp == 0xFF);
  if (is_NAN_or_oo)
  {
    return f;
  }

  /*
   * round to even, we care about last 2 bits of frac
   *
   * 00 => 0 just >>1
   * 01 => 0 (round to even) just >>1
   * 10 => 1 just >>1
   * 11 => 1 + 1 (round to even) just >>1 and plus 1
   */
  int addition = (frac & 0x3) == 0x3;

  if (exp == 0)
  {
    /* Denormalized */
    frac >>= 1;
    frac += addition;
  }
  else if (exp == 1)
  {
    /* Normalized to denormalized */
    rest >>= 1;
    rest += addition;
    exp = 0;
    frac = rest & 0x7FFFFF;
  }
  else
  {
    /* Normalized */
    exp -= 1;
  }

  return sig << 31 | exp << 23 | frac;
}

int main()
{
  float_bits f1 = 67;
  assert(u2f(float_half(f1)) == u2f(f1) / 2);

  return 0;
}