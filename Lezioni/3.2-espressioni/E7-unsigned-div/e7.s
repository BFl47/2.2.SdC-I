
.globl f

f:
	movl 4(%esp), %eax			#int a = x
	#molv $0, %edx
	xorl %edx, %edx				#int d = 0
	divl 8(%esp)				#a = a/y
	ret							#return a
