#include <assert.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/num.h"

typedef unsigned float_bits;

/**
 * @brief
 * 将 f 转成 int 类型的数
 * 如果 f 是 NaN，返回 0
 * 如果 f 转成 int 后，超出范围或者 NaN，返回 0x80000000
 *
 *
 *
 * @param f
 * @return float_bits
 */
float_bits float_f2i(float_bits f)
{
  unsigned sig = f >> 31;
  unsigned exp = f >> 23 & 0xFF;
  unsigned frac = f & 0x7FFFFF;
  unsigned bias = 0x7F;

  /**
   * @brief exp == 0 的时候，都是小于 1 的数，变为 0
   *
   * exp > 0 有一部分是小于 0 的数，当 exp >= bias，计算出来的才是大于 1 的
   *
   */
  if (exp >= 0 && exp < bias)
  {
    return 0;
  }
  /**
   * @brief 当exp - bias > 31 的时候，溢出了
   * 当 exp - bias = 31 的时候，只有 INI_MIN 的情况才符合，这个也可以表示为 0x80000000
   */
  else if (exp - bias > 31)
  {
    return 0x80000000;
  }
  else
  {
    int num;
    unsigned E;
    unsigned M;
    E = exp - bias;
    // M = 1 + f
    M = frac | 0x800000;
    // 将 float 转成 int，因为 frac 是精度，所以如果能全表示，只需要左移就好了
    if (E > 23)
    {
      num = M << (E - 23);
    }
    // 如果不能全部表示，那么就右移
    // 假设 E = 1，那么其实就是将 M 右移22 位
    else
    {
      /* whether sig is 1 or 0, round to zero */
      num = M >> (23 - E);
    }
    return sig ? -num : num;
  }
}

int main()
{
  float_bits f1 = 67;
  assert(u2f(float_half(f1)) == u2f(f1) / 2);

  return 0;
}