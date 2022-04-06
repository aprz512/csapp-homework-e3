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

    show_int(1);
    //  00 00 80 3f，这个可以自己算一下是否符合期望，1 + 8 + 23
    show_float(1.0f);
    int p = 0;
    show_point(&p);
    return 0;
}