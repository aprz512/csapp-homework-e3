/*
You are charged with maintaining a large C program, and you come across the
following code:

typedef struct {
    int first;
    a_struct a[CNT];
    int last;
} b_struct;


void test(long i, b_struct *bp)
{
    int n = bp->first + bp->last;

    // 4 + a_struct.size * i
    a_struct *ap = &bp->a[i];

    // 4 + a_struct.size * i + align + x.size * ap->idx
    ap->x[ap->idx] = n;
}

The declarations of the compile-time constant CNT and the structure a_struct
are in a file for which you do not have the necessary access privilege. Fortunately,
you have a copy of the .o version of code, which you are able to disassemble with
the objdump program, yielding the following disassembly:

void test(long i, b_struct *bp)
i in %rdi, bp in %rsi
0000000000000000 <test>:
0: 8b 8e 20 01 00 00        mov 0x120(%rsi),%ecx            => ecx = 0x120 + rsi   => bp.last
6: 03 0e                    add (%rsi),%ecx                 => ecx = ecx + *rsi     => bp.last + bp.first
8: 48 8d 04 bf              lea (%rdi,%rdi,4),%rax          => rax = 5 * rdi
c: 48 8d 04 c6              lea (%rsi,%rax,8),%rax          => rax = 40 * rdi + rsi
10: 48 8b 50 08             mov 0x8(%rax),%rdx              => rdx = 40 * rdi + rsi + 8 => a_struct的大小是 40，8字节对齐，rdx 就是 ap
14: 48 63 c9                movslq %ecx,%rcx                => rcx = ecx
17: 48 89 4c d0 10          mov %rcx,0x10(%rax,%rdx,8)      => [8 * rdx + rax + 0x10] = rcx => 直接用 ap * 8，说明 ap 此时应该表示的是第一个元素
1c: c3                      retq

Using your reverse engineering skills, deduce the following:
A. The value of CNT.
B. A complete declaration of structure a_struct. Assume that the only fields
in this structure are idx and x, and that both of these contain signed values.
*/

int main() {
    // 0x120 => 288
    // mov 0x8(%rax),%rdx  这个行指令，rdx 表示的是 ap，a_struct的大小是 40
    // ap->idx 应该是 a_struct 的第一个元素，所以直接用 ap 表示，rdx * 8 是计算数组大小，所以 idx 是一个 long 类型
    // ap->x 不是第一个元素，rax + 0x10，应该拆成 rax+0x8 + 0x8，rax + 0x8 表示 ap，即为  ap + 0x8
    // 汇编的 movslq %ecx,%rcx 将 int 转 long，所以 ap->x 是一个 long 数组
    /*
        a_struct
        typedef struct {
            long idx,
            long x[4]
        } a_struct
  */
    return 0;
}