
#include <stdio.h>
#include <assert.h>
#include <limits.h>

int add_ok(int x, int y)
{
    int sig_mask = INT_MIN;
    int sum = x + y;
    int pos_over = !(x & sig_mask) && !(y & sig_mask) && (sum & sig_mask);
    int neg_over = (x & sig_mask) && (y & sig_mask) && !(sum & sig_mask);
    return !(pos_over || neg_over);
}

int tsub_ok(int x, int y)
{
    // x - y, 不溢出 -y = ~y + 1

    int ny = ~y + 1;
    int add = add_ok(x, ny);

    return add && (y != INT_MIN);
}

int main()
{
    assert(!tsub_ok(0x00, INT_MIN));
    assert(tsub_ok(0x00, 0x00));
    return 0;
}
