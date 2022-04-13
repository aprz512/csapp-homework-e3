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
int divide_power2(int x, int k)
{
  int is_neg = x & INT_MIN;
  (is_neg && (x = x + (1 << k) - 1));
  return x >> k;
}

int main()
{

  printf("divide_power2 = %d\n", divide_power2(-3, 2));

  return 0;
}