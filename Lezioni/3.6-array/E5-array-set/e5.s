.globl array_set

array_set:
	movl 4(%esp), %eax
	addl 8(%esp), %eax
	addl 8(%esp), %eax
	subl $2, %eax
L:
	cmpl 4(%esp), %eax
	jl E
	movw 12(%esp), %dx
	movw %dx, (%eax)
	subl $2, %eax
	jmp L
E:
	ret
