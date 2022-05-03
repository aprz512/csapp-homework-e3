#include "../lib/num.h"
#include <assert.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned float_bits;

/**
 * @brief 计算 i 的二进制位的（从左到右）第一个不为 0 的位，负数的话，先转成正数再计算
 *
 * 0x3 -> 2
 * 0xF -> 4
 * -0x3 -> 2
 *
 * @param i
 * @return int
 */
int bits_length(int i)
{
    if (i < 0)
    {
        return bits_length(-i);
    }
    else if (i == 0)
    {
        return 0;
    }
    else
    {
        int count = 0;
        while (i != 0)
        {
            i = i >> 1;
            count++;
        }
        return count;
    }
}

/**
 * @brief 生成 s 位 1
 *
 * 3 -> 0x7
 *
 * @param s
 * @return int
 */
int bits_mask(short s)
{
    unsigned all = -1;
    return all >> (32 - s);
}

/**
 * @brief float to int
 *
 * 类似于在代码中调用 (float)3
 *
 *
 * @param f
 * @return float_bits
 */
float_bits float_i2f(int i)
{

    if (i == 0)
    {
        return 0;
    }

    if (i == INT32_MIN)
    {
        return 1 << 31 | (0x7f + 31) << 23 | 0;
    }
    // int 的精度是 32 bit
    // float 的精度是 23 bit
    // 如果 int 表示的数字超过 23 位，那么有精度损失

    unsigned sig = 0;
    unsigned bias = 0x7F;
    /* 2's complatation */
    if (i < 0)
    {
        sig = 1;
        i = -i;
    }

    unsigned bits = bits_length(i);
    // 可以少一位
    unsigned fbits = bits - 1;
    unsigned exp = bias + fbits;
    //
    unsigned rest = i & bits_mask(fbits);

    unsigned frac;
    // 除符号位的其他位
    unsigned exp_sig;
    if (fbits <= 23)
    {
        // int 类型是靠右，float 类型是靠23位的左边
        frac = rest << (23 - fbits);
        exp_sig = exp << 23 | frac;
    }
    else
    {
        // 失去的精度位
        int offset = fbits - 23;
        // offset 为4， 则 1 0 0 0
        int round_mid = 1 << (offset - 1);

        unsigned round_part = rest & bits_mask(offset);
        frac = rest >> offset;
        exp_sig = exp << 23 | frac;

        // 判断是否需要舍入
        if (round_part < round_mid)
        {
            // 不需要
        }

        else if (round_part > round_mid)
        {
            // 需要
            exp_sig += 1;
        }
        else
        {
            // 像偶数舍入，则最后一位是 1，那么就 + 1
            if ((frac & 0x1) == 1)
            {
                exp_sig += 1;
            }
        }
    }

    return sig << 31 | exp_sig;
}

int main()
{
    printf("bit_length = %d\n", bits_length(6));
    printf("%f\n", u2f(float_i2f(6)));
    assert(u2f(float_i2f(6)) == (float)6);
    return 0;
}