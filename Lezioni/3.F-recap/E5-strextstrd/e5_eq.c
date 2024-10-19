// scrivi soluzione C equivalente qui...
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "e5.h"

char* strextstrd(const char *s, int stride) {
	const char* esi = s;				//esi -> s
	int edi = stride;					//edi -> stride
	
	int ebp = strlen(esi);				//ebp -> n
	int a0 = ebp/edi;
	a0++;
	
	char* eax = malloc(a0);
	char* ebx = eax;

	if (eax == NULL) goto F;
	int c = 0;
L:	
	if (c >= ebp) goto E;
	char d = esi[c];
	*ebx = d;
	ebx++;
	c += edi;
	goto L;
E:
	*ebx = 0;
F:
	return eax;
}


/*
 * stride		+28
 * s			+24
 * R			+20
 * esi			+16
 * edi			+12
 * ebp			+8
 * ebx			+4
 * arg 
*/
