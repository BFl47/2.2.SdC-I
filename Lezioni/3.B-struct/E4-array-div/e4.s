# Scrivere la soluzione qui...
.globl array_div
array_div:
	pushl %ebp
	pushl %ebx
	pushl %edi
	pushl %esi

	xorl %ecx, %ecx
	movl 20(%esp), %ebp
	movl 24(%esp), %ebx
	movl 28(%esp), %esi
	
L:
	cmpl 32(%esp), %ecx
	jge E
	movl (%ebp, %ecx, 4), %edx
	movl %edx, %edi
	cmpl (%ebx, %ecx, 4), %edx
	cmovgel (%ebx, %ecx, 4), %edi
	
	movl %edx, %eax
	cmpl (%ebx, %ecx, 4), %edx
	cmovll (%ebx, %ecx, 4), %eax
	
	movl %eax, %edx
	sarl $31, %edx
	idivl %edi
	movl %eax, (%esi)
	movl %edx, 4(%esi)
	
	addl $8, %esi
	incl %ecx
	jmp L
E:	
	popl %esi
	popl %edi
	popl %ebx
	popl %ebp
	ret
