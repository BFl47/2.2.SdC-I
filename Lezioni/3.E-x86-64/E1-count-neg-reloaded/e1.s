.globl f
f:
	pushq %r12
	pushq %r13
	pushq %r14
	pushq %r15
	subq $4, %rsp
	
	movq %rdi, %r12			#v
	movq %rsi, %r13			#n
	xorq %r14, %r14			#i = 0
	xorq %r15, %r15			#cnt = 0
L:
	cmpq %r13, %r14
	jae E
	movl (%r12, %r14, 4), %edi
	call is_negative
	addl %eax, %r15d
	incq %r14
	jmp L
E:
	movl %r15d, %eax	
	addq $4, %rsp
	popq %r15
	popq %r14
	popq %r13
	popq %r12
	ret
