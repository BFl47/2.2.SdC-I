
unsigned count1(unsigned n) {
    unsigned a = 0; // counter
    unsigned c = n;
L:
	if (c <= 0) goto E;
	if ((c & 1) == 0) goto E1;
	a++;
E1:
	c = c >> 1;
    goto L;
E:
    return a;
}
