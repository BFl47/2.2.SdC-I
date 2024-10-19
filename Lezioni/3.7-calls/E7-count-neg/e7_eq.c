int is_negative(int x);

unsigned f(int *v, unsigned n) {
    unsigned c = 0, b = 0, bp = n;
    int* di = v;
    int a;
L:
    if (c >= bp) goto E;
    a = is_negative(di[c]);
	b += a;
	c++;
	goto L;
E:
	a = b;
	return a;
}

