/**
 * @file ex58.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-06-23
 *
 * @copyright Copyright (c) 2022
 *
    For a function with prototype
    long decode2(long x, long y, long z);
    gcc generates the following assembly code:
    1 decode2:
    2 subq %rdx, %rsi
    3 imulq %rsi, %rdi
    4 movq %rsi, %rax
    5 salq $63, %rax
    6 sarq $63, %rax
    7 xorq %rdi, %rax
    8 ret
    Parameters x, y, and z are passed in registers %rdi, %rsi, and %rdx. The code
    stores the return value in register %rax.
    Write C code for decode2 that will have an effect equivalent to the assembly
    code shown.
 *
 */

#include <stdio.h>
#include <assert.h>

long decode2(long x, long y, long z)
{
    // 前面3条指令比较简单
    y -= z;
    long temp = y;
    x *= y;

    // 下面两条指令其实就是判断 temp 的最后一位是0 还是 1
    // 如果是 0，那么 temp = 0，如果是 1，那么 temp 为 -1
    // 最后 x 的结果不是 x 就是 ~x
    temp <<= 63;
    temp >>= 63;
    return x ^ temp;
}

long decode22(long x, long y, long z)
{
    y -= z;
    x *= y;
    return (y % 2 == 0 ? x : ~x);
}

int main()
{
    assert(decode2(1, 2, 3) == decode22(1, 2, 3));
    assert(decode2(-1, 2, 73) == decode22(-1, 2, 73));
    assert(decode2(1, 2, 3) != decode22(3, 1, 2));
    return 0;
}
