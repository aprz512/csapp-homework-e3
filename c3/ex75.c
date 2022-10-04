/**
 * @file ex75.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-04
 * 
 * @copyright Copyright (c) 2022
 * 
ISO C99 includes extensions to support complex numbers. Any floating-point type
can be modified with the keyword complex. Here are some sample functions that
work with complex data and that call some of the associated library functions:

#include <complex.h>

double c_imag(double complex x) {
    return cimag(x);
}

double c_real(double complex x) {
    return creal(x);
}

double complex c_sub(double complex x, double complex y) {
    return x - y;
}

When compiled, gcc generates the following assembly code for these functions:

double c_imag(double complex x)
c_imag:
    movapd %xmm1, %xmm0
    ret

double c_real(double complex x)
c_real:
    rep; ret

double complex c_sub(double complex x, double complex y)
c_sub:
    subsd %xmm2, %xmm0
    subsd %xmm3, %xmm1
    ret

Based on these examples, determine the following:
A. How are complex arguments passed to a function?
B. How are complex values returned from a function?

 * 
 * 
 */

int main() {

    /**
     * @brief 
     * creal cimag 分别是取实部和虚部
     * 
     * 看 c_real 的汇编，里面什么都没有，返回值是 %xmm0，所以 %xmm0 储存的是实部
     * 看 c_imag 的汇编，%xmm0 的值被 %xmm1 覆盖，所以 %xmm1 储存的是虚部
     * 看 c_sub 的汇编， %xmm2 与 %xmm3 也参与了计算，所以可以猜测，%xmm2 储存了第二个参数的实部，%xmm3 储存了第二个参数的虚部
     * 然后，可以继续往后推测，%xmm4，%xmm5等等
     * 
     */
    return 0;
}