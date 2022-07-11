/*
Consider the following source code, where R, S, and T are constants declared with
#define:
long A[R][S][T];

long store_ele(long i, long j, long k, long *dest)
{
    *dest = A[i][j][k];
    return sizeof(A);
}

In compiling this program, gcc generates the following assembly code:
long store_ele(long i, long j, long k, long *dest)
i in %rdi, j in %rsi, k in %rdx, dest in %rcx
store_ele:
    leaq (%rsi,%rsi,2), %rax
    leaq (%rsi,%rax,4), %rax
    movq %rdi, %rsi
    salq $6, %rsi
    addq %rsi, %rdi
    addq %rax, %rdi
    addq %rdi, %rdx
    movq A(,%rdx,8), %rax
    movq %rax, (%rcx)
    movl $3640, %eax
    ret

A. Extend Equation 3.1 from two dimensions to three to provide a formula for
the location of array element A[i][j][k].
B. Use your reverse engineering skills to determine the values of R, S, and T
based on the assembly code.

*/

int main()
{
    // A
    // A[i][j] = A + L(S*i + j);
    // A[i][j][k] = A + L(S * T * i + j * T + k);


    // B
    /*
    leaq (%rsi,%rsi,2), %rax    => rax = 3 * j
    leaq (%rsi,%rax,4), %rax    => rax = 4 * 3 * j + j;
    movq %rdi, %rsi             => rsi = i
    salq $6, %rsi               => rsi = 64 * i
    addq %rsi, %rdi             => rdi = i + 64 * i
    addq %rax, %rdi             => rdi = 13 * j + 65 * i
    addq %rdi, %rdx             => rdx = 13 * j + 65 * i + k
    movq A(,%rdx,8), %rax       => rax = A + 8 * (13 * j + 65 * i + k)
    movq %rax, (%rcx)           => *rcx = rax
    movl $3640, %eax            => eax = 3640
    */
   // L * S * T * i = 8 * 65 * i
   // L * T * j = 8 * 13 * j
   // long 类型。所以 L = 8，T = 13, S = 5
   // R * S * T = 3640 * 8， R = 7


    return 0;
}