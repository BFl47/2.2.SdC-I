# Scrivi la soluzione qui
.globl strextstrd
strextstrd:
	pushl %esi
	pushl %edi
	pushl %ebp
	pushl %ebx
	subl $4, %esp
	
	movl 24(%esp), %esi
	movl 28(%esp), %edi
	
	movl %esi, (%esp)
	call strlen
	movl %eax, %ebp
	
	xorl %edx, %edx
	idivl %edi
	incl %eax
	
	movl %eax, (%esp)
	call malloc
	movl %eax, %ebx
	
	cmpl $0, %eax
	je F
	xorl %ecx, %ecx
L:
	cmpl %ebp, %ecx
	jge E
	movb (%esi, %ecx), %dl
	movb %dl, (%ebx)
	incl %ebx
	addl %edi, %ecx
	jmp L
E:
	movl $0, (%ebx)
F:
	addl $4, %esp
	popl %ebx
	popl %ebp
	popl %edi
	popl %esi
	ret
