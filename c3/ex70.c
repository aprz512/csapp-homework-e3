/*
Consider the following union declaration:

    union ele {
        struct {
            long *p;
            long y;
        } e1;

        struct {
            long x;
            union ele *next;
        } e2;
    };

This declaration illustrates that structures can be embedded within unions.
The following function (with some expressions omitted) operates on a linked
list having these unions as list elements:

    void proc (union ele *up) {
        up->p = *(up->next->p) - up->next->y;
    }

A. What are the offsets (in bytes) of the following fields:
e1.p
e1.y
e2.x
e2.next

B. How many total bytes does the structure require?

C. The compiler generates the following assembly code for proc:

void proc (union ele *up)
up in %rdi
proc:
    movq 8(%rdi), %rax      => rax = up.y / up->next
    movq (%rax), %rdx       => rdx = *up.y / *(up->next)  => next 正常
    movq (%rdx), %rdx       => rdx = *(up->next->p)
    subq 8(%rax), %rdx      => *(up->next->p) - up->next->y
    movq %rdx, (%rdi)       => *up.next = *(up.next.p) - up.next.y
    ret
    
On the basis of this information, fill in the missing expressions in the code
for proc. Hint: Some union references can have ambiguous interpretations.
These ambiguities get resolved as you see where the references lead. There
is only one answer that does not perform any casting and does not violate
any type constraints.

*/

union ele
{
    struct
    {
        long *p;
        long y;
    } e1;

    struct
    {
        long x;
        union ele *next;
    } e2;
};

void proc(union ele *up)
{
    up->e2.x = *(up->e2.next->e1.p) - up->e2.next->e1.y;
}

int main()
{

    /*

A. What are the offsets (in bytes) of the following fields:
e1.p        => 0
e1.y        => 8
e2.x        => 0
e2.nextq    => 8

B. How many total bytes does the structure require?
16byte

C. The compiler generates the following assembly code for proc:
    up->e2.x = *(up->e2.next->e1.p) - up->e2.next->e1.y;

    */

    return 0;
}