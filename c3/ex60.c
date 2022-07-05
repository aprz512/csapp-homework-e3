/**
 * @file ex60.c
 *
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-05
 *
 * @copyright Copyright (c) 2022
 *
 *
 *
Consider the following assembly code:
long loop(long x, int n)
x in %rdi, n in %esi
loop:
movl %esi, %ecx
movl $1, %edx
movl $0, %eax
jmp .L2
.L3:
movq %rdi, %r8
andq %rdx, %r8
orq %r8, %rax
 salq %cl, %rdx
 .L2:
 testq %rdx, %rdx
 jne .L3
 rep; ret
The preceding code was generated by compiling C code that had the following
overall form:

    long loop(long x, long n)
    {
        long result = [----];
        long mask;
        for (mask = [----]; mask ; mask = [----]) {
            result |= [----];
        }
        return result;
    }

Your task is to fill in the missing parts of the C code to get a program equivalent
to the generated assembly code. Recall that the result of the function is returned
in register %rax. You will find it helpful to examine the assembly code before,
during, and after the loop to form a consistent mapping between the registers and
the program variables.
A. Which registers hold program values x, n, result, and mask?
B. What are the initial values of result and mask?
C. What is the test condition for mask?
D. How does mask get updated?
E. How does result get updated?
F. Fill in all the missing parts of the C code.
 */

#include <stdio.h>

/**
 * @brief 算法，将 x 的二进制表示的低 n 位翻转
 * 
 * @param x 
 * @param n 
 * @return long 
 */
long loop(long x, long n)
{
    // result 对应的 rax，初始值是 eax，为 0
    long result = 0;
    long mask;

    // mask 对应的寄存器是 rdx，初始值为1
    for (mask = 1; mask != 0; mask = mask << n)
    {
        result |= （x & mask）;
    }
    return result;
}

int main()
{
    /*
long loop(long x, int n)
x in %rdi, n in %esi
loop:
    movl %esi, %ecx         -> ecx = n
    movl $1, %edx           -> edx = 1
    movl $0, %eax           -> eax = 0
    jmp .L2                 -> 跳转到 L2
.L3:
    movq %rdi, %r8          -> r8 = x
    andq %rdx, %r8          -> r8 = r8 & rdx = x & rdx，rdx 是 edx
    orq %r8, %rax           -> rax = rax | r8，rax 是 eax
    salq %cl, %rdx          -> rdx = rdx << n，cl 是 ecx
.L2:
    testq %rdx, %rdx        -> rdx : 0
    jne .L3                 -> if (rdx != 0) jmp L3
    rep; ret                -> return
 */

    return 0;
}
