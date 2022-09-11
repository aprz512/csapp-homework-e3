/*
(a) C code

#include <alloca.h>

long aframe(long n, long idx, long *q) {
    long i;
    long **p = alloca(n * sizeof(long *));
    p[0] = &i;
    for (i = 1; i < n; i++)
        p[i] = q;
    return *p[idx];
}

(b) Portions of generated assembly code

long aframe(long n, long idx, long *q)
n in %rdi, idx in %rsi, q in %rdx
aframe:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp          Allocate space for i (%rsp = s1)
    leaq 30(,%rdi,8), %rax
    andq $-16, %rax
    subq %rax, %rsp         Allocate space for array p (%rsp = s2)
    leaq 15(%rsp), %r8
    andq $-16, %r8          Set %r8 to &p[0]
    .
    .
    .

Figure 3.54(a) shows the code for a function that is similar to function vfunct
We used vfunct to illustrate the use of a frame pointer in managing variable-size stack frames. 
The new function aframe allocates space for local array p by calling library function alloca. 
This function is similar to the more commonly used function malloc, except that it allocates space on the run-time stack.
The space is automatically deallocated when the executing procedure returns.

Figure 3.54(b) shows the part of the assembly code that sets up the frame
pointer and allocates space for local variables i and p. It is very similar to the
corresponding code for vframe. Let us use the same notation as in Problem 3.49:
The stack pointer is set to values s1 at line 4 and s2 at line 7. The start address of
array p is set to value p at line 9. Extra space e2 may arise between s2 and p, and
extra space e1 may arise between the end of array p and s1.

A. Explain, in mathematical terms, the logic in the computation of s2.
B. Explain, in mathematical terms, the logic in the computation of p.
C. Find values of n and s1 that lead to minimum and maximum values of e1.
D. What alignment properties does this code guarantee for the values of s2 and p?

*/

#include <stdio.h>


int main()
{
    /*
    变长数组在栈中的分配
    因为数组使用 alloca 函数分配，分配的地址空间要求起始地址是 16 的倍数。
    所以必然会出现书中第3章，图 3-44 的 e1 与 e2 空间。
    */

   /*
   A 
   s2 = s1 - (30 + 8*n) & 0xfffffff0

   当 n 是奇数， s2 = s1 - （24 + 8*n）
   当 n 是偶数， s2 = s1 - （16 + 8*n）
   */


    /*
   B
   p = (s2 + 15) & 0xfffffff0

    这个是计算 e2 的大小，当栈空间分配好之后（24 + 8*n 或者 16 + 8*n），那么就需要确定 p 的位置了，因为 p 要是 16 的倍数，所以采用 + 15 然后 & 0xfffffff0 的方法，就可以得出距离 s2 最近的 16 的倍数。
   */

  /*
  C

  看 b 的汇编，是先确定 e2 的大小。
  当 s2 是16 的倍数时， e2 最小为0，那么当n是偶数的时候， e1+e2=24，所以 e1 最大是 24。
  当 s2 不是 16 的倍数时，e2 最大为15，那么当n是奇数的时候，e1 + e2 = 16，所以 e1 最小为1.
  
  */

  /*
  D
  p 是 16 倍数对齐
  s2 也是 16 倍数对齐，时容下8 * n字节的最小的16的倍数再加16。
  */

    return 0;
}