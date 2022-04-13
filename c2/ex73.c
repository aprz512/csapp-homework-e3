
#include <stdio.h>
#include <assert.h>
#include <limits.h>

int saturating_add(int x, int y)
{
    int sum = x + y;
    int sig_mask = INT_MIN;
    /*
     *  x > 0, y > 0，但是相加后 sum < 0，正溢出
     *  x < 0, y < 0 ，相加后结果 sum >= 0, 负溢出
     */
    int pos_over = !(x & sig_mask) && !(y & sig_mask) && (sum & sig_mask);
    int neg_over = (x & sig_mask) && (y & sig_mask) && !(sum & sig_mask);

    (pos_over && (sum = INT_MAX) || neg_over && (sum = INT_MIN));

    return sum;
}

int main()
{
    printf("%x", INT_MIN);
    return 0;
}
