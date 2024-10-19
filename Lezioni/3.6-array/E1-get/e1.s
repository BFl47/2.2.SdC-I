.globl get

get:
	movl 4(%esp), %ecx
	movl 12(%esp), %edx
	
	cmpl 8(%esp), %edx
	jb E
	movw $-1, %ax
	jmp E2
E:
	movw (%ecx, %edx, 2), %ax
E2:
	ret
