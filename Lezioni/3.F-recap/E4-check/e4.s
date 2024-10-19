# Scrivere soluzione qui...
.globl check
check:
	pushl %ebx
	pushl %edi
	pushl %esi
	subl $16, %esp
	
	movl 32(%esp), %edi					#edi = a
	movl 36(%esp), %ebx					#ebx = b
	movl %edi, %esi
	addl 40(%esp), %esi
	addl 40(%esp), %esi
	subl $2, %esi
L:
	cmpl %edi, %esi
	jl E1
	movswl (%esi), %eax
	movl %eax, (%esp)
	movsbl (%ebx), %eax
	movl %eax, 4(%esp)
	leal 12(%esp), %eax
	movl %eax, 8(%esp)
	call prod
	cmpl $6, 12(%esp)
	jne E0
	movl $1, %eax
	jmp E2
E0:
	subl $2, %esi
	incl %ebx
	jmp L
E1:
	xorl %eax, %eax
E2:	
	addl $16, %esp
	popl %esi
	popl %edi
	popl %ebx
	ret
