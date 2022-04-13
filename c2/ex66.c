#include <stdio.h>
#include <assert.h>

/**
 * @brief Generate mask indicating leftmost 1 in x. Assume w=32
 * For example, 0xFF00 -> 0x8000, and 0x6000 -> 0x4000.
 * If x = 0, then return 0
 *
 * @param x
 * @return int
 */
int leftmost_one(unsigned x)
{
    // 有个小技巧
    // 0x8000 = 0x7FFF + 1
    // 那么我们怎么得到 0x7FFF 呢？将最高位不断左移就行
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    // 不直接 + 1，是因为 x 为 0 的时候会出问题
    return (x >> 1) + (x & 1);
}

int main()
{
    assert(leftmost_one(0xFF00) == 0x8000);
    assert(leftmost_one(0x6000) == 0x4000);
    assert(leftmost_one(0x0) == 0x0);
    assert(leftmost_one(0x80000000) == 0x80000000);
    return 0;
}
