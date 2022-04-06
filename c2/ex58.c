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

//利用联合体共享内存的特性，来判断是大端小端,
// union里面的成员c和i都是从低地址开始对齐的。
int is_little_endian2()
{
    union w
    {
        int a;
        char b;
    } c;
    c.a = 1;
    return (c.b == 1); // 小端返回TRUE,大端返回FALSE
}

int main()
{

    int ret = is_little_endian();
    printf("is_little_endian = %d\n", ret);

    int ret2 = is_little_endian2();
    printf("is_little_endian2 = %d", ret2);

    return 0;
}