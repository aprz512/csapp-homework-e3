#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for ( i = 0; i < len; i++)
    {
        printf(" %.2x", start[i]);
    }
    printf("\n");
    
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_point(void* x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

int main() {

    int x = 1;
    // 结果输出 01 00 00 00
    // 显然是小端序
    show_int(x);
    return 0;
}