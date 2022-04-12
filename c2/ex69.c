
#include <stdio.h>
#include <assert.h>

/**
 * @brief
 *
 * 0 <= n < w
 * 假设 x = 0x12345678，w = 32
 * n = 4 时，输出 0x23456781
 * n = 20 时，输出 0x67812345
 *
 * @param x
 * @param n
 * @return unsigned
 */
unsigned rotate_left(unsigned x, int n)
{
    int w = sizeof(int) << 3;
    return x << n | (x >> (w - n));
}

int main()
{
    assert(rotate_left(0x12345678, 4) == 0x23456781);
    assert(rotate_left(0x12345678, 20) == 0x67812345);
    return 0;
}
