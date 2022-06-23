#include <stdio.h>



int factorial(int n) {

    if (n < 0)
    {
        return -1;
    }

    int result = 1;
    int temp;
    for (size_t i = 1; i <= n; i++)
    {
        temp = result * i;

        if (temp / result != i)
        {
            printf("在 i = %d 处溢出了, 最大数为 = %d\n", i, result);
            break;
        }

        result = temp;
    }

    return 0;
}

int main() {
    factorial(10000);
    return 0;
}