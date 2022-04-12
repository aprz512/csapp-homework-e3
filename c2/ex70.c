
#include <stdio.h>
#include <assert.h>

/**
 * @brief 英文不好，这题没看懂意思，看了答案才知道
 * x 能否表示为 n 位二进制补码形式
 * @param x
 * @param n
 * @return unsigned
 */
int fits_bits(int x, int n)
{
    int w = sizeof(int) << 3;
    int shift = w - n;
    return !((x << shift >> shift) ^ x);
}

int main()
{
    assert(!fits_bits(0xFF, 8));
    assert(!fits_bits(~0xFF, 8));

    assert(fits_bits(0b0010, 3));
    assert(!fits_bits(0b1010, 3));
    assert(!fits_bits(0b0110, 3));

    assert(fits_bits(~0b11, 3));
    assert(!fits_bits(~0b01000011, 3));
    assert(!fits_bits(~0b111, 3));
    return 0;
}
