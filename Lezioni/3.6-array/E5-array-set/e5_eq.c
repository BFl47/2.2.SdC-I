void array_set(short* v, int n, short c) {
	short* a = v;
	a = a + n;
	a--;
L:   
    if (a < v) goto E;
    //*a = c;
	short d = c;
	*a = d;
    a--;
	goto L;
E:
	return;
}
