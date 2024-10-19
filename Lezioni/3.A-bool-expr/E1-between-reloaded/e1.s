# Scrivi la soluzione qui...

# return ax < cx < dx
# return x <= y && y <= z;

.globl between
between:
	movw 4(%esp), %ax		#x
	movw 8(%esp), %cx		#y
	movw 12(%esp), %dx		#z
	
	cmpw %cx, %ax
	setle %al
	cmpw %dx, %cx
	setle %ah
	andb %ah, %al
	movzbl %al, %eax
	ret
