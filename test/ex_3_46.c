#include <stdio.h>

void get(char a[2])
{
    printf("get a addr = %x\n", a);

    a[0] = 3;
    a[1] = 4;
}

void put(char a[2])
{
    printf("put a addr = %x\n", a);

    a[0] = 5;
    a[1] = 6;
}

int main()
{

    char a[2];
    printf("main a addr = %x\n", a);
    a[0] = 1;
    a[1] = 2;
    get(a);
    put(a);

    printf("a[0] = %d\n", a[0]);
    printf("a[1] = %d\n", a[1]);

    return 0;
}