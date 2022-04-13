#include <stdio.h>
#include <assert.h>

/**
 * @brief 左移超过位数时结果是未定义的，应该使用 %w 计算出最终结果
 *
 * @return int
 */
int int_size_is_32()
{
    int set_msb = 1 << 31;
    int beyong_msb = set_msb << 1;
    return set_msb && !beyong_msb;
}

int int_size_is_32_for_16()
{
    int set_msb = 1 << 15 << 15 << 1;
    int beyong_msb = set_msb << 1;
    return set_msb && !beyong_msb;
}

int main()
{
    assert(int_size_is_32());
    assert(int_size_is_32_for_16());
    return 0;
}
