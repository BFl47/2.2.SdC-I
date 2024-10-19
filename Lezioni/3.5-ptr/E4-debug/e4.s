.globl f
f:
    movw 4(%esp), %ax
    xorw %cx, %cx
    movl 8(%esp), %edx
    movw $0, (%edx)
    movl 12(%esp), %edx
    movw $0, (%edx)
L:  
	cmpw %ax, %cx
    ja E
    testw $1, %cx
    jne F
    movl 8(%esp), %edx
    addw %cx, (%edx)
    jmp C  
F:
    movl 12(%esp), %edx
    addw %cx, (%edx)
C:	
	incw %cx
	jmp L
E:
	ret
