/**
 * @file ex58.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-06-23
 *
 * @copyright Copyright (c) 2022
 *
The following code computes the 128-bit product of two 64-bit signed values x and
y and stores the result in memory:
1 typedef __int128 int128_t;
2 3
void store_prod(int128_t *dest, int64_t x, int64_t y) {
4 *dest = x * (int128_t) y;
5 }
Gcc generates the following assembly code implementing the computation:

1 store_prod:
2 movq %rdx, %rax
3 cqto
4 movq %rsi, %rcx
5 sarq $63, %rcx
6 imulq %rax, %rcx
7 imulq %rsi, %rdx
8 addq %rdx, %rcx
9 mulq %rsi
10 addq %rcx, %rdx
11 movq %rax, (%rdi)
12 movq %rdx, 8(%rdi)
13 ret

This code uses three multiplications for the multiprecision arithmetic required
to implement 128-bit arithmetic on a 64-bit machine. Describe the algorithm used
to compute the product, and annotate the assembly code to show how it realizes
your algorithm. Hint: When extending arguments of x and y to 128 bits, they can
be rewritten as x = 264 . xh + xl and y = 264 . yh + yl, where xh, xl, yh, and yl are 64-
bit values. Similarly, the 128-bit product can be written as p = 264 . ph + pl, where
ph and pl are 64-bit values. Show how the code computes the values of ph and pl
in terms of xh, xl, yh, and yl.
 *
 */

#include <stdio.h>
#include <assert.h>



int main()
{

    // 一个 128 位的有符号数，用两个 64 位的有符号数来表示： xh * 2^64 + xl
    // 两个有符号的 64 位数相乘，我们先需要将他们扩展到 128 位：
    // x * y = (xh * 2^64 + xl) * (yh * 2^64 + yl)
    // 由于有符号数扩展的时候，只需要将高位全部置位符号位即可，所以我们可以很轻松的得到 xh 与 yh
    // 相乘结果为 xh * yh * 2^128 + xh * 2^64 * yl + xl * yh * 2^64 + xl * yl
    // 第一项 xh * yh * 2^128 超过了 128 位，直接忽略，64 * 64 的结果不会超过 128 位
    // 第二三四项可以算出来

/**
 * @brief 
 *  1 store_prod:
    2 movq %rdx, %rax           -> rax = y
    3 cqto                      -> 将 rdx 置为 y 的符号位，也就是 yh
    4 movq %rsi, %rcx           -> rcx = x
    5 sarq $63, %rcx            -> 将 rcx 置为 x 的符号位，也就是 xh
    6 imulq %rax, %rcx          -> rcx = xh * y
    7 imulq %rsi, %rdx          -> rdx = yh * x
    8 addq %rdx, %rcx           -> rcx = xh * y + yh * x
    9 mulq %rsi                 -> rdx:rax <= y * x，无符号计算 （将一个 64 位数扩展为 128 位进行计算，低位就相当于无符号计算）
    10 addq %rcx, %rdx          -> rdx += rcx，因为 rdx 表示结果的高位，加上 rcx 就相当于把 rcx 乘以 2^64
    11 movq %rax, (%rdi)        -> *rdi = rax，存放低位
    12 movq %rdx, 8(%rdi)       -> *(rdi+8) = rdx，存放高位
    13 ret
 * 
 */

    return 0;
}
