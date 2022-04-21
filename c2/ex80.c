#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int threefourths(int x)
{
  int x3 = x + (x << 1);
  int s = x & INT32_MIN;
  s && (x3 = x3 + 3);
  return x3 >> 2;
}

int main()
{

  assert(threefourths(8) == 6);
  assert(threefourths(9) == 6);
  assert(threefourths(10) == 7);
  assert(threefourths(11) == 8);
  assert(threefourths(12) == 9);

  assert(threefourths(-8) == -6);
  assert(threefourths(-9) == -6);
  assert(threefourths(-10) == -7);
  assert(threefourths(-11) == -8);
  assert(threefourths(-12) == -9);
  return 0;
}