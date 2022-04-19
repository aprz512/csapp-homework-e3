#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

float u2f(unsigned u)
{
  return *(float *)(&u);
}

float fpwr2(int x)
{

  /**
   * @brief
   * exp 代表的是 E + bias
   * frac 代表的是 M
   *
   */
  unsigned exp, frac;
  unsigned u;

  int bias = pow(2, 7) - 1;

  /**
   * @brief 能表示的最小数
   *
   */
  if (x < 1 - bias - 23)
  {
    exp = 0;
    frac = 0;
  }
  /**
   * @brief 1 - bias - 1 非规格化数能表示的最大值（2的幂次方）
   *
   */
  else if (x < 1 - bias)
  {
    exp = 0;
    // 就是只能在表示小数位的 23 位中选一位
    frac = 1 << abs(x - (1 - bias - 23));
  }
  /**
   * @brief 规格化数能表示的最大值（2的幂次方）为 bias
   * 
   */
  else if (x < bias + 1)
  {

    exp = bias + x;
    frac = 0;
  }
  else
  {
    exp = 0xFF;
    frac = 0;
  }

  u = exp << 23 | frac;

  return u2f(u);
}

int main()
{
  assert(fpwr2(0) == powf(2,0));
  assert(fpwr2(100) == powf(2,100));
  assert(fpwr2(-100) == powf(2,-100));
  assert(fpwr2(10000) == powf(2,10000));
  assert(fpwr2(-10000) == powf(2,-10000));

  return 0;
}