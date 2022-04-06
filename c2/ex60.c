#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    unsigned merge = b;
    int shift = i;
    unsigned mask = 0xff;
    while (shift > 0)
    {
        merge <<= 8;
        mask <<= 8;
        shift--;

        printf("i = %d\n", i);
    }
    return (x & ~mask) | merge;
}

int main()
{
    printf("ret = %x\n", replace_byte(0x12345678, 2, 0xAB));
    printf("ret = %x\n", replace_byte(0x12345678, 0, 0xAB));

    return 0;
}