#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++)
    {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_pointer)&x, sizeof(float));
}

void show_point(void *x)
{
    show_bytes((byte_pointer)&x, sizeof(void *));
}

int main()
{

    int x = 1;
    // 结果输出 01 00 00 00
    // 显然是小端序
    show_int(x);

    int t1 = 0;
    int t2 = 0;

    printf("t1 addr = %x, t2 addr = %x\n", &t1, &t2);
    return 0;
}