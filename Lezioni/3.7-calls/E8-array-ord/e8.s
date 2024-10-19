.globl f
f:
	pushl %ebx
	pushl %ebp
	pushl %edi
	subl $8, %esp
	
	movl $1, %ebx
	movl 28(%esp), %ebp
	movl 24(%esp), %edi
L:
	cmpl %ebp, %ebx
	jae E
	movl (%edi, %ebx, 4), %eax
	movl %eax, 4(%esp)
	decl %ebx
	movl (%edi, %ebx, 4), %eax
	movl %eax, (%esp)
	incl %ebx
	call ordinati
	cmpl $0, %eax
	je F
	incl %ebx
	jmp L
E:
	movl $1, %eax
F:
	addl $8, %esp
	popl %edi
	popl %ebp
	popl %ebx
	ret
