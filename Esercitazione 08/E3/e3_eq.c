int count_digits(const char *s) {
    int a = 0;
    const char *c = s;
L:
	if (*c == 0) 
		goto F;
	if (*c < '0') 
		goto E;
	if (*c > '9')
		goto E;
	a++;
E:
	c++;
	goto L;
F:
    return a;
}
