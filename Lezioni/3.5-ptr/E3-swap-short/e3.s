
.globl swap

swap:
	movl 4(%esp), %eax
	movl 8(%esp), %ecx
	
	movw (%eax), %ax
	movw (%ecx), %cx
	
	movl 4(%esp), %edx
	movw %cx, (%edx)
	movl 8(%esp), %edx
	movw %ax, (%edx)
	
	ret
