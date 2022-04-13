#include <stdio.h>

/**
 * @brief 直接的想法是将所有位异或一遍，1^1 = 0，奇数位个1得到的结果是1
 *
 * @param x
 * @return int
 */
int odd_ones(unsigned x)
{
    // 其实我们只需要后16位结果，这里可以忽略前16位，因为最后我们会&1
    x ^= x >> 16;
    // 其实我们只需要后8位结果
    x ^= x >> 8;
    // 其实我们只需要后4位结果
    x ^= x >> 4;
    // 其实我们只需要后2位结果
    x ^= x >> 2;
    // 其实我们只需要后1位结果
    x ^= x >> 1;
    // 只考虑最后一位
    x &= 0x1;
    return x;
}

int main()
{

    printf("-1 -> %d\n", odd_ones(-1));
    printf("1 -> %d\n", odd_ones(1));
    return 0;
}
