// Scrivere il C equivalente qui...
int lcm(int x, int y) {
	int c = x;				//x			c
	int b = y;				//y			b
    int esi = b;			//greater	esi
    int d, a;
    
    if (c > b)
        esi = c;
L:
	a = esi;
	d = a;
	d = d >> 31;
	d = a % c;
	if (d != 0) goto E;
	
	a = esi;
	d = a;
	d = d >> 31;
	d = a % b;
	
	if (d != 0) goto E;
	return esi;
E:
	esi++;
	goto L;
}
