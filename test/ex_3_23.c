long dw_loop(long x){
    long y = x * x;
    long *p = &x;
    long n = 2 * x;

    do {
        x += y;
        (*p)++;
        n--;

    } while (n > 0);
    return x;
}


// x in %rdi
dw_loop:
    movq %rdi, %rax    result = x;
    movq %rdi, %rcx     y = x
    imulq %rdi, %rcx    y = y * x
    leaq (%rdi, %rdi), %rdx  n = x + x
.L2:
    leaq 1(%rcx, %rax), %rax result = result + y + 1
    subq $1, %rdx     n = n - 1
    testq %rdx, %rdx 
    jg .L2 n > 0
    rep; ret