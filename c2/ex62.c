#include <stdio.h>

// 这题没看懂
// 找了一个答案
// 知道了是在做什么：就是判断 >> 是算术右移还是逻辑右移
int int_shifts_are_arithmetic()
{
    int test = -1;
    return !(test ^ (test >> 1));
}

int main()
{
    printf("%d", int_shifts_are_arithmetic());
    return 0;
}