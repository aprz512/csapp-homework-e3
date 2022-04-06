#include <stdio.h>

unsigned srl(unsigned x, int k)
{
    unsigned xsra = (int)x >> k;
    int w = sizeof(int) << 3;
    int mask = (int)-1 << (w - k);
    return xsra & (~mask);
}

int sra(int x, int k)
{
    int xsrl = (unsigned)x >> k;
    int w = sizeof(int) << 3;
    int mask = (int)-1 << (w - k);
    int symbol_mask = (int)-1 << (w - 1);
    mask = mask & (!(symbol_mask & x) - 1);
    return xsrl | mask;
}

int main()
{
    printf("%d", int_shifts_are_arithmetic());
    return 0;
}