#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main()
{
  int x = 1;
  int a = (x << 4) + x;
  int b = x - (x << 3);
  int c = (x << 6) - (x << 2);
  int d = (x << 4) - (x << 7);

  printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);

  return 0;
}