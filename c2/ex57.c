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

// short 与  int 函数原型冲突
// void show_int(int x)
// {
//     show_bytes((byte_pointer)&x, sizeof(int));
// }

void show_float(float x)
{
    show_bytes((byte_pointer)&x, sizeof(float));
}

void show_point(void *x)
{
    show_bytes((byte_pointer)&x, sizeof(void *));
}

void show_short(short x)
{
    show_bytes((byte_pointer)&x, sizeof(short));
}

void show_long(long x)
{
    show_bytes((byte_pointer)&x, sizeof(long));
}

void show_double(double x)
{
    show_bytes((byte_pointer)&x, sizeof(double));
}

int main()
{

    short s = 6;
    long l = 5L;
    double d = 1.0;

    show_short(s);
    show_long(l);
    show_double(d);

    return 0;
}