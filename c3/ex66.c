/*
Consider the following source code, where NR and NC are macro expressions declared 
with #define that compute the dimensions of array A in terms of parameter n. 
This code computes the sum of the elements of column j of the array.

long sum_col(long n, long A[NR(n)][NC(n)], long j) {
    long i;
    long result = 0;
    for (i = 0; i < NR(n); i++)
        result += A[i][j];
    return result;
}

In compiling this program, gcc generates the following assembly code:

long sum_col(long n, long A[NR(n)][NC(n)], long j)
n in %rdi, A in %rsi, j in %rdx
sum_col:
    leaq 1(,%rdi,4), %r8
    leaq (%rdi,%rdi,2), %rax
    movq %rax, %rdi
    testq %rax, %rax
    jle .L4
    salq $3, %r8
    leaq (%rsi,%rdx,8), %rcx
    movl $0, %eax
    movl $0, %edx
.L3:
    addq (%rcx), %rax
    addq $1, %rdx
    addq %r8, %rcx
    cmpq %rdi, %rdx
    jne .L3
    rep; ret
.L4:
    movl $0, %eax
    ret

Use your reverse engineering skills to determine the definitions of NR and NC.



*/

int main() {

/*
long sum_col(long n, long A[NR(n)][NC(n)], long j)
n in %rdi, A in %rsi, j in %rdx
sum_col:
    leaq 1(,%rdi,4), %r8        => r8 = 4 * rdi + 1
    leaq (%rdi,%rdi,2), %rax    => rax = 3 * rdi
    movq %rax, %rdi             => rdi = rax
    testq %rax, %rax            => rax : 0
    jle .L4                     => 小于等于跳转 L4
    salq $3, %r8                => r8 = r8 * 8
    leaq (%rsi,%rdx,8), %rcx    => rcx = 8 * rdx + A
    movl $0, %eax               => eax = 0
    movl $0, %edx               => edx = 0
.L3:
    addq (%rcx), %rax           => rax = *rcx
    addq $1, %rdx               => rdx += 1
    addq %r8, %rcx              => rcx += r8
    cmpq %rdi, %rdx             => rdi : rdx
    jne .L3                     => !=
    rep; ret
.L4:
    movl $0, %eax               => eax = 0
    ret
*/

    // 看 L3 是循环内容，rcx 是 A[i][j]
    // r8 是每次的差值，就是 NC(n)
    // rdi 是 NR(n)
    // rdx 是 i

    // NC(n) = 4 * n + 1
    // NR(n) = 3 * n
    return 0;
}