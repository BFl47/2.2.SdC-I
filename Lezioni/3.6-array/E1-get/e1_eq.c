short get(short* v, unsigned n, unsigned i) {
	short* c = v;
	unsigned d = i;
	short a;
	
	if (d < n) goto E;
	a = -1;
	goto E2;
E:
    a = c[d];
E2:
	return a;
}
