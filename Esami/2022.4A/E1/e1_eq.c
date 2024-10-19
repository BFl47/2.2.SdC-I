#include "e1A.h"

int crc32(char *bytes, int n) {
    int c = 0xFFFFFFFF; // valore iniziale
    int d = 0;
    char* esi = bytes;
L:
	if (d >= n)
		goto E;
	char a = esi[d];
	int eax = a; // attenzione!
	c = c ^ a;
	int b = 0;
L1:
	if (b >= 8) 
		goto E1;
	
	eax = c & 1;
	eax = -eax; // operazione: neg
	c = (c >> 1) ^ (0xEDB88320 & eax);
	b++;
	goto L1;
E1:    
    d++;
    goto L;
E:
	c = ~c;
	eax = c;
    return eax; // operazione: not
}



// crc  	-> c
// i		-> d
// j		-> b
// bytes	-> esi
