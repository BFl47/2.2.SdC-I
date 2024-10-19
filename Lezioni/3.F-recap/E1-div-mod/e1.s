# Scrivere soluzione qui...
.globl div_mod
div_mod:
	pushl %ebx				#4
	pushl %edi				#8

	movl 12(%esp), %eax		#x
	movl 16(%esp), %ebx		#y
	movl 20(%esp), %ecx		#q
	movl 24(%esp), %edi		#r
	
	movl %eax, %edx
	sarl $31, %edx
	idiv %ebx
	
	movl %eax, (%ecx)
	movl %edx, (%edi)
	
	popl %edi
	popl %ebx
	ret
