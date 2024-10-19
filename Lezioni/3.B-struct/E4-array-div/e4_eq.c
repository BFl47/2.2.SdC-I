/*
 typedef struct {			base
    int quot;				offset	0	|xxxx|
    int rem;				offset	4	|xxxx|
} div_rem_t;				sizeof	8
*/

#include "e4.h"

void array_div(const int *a, const int *b, div_rem_t *res, int n) {
    int c = 0;
    const int* ebp = a;
L:	
	if (c >= n) goto E;
	int d = ebp[c];
	int edi = d;
	if (d >= b[c])
		edi = b[c];
		
	int a1 = d;
	if (d < b[c])
		a1 = b[c];
		
    int d1 = a1;
    d1 = d1 >> 31;
    int a2 = a1 / edi;
    d1 = a1 % edi;
    res[c].quot = a2;
    res[c].rem = d1;
    c++;
    goto L;
E:
	return;
}
