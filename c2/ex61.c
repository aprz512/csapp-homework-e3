#include <stdio.h>

int testA(int x)
{
    return !(~x);
}

int testB(int x)
{
    return !x;
}

int testC(int x)
{
    // 将其他位替换为 1
    return testA(x | ~0xFF);
}

int testD(int x)
{
    // 将其他位替换为 0
    int w = sizeof(int) << 8;
    int shift = w - 8;
    return testB(x & (0xFF << shift));
}

int main()
{
    printf("testA: %d\n", testA(-1));
    printf("testB: %d\n", testB(0));
    printf("testC: %d\n", testC(255));
    printf("testD: %d\n", testD(-1));

    return 0;
}