// Scrivere C equivalente qui...
int prod(short x, char y, int * res);

int check(short* a, char* b, unsigned n) {
	short* edi = a;
	char* ebx = b;
	short* esi = edi;			//pa
	esi += n;
	esi--;
	int a1 = 1;
L:
	if (esi < edi) goto E1;
    short dx = *esi;
    char dl = *ebx;
    int res;
    prod(dx, dl, &res);
    if (res != 6) goto E0;
    a1 = 1;
    goto E2;
E0:
	esi--;
	ebx++;
	goto L;
E1:
	a1 = 0;
E2:
    return a1;
}

/*
 * n						+40			
 * b						+36
 * a						+32
 * R						+28
 * ebx				b		+24
 * edi				a		+20
 * esi				pa		+16	
 * res						+12
 * &res						+8
 * *ebx				*b		+4
 * *esi				*pa		
*/ 
