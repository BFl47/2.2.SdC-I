
.globl f

f:
	movl 4(%esp), %eax	#int a = x
	incl %eax			#a++
	ret					#return
