#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int testA(int k)
{
  int w = sizeof(int) << 3;

  int mask = -1;

  return (unsigned)-1 << k;
}

int testB(int j, int k)
{
  int w = sizeof(int) << 3;

  unsigned mask = -1;

  return (mask << j) >> (w - k - j);
}

int main()
{

  assert(testA(8) == 0xFFFFFF00);
  assert(testB(16, 8) == 0x00FFFF00);

  return 0;
}