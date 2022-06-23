	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 1	sdk_version 11, 1
	.globl	_get                    ## -- Begin function get
	.p2align	4, 0x90
_get:                                   ## @get
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%rbx
	pushq	%rax
	.cfi_offset %rbx, -24
	movq	%rdi, %rbx
	leaq	L_.str(%rip), %rdi
	movq	%rbx, %rsi
	xorl	%eax, %eax
	callq	_printf
	movw	$1027, (%rbx)           ## imm = 0x403
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_put                    ## -- Begin function put
	.p2align	4, 0x90
_put:                                   ## @put
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%rbx
	pushq	%rax
	.cfi_offset %rbx, -24
	movq	%rdi, %rbx
	leaq	L_.str.1(%rip), %rdi
	movq	%rbx, %rsi
	xorl	%eax, %eax
	callq	_printf
	movw	$1541, (%rbx)           ## imm = 0x605
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%rbx
	pushq	%rax
	.cfi_offset %rbx, -24
	leaq	L_.str.2(%rip), %rdi
	leaq	-10(%rbp), %rbx
	movq	%rbx, %rsi
	xorl	%eax, %eax
	callq	_printf
	movw	$513, -10(%rbp)         ## imm = 0x201
	movq	%rbx, %rdi
	callq	_get
	movq	%rbx, %rdi
	callq	_put
	movsbl	-10(%rbp), %esi
	leaq	L_.str.3(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	movsbl	-9(%rbp), %esi
	leaq	L_.str.4(%rip), %rdi
	xorl	%eax, %eax
	callq	_printf
	xorl	%eax, %eax
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"get a addr = %x\n"

L_.str.1:                               ## @.str.1
	.asciz	"put a addr = %x\n"

L_.str.2:                               ## @.str.2
	.asciz	"main a addr = %x\n"

L_.str.3:                               ## @.str.3
	.asciz	"a[0] = %d\n"

L_.str.4:                               ## @.str.4
	.asciz	"a[1] = %d\n"

.subsections_via_symbols
