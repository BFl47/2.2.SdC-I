# Scrivere soluzione qui...
.globl f

f:
	movl 4(%esp), %eax
	movsbl (%eax), %eax
	movl 8(%esp), %ecx
	movsbl (%ecx), %ecx
	addl %ecx, %eax
	ret
