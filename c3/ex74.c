/**
 * @file ex74.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-23
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
Write a function in assembly code that matches the behavior of the function find_
range in Figure 3.51. Your code should contain only one floating-point comparison
instruction, and then it should use conditional moves to generate the correct result.
You might want to make use of the instruction cmovp (move if even parity). Test
your code on all 2^32 possible argument values. Web Aside asm:easm on page 214
describes how to incorporate functions written in assembly code into C programs.
 * 
 */

#include <stdio.h>
#include <assert.h>

typedef enum
{
    NEG,
    ZERO,
    POS,
    OTHER
} range_t;

range_t find_range(float x)
{
    __asm__(
        "vxorps %xmm1, %xmm1, %xmm1       # 将xmm1置为0 \n\t"
        "vucomiss %xmm1, %xmm0            # x : 0  \n\t"
        "movq $3, %rsi                       \n\t"
        "movq $2, %rax                    # 这里取个默认值，返回值为 2 \n\t"
        "movq $1, %rcx                       \n\t"
        "movq $0, %rdx                       \n\t"
        "cmoveq %rcx, %rax       # x = 0 \n\t"
        "cmovbq %rdx, %rax       # x < 0 \n\t"
        "cmovpq %rsi, %rax       # NaN \n\t"
        ".Done:\n\t");
}

int main()
{
    /**
     * @brief 这里其实和 73 是差不多的，只不过需要先计算表达式的值，
     * 因为表达式本身是一个值，所以，计算也可以省略
     * 
     */
    range_t n = NEG, z = ZERO, p = POS, o = OTHER;

    assert(o == find_range(0.0 / 0.0));
    assert(n == find_range(-2.3));
    assert(z == find_range(0.0));
    assert(p == find_range(3.33));

    return 0;
}