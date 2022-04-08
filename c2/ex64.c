#include <stdio.h>

// 奇数位，从1开始
int any_odd_one(unsigned x)
{
    return 1 - !(x & 0x555555);
}

int main()
{
    printf("x = 1, %d\n", any_odd_one(1));
    printf("x = 2, %d\n", any_odd_one(2));
    printf("x = 0xaa11, %d\n", any_odd_one(0xaa11));

    return 0;
}
