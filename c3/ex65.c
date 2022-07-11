/*
The following code transposes the elements of an M × M array, where M is a
constant defined by #define:

void transpose(long A[M][M]) {
    long i, j;
    for (i = 0; i < M; i++)
        for (j = 0; j < i; j++) {
            long t = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = t;
        }
}

When compiled with optimization level -O1, gcc generates the following code
for the inner loop of the function:

1 .L6:
2 movq (%rdx), %rcx
3 movq (%rax), %rsi
4 movq %rsi, (%rdx)
5 movq %rcx, (%rax)
6 addq $8, %rdx
7 addq $120, %rax
8 cmpq %rdi, %rax
9 jne .L6

We can see that gcc has converted the array indexing to pointer code.
A. Which register holds a pointer to array element A[i][j]?
B. Which register holds a pointer to array element A[j][i]?
C. What is the value of M?
*/

int main() {

/*
.L6:
movq (%rdx), %rcx       => rcx = *rdx
movq (%rax), %rsi       => rsi = *rax
movq %rsi, (%rdx)       => *rdx = rsi
movq %rcx, (%rax)       => *rax = rcx
addq $8, %rdx           => rdx = rax + 8
addq $120, %rax         => rax = 120 + rax
cmpq %rdi, %rax         => rdi : rax
jne .L6                 => != 
*/

    // 内层循环 j++
    // rax 每次加 8 ，符合A[i][j]
    // rdx 每次加 120，符合A[j][i]
    // 8 * M = 120 , M = 15
    return 0;
}