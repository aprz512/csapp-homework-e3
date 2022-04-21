#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  // 假设 w = 8
  // A, 错， x 为 -128， y 为 -127，那么x转成负数会溢出，结果还是 -128

  printf("%x\n", -INT32_MIN);

  // B, 对，右移 == 乘法

  // C, 对，-y = ~y +1

  // D, 错，右边一定为负数

  // E, 对，x为正数时，x为负数时

  int x = 1;
  int y = 10;
  unsigned ux = (unsigned)x;
  unsigned uy = (unsigned)y;

  printf("%u\n", (ux - uy));
  printf("%d\n", -(unsigned)(y - x));

  return 0;
}