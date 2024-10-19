.globl f
f:
	pushl %ebx			
	pushl %ebp
	pushl %edi
	subl $4, %esp
	
	xorl %ecx, %ecx
	xorl %ebx, %ebx
	movl 24(%esp), %ebp
	movl 20(%esp), %edi
L:
	cmpl %ebp, %ecx
	jae E
	movl (%edi, %ecx, 4), %edx
	movl %edx, (%esp)
	call is_negative
	addl %eax, %ebx
	incl %ecx
	jmp L
E:
	movl %ebx, %eax
	
	addl $4, %esp
	popl %edi
	popl %ebp
	popl %ebx
	ret
