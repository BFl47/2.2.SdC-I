# Scrivere la soluzione qui...
.globl lcm
lcm:
	pushl %ebx		#4
	pushl %esi		#8
	
	movl 12(%esp), %ecx
	movl 16(%esp), %ebx
	movl %ebx, %esi
	
	cmpl %ebx, %ecx
	cmovgl %ecx, %esi
L:
	movl %esi, %eax
	movl %eax, %edx
	sarl $31, %edx
	idiv %ecx
	
	cmpl $0, %edx
	jne E
	
	movl %esi, %eax
	movl %eax, %edx
	sarl $31, %edx
	idiv %ebx
	
	cmpl $0, %edx
	jne E
	jmp Z
E:
	incl %esi
	jmp L
Z:
	movl %esi, %eax	
	popl %esi
	popl %ebx
	ret
