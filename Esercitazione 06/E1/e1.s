# Inserisci qui la soluzione...
.globl list_add_first
list_add_first:
	pushl %ebx
	pushl %edi
	subl $4, %esp
	
	movl 16(%esp), %ebx				#**l 	->b1
	movl (%ebx), %edi				#*l 	->b
	movl $8, %eax
	movl %eax, (%esp)
	call malloc
	
	cmpl $0, %eax
	je E
	movl 20(%esp), %edx
	movl %edx, (%eax)
	movl %edi, 4(%eax)
	movl %eax, (%ebx)
	movl $0, %eax
	jmp E2

E:
	movl $-1, %eax
E2:	
	addl $4, %esp
	popl %edi
	popl %ebx
	ret



# elem		+20
# **l		+16
# R			+12
# ebx		+8
# edi		+4
# sizeof	<
