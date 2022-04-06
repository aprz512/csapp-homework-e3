#include <stdio.h>

int main()
{
    int first = 0x89ABCDEF;
    int second = 0x76543210;

    int ret = (first & 0xFF) | (second & 0xFFFFFF00);

    printf("ret = %x\n", ret);

    return 0;
}