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
	movq	8(%rdi), %rax
	movq	(%rax), %rax
	movq	%rax, (%rsi)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
