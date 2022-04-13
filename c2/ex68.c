#include <assert.h>
#include <stdio.h>

/**
 * @brief n = 6，输出 0x3F
 *
 * @param n
 * @return int
 */
int lower_one_mask(int n)
{
    unsigned num = -1;
    int w = sizeof(int) << 3;
    return num << n >> (w - n);
}

int main()
{
    printf("x = %x\n", lower_one_mask(6));

    return 0;
}
