#include <stdio.h>

typedef unsigned char *byte_pointer;

int is_little_endian()
{
    int x = 1;
    char first_byte = (&x)[0];
    if (first_byte != 0)
    {
        return 1;
    }

    return 0;
}

int main()
{

    int ret = is_little_endian();
    printf("is_little_endian = %d", ret);

    return 0;
}