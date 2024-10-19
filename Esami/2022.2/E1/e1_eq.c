#include "e1A.h"

unsigned int* div_vectors(unsigned int* a, unsigned int* b, int n) {
    if (a == NULL)
		return NULL;			//goto Z
    if (b == NULL)
		return NULL;
	if (n == 0)
        return NULL;
    int c = n;
    c = c*4;
    unsigned int* eax = malloc(c);
    unsigned int* ebx = eax;
    
    unsigned int* esi = a;
    unsigned int* edi = b;
    c = 0;
    
L:
	if (c >= n) 
		goto E;
	unsigned int a1 = esi[c];
	unsigned int d = a1;
	d = d >> 31;			   //shrl
	unsigned int ebp = edi[c];
	d = a1 % ebp;
	a1 = a1 / ebp;
	
    ebx[c] = a1;  // usare idiv, attenzione a edx!
    
    c++;
    goto L;
E:
	eax = ebx;
    return eax;
}


// out 		-> ebx
// i		-> c
// a		-> esi
// b		-> edi
// b[i]		-> ebp 
