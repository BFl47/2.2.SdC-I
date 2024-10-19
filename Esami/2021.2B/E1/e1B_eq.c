#include "e1B.h"

unsigned int adler32_simplified(unsigned char* data, int len)
{
    unsigned int a = 1, b = 0;
    int ecx = 0;
    unsigned char* esi = data;
L:
	if (ecx >= len) 
		goto E;
	
	int edx = esi[ecx];
	a = a + edx;
	a = a & 0xFFFF;
    b = (b + a);
    b = b & 0xFFFF;
    
    ecx++;
    goto L;
E:	
	b = b << 16;
	a = a | b;
    return a;
}


// index	-> ecx
//	b		-> ebx
//	data    -> esi
