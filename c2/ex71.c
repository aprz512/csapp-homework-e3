
#include <stdio.h>
#include <assert.h>

typedef unsigned packed_t;

/**
 * @brief 使用补码运算和算数右移
 * 这题没看懂想考什么，只能使用算数右移，所以要将 unsigned 强转为 int ？？？
 * 然后将要截取的字节符号扩展为 32 位。
 * @param x
 * @param n
 * @return unsigned
 */
int xbyte(packed_t word, int bytenum)
{
    return (word >> (bytenum << 3)) & 0xFF;
}

/**
 * @brief 贴一个别人的答案吧
 *
 * @param word
 * @param bytenum
 * @return int
 */
int xbyte2(packed_t word, int bytenum)
{
    int max_bytenum = 3;
    return (int)word << ((max_bytenum - bytenum) << 3) >> (max_bytenum << 3);
}

int main()
{
    printf("%x", xbyte2(0xAABBCC00, 0));
    return 0;
}
