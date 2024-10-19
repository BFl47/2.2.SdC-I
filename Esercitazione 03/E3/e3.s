
.globl comp

comp:
	movl 4(%esp), %eax
	movl 8(%esp), %ecx
	movl (%eax), %eax
	movl (%ecx), %ecx
	subl %ecx, %eax
	ret
