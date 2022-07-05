/*
In Section 3.6.6, we examined the following code as a candidate for the use of
conditional data transfer:

long cread(long *xp) {
    return (xp ? *xp : 0);
}

We showed a trial implementation using a conditional move instruction but argued
that it was not valid, since it could attempt to read from a null address.
Write a C function cread_alt that has the same behavior as cread, except
that it can be compiled to use conditional data transfer. When compiled, the
generated code should use a conditional move instruction rather than one of the
jump instructions.
*/

#include <stdio.h>

// 条件传送指令需要提前计算两个分支的表达式的值，如果 xp 为 null，会出问题

long cread2(long *xp)
{
    // 我第一想法是先判断一下空指针，看看编译后的结果，结果是不行
    if (xp == NULL)
    {
        return 0;
    }

    return (xp ? *xp : 0);
}

long cread3(long *xp)
{
    // 可以反着来，编译结果还是没有
    return (!xp ? 0 : *xp);
}

// 这里有点奇怪，理论上是可以出现 cmov 的