// Scrivi la soluzione qui...
.globl stringa_vuota

stringa_vuota:
	xorl %eax, %eax
	movl 4(%esp), %ecx
	cmpl $0, %ecx
	je E
	cmpl $0, (%ecx)
	jne E
	movl $1, %eax
E:
	ret
