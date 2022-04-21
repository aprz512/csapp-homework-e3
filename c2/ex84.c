#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned f2u(float x) {
  return *(unsigned*)&x;
}

int float_le(float x, float y) {
  unsigned ux = f2u(x);
  unsigned uy = f2u(y);

  unsigned sx = ux >> 31;
  unsigned sy = uy >> 31;

  // ref: https://github.com/DreamAndDead/CSAPP-3e-Solutions/issues/1
  return (ux << 1 == 0 && uy << 1 == 0) || /* both zeros */
    (sx && !sy) ||                         /* x < 0, y >= 0 or x <= 0, y > 0 */
    (!sx && !sy && ux <= uy) ||            /* x > 0, y >= 0 or x >= 0, y > 0 */
    (sx && sy && ux >= uy);                /* x < 0, y <= 0 or x <= 0, y < 0 */
}

/**
 * @brief 这题直接copy答案了，没有什么太好的办法，只能利用正负数一点一点比较
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[]) {
  assert(float_le(-0, +0));
  assert(float_le(+0, -0));
  assert(float_le(0, 3));
  assert(float_le(-4, -0));
  assert(float_le(-4, 4));
  return 0;
}