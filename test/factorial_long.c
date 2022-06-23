#include <stdio.h>



int factorial(size_t n) {
    long result = 1;
    long temp;

    for (size_t i = 1; i <= n; i++)
    {
        temp = result * i;
        printf("temp = %ld\n", temp);

        if (temp / result != i)
        {
            printf("在 i = %d 处溢出了, 最大数为 = %ld\n", i, result);
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