
#include <stdio.h>
#include <assert.h>


void copy_int(int val, void *buff, int maxbytes)
{
    // sizeof 返回无符号数，导致 maxbytes 也变成无符号数，计算结果也作为无符号数解析，所以总是大于0
    // 将 sizeof 结果转为 int
    if (maxbytes - sizeof(val) >= 0)
    {
        memcpy(buff, (void *)&val, sizeof(val));
    }
}

int main()
{
    printf("%x", xbyte2(0xAABBCC00, 0));
    return 0;
}
