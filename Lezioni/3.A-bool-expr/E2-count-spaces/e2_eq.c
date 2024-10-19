
int count_spaces(const char* s) {
    int a = 0;
    const char* d = s;
L:	
	if (*d == 0) goto E;
	int c = *d == 32;
	a += c;
	d++;
	goto L;
E:
	return a;
}
