#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/**
 * @brief 负数直接右移会导致舍入不正确，需要加一个偏置值，使其向0舍入
 *
 * @param x
 * @param k
 * @return int
 */
int mul3div4(int x)
{
  // 溢出
  int mul = x * 3;
  (mul & INT64_MIN) && (mul = mul + 3);
  return mul >> 2;
}

int main()
{

  int x = 0x87654321;
  assert(mul3div4(x) == x * 3 / 4);
  return 0;
}