#include "e1.h"

int binsearch(int *v, int n, int x) {
	int* esi = v;		//esi = v
	int c = 0;			//c = i
	int d = n;			//d = j
	int b = x;			//b = x
	int a = 0;
L:
	if (c >= d) 
		goto F;
    c = c + d;
    c = c >> 1;
    if (esi[c] != b) 
		goto E;
	a = 1;
	goto F;
E:
    if (esi[c] <= b) 
		goto E1;
	d = c;
	goto L;
E1:
	c++;
	goto L;
F:	
    return a;
}
