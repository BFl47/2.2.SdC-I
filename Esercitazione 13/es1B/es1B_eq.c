void interleave(const char* a, const char* b, char* c) {
L:
	if (*a == 0) 
		goto E1;
	char d = *a;
	*c = d;
	c++;
	a++;
E1:	
	if (*b == 0)
		goto E2;
	d = *b;
	*c = d;
	c++;
	b++;
E2:	
	if (*a == 0)
		goto I1;
	goto L;
I1:
	if (*b == 0)
		goto F;
	goto L;
F:
	*c = 0;
}
