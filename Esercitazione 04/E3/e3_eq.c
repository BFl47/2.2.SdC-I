char my_strcmp(const char* s1, const char* s2) {
	const char* d = s1;
	const char* c = s2;
L:
	if (*d == 0) goto E;
	char a = *d;
	if (a != *c) goto E;
	d++;
	c++;
	goto L;
E:;
	int a1 = *c;
	a1 = -a1;
	a1 += *d;
	return a1;
}
