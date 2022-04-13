#include <stdio.h>
#include <assert.h>
#include <inttypes.h>

int signed_high_prod(int x, int y) {
  int64_t mul = (int64_t) x * y;
  return mul >> 32;
}

/**
 * @brief 这里看了答案，还是没看懂，为啥最后一项不用处理
 * 网上找了一下：https://www.zhihu.com/question/45395026，2^64次方太大，一个数左移64次会变成0，不会影响结果
 * 
 * 但是我还有一个疑问，不是证明了无符号数与补码乘法位级是一致的么？为啥不直接用
 * 哦，是低位一样，取模导致一样
 * 
 * @param x 
 * @param y 
 * @return unsigned 
 */
unsigned unsigned_high_prod(unsigned x, unsigned y) {
  /* TODO calculations */
  int sig_x = x >> 31;
  int sig_y = y >> 31;
  printf("sig_x = %d\n", sig_x);
  printf("sig_y = %d\n", sig_y);
  printf("offset = %d\n", x * sig_y + y * sig_x);
  int signed_prod = signed_high_prod(x, y);
  return signed_prod + x * sig_y + y * sig_x;
}

/* a theorically correct version to test unsigned_high_prod func */
unsigned another_unsigned_high_prod(unsigned x, unsigned y) {
  uint64_t mul = (uint64_t) x * y;
  return mul >> 32;
}

int main(int argc, char* argv[]) {
  unsigned x = -0xa;
  unsigned y = -0x4;

  assert(another_unsigned_high_prod(x, y) == unsigned_high_prod(x, y));
  return 0;
}