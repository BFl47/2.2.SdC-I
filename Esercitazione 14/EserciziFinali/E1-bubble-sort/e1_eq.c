#include "e1.h"

void bubble_sort(short *v, unsigned n) {
    unsigned edi;
    short* esi = v;
L:
    edi = 0;
	unsigned ebx = 1;
L1:
    if (ebx >= n)
		goto E;
	short d = esi[ebx];
	if (esi[ebx-1] <= d)
		goto E1;
	swap(&esi[ebx-1], &esi[ebx]);
    edi = 1;
E1:
    ebx++; 
    goto L1;
E:
    if (edi == 1)
		goto L;
}


//again -> edi
//i		-> ebx
//v		-> esi
