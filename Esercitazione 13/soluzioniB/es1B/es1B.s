# void interleave(const char* a, const char* b, char* c) {
#     do {
#         if (*a) *c++ = *a++;
#         if (*b) *c++ = *b++;
#     } while (*a || *b);
#     *c = '\0';
# }

.globl interleave

interleave:
    pushl %ebx
    movl 8(%esp), %eax
    movl 12(%esp), %ebx
    movl 16(%esp), %ecx
L1: movb (%eax), %dl
    testb %dl, %dl
    jz L2
    movb %dl, (%ecx)
    incl %eax
    incl %ecx
L2: movb (%ebx), %dl
    testb %dl, %dl
    jz L3
    movb %dl, (%ecx)
    incl %ebx
    incl %ecx
L3: cmpb $0, (%eax)
    jne L1
    cmpb $0, (%ebx)
    jne L2  # jne L1 anche corretto, ma meno efficiente
    movb $0, (%ecx)
    popl %ebx
    ret
