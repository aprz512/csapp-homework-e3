/*
Write a function in assembly code that matches the behavior of the function find_
range in Figure 3.51. Your code should contain only one floating-point comparison
instruction, and then it should use conditional branches to generate the correct
result. Test your code on all 232 possible argument values. Web Aside asm:easm
on page 214 describes how to incorporate functions written in assembly code into
C programs.

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
        "jp .P                            # x是NaN \n\t"
        "ja .A                            # 0 > x \n\t"
        "jb .B                            # 0 < x \n\t"
        "je .E                            # 0 = x \n\t"
        ".A:\n\t"
        "movl $2, %eax\n\t"
        "jmp .Done\n\t"
        ".B:\n\t"
        "movl $0, %eax\n\t"
        "jmp .Done\n\t"
        ".E:\n\t"
        "movl $1, %eax\n\t"
        "jmp .Done\n\t"
        ".P:\n\t"
        "movl $3, %eax\n\t"
        ".Done:\n\t");
}

int main()
{
    /**
     * PF 在浮点数运算中，可以用来判断是否有 NaN。
     * 因为 jxx 不会改变标志位，所以可以连续使用。
     * 我最开始的想法是根据x的二进制位特征来入手
     * 中文版书上第214页有PF标志的讲解
     * c 里面嵌套汇编可以参考 http://csapp.cs.cmu.edu/3e/waside/waside-embedded-asm.pdf
     */
    range_t n = NEG, z = ZERO, p = POS, o = OTHER;
    assert(o == find_range(0.0 / 0.0));
    assert(n == find_range(-2.3));
    assert(z == find_range(0.0));
    assert(p == find_range(3.33));

    return 0;
}