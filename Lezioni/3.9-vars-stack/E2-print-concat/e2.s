# Scrivere soluzione qui...
.globl print_concat
print_concat:
	pushl %ebx						#n
	pushl %edi						#i
	pushl %ebp						#s
	pushl %esi						#buf
	subl $520, %esp
	
	leal 8(%esp), %esi
	movl $0, (%esi)
	
	xorl %edi, %edi
	movl 544(%esp), %ebx
	movl 540(%esp), %ebp
L:
	cmpl %ebx, %edi
	jge E
	movl %esi, (%esp)
	movl (%ebp, %edi, 4), %eax
	movl %eax , 4(%esp)
	call strcat
	incl %edi
	jmp L
E:
	movl %esi, (%esp)
	call puts
	addl $520, %esp
	popl %esi
	popl %ebp
	popl %edi
	popl %ebx
	ret
