int find(int* v, int n, int x) {
    int d = 0;
    int* c = v;
    int a;
L:	
	if (d >= n) goto E1;
	a = x;
	if (c[d] != a) goto E2;
	a = 1;
	goto E1;
E2:
	a = 0;
	d++;
	goto L;
E1:
	return a;
}
