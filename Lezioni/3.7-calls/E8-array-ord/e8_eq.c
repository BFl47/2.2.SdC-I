int ordinati(int x, int y);

unsigned f(int *v, unsigned n) {
    unsigned b = 1, bp = n;
    int* di = v;
    int a = 0;
L:	
	if (b >= bp) goto E;
	if (ordinati(di[b-1], di[b]) == 0) goto E1;
	b++;
	goto L;
E:
	a = 1;
E1:	
	return a;
}
