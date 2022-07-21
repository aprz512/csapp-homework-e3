/*
In the following code, A and B are constants defined with #define:

typedef struct {
    int x[A][B];
    long y;
} str1;

typedef struct {
    char array[B];
    int t;
    short s[A];
    long u;
} str2;

void setVal(str1 *p, str2 *q) {
    long v1 = q->t;
    long v2 = q->u;
    p->y = v1+v2;
}

Gcc generates the following code for setVal:
void setVal(str1 *p, str2 *q)
p in %rdi, q in %rsi
setVal:
    movslq 8(%rsi), %rax
    addq 32(%rsi), %rax
    movq %rax, 184(%rdi)
    ret
What are the values of A and B? (The solution is unique.)
*/

int main() {

    /*
    q->t 对应的是 8(%rsi)，因为 t 是int类型，4字节对齐。所以  4 < B <= 8
    q->u 对应的是 32(%rsi)，u 是 long 类型，8字节对齐，24 < 8 + 4 + 2 * A <= 32，得到 6< A < 10
    4 * A * B 对应 184，y 是 8字节对齐。所以， 44 < A * B <= 46
    最终只有 B = 5， A = 9 符合
    */

    return 0;
}