#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main()
{

  int x = -1;
  int y = -1;
  int z = INT32_MIN;

  double dx = (double)x;
  double dy = (double)y;
  double dz = (double)z;

  // A  对，精度没丢失

  // B  错，y = INT_MIN 丢失精度
  // printf("%x", (double)(1-INT32_MIN));

  // C 对

  // D 网上都说错了，但是没有例子

  // printf("%lf -- %lf", (dx * dy) * dz, dx * (dy * dz));

  // E 错，除以0有问题

  return 0;
}