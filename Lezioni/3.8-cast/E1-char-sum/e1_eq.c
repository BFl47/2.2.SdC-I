int f(char *p, char *q) {
	char* a = p;
	int a1 = *a;
	char* c = q;
	int c1 = *c;
	a1 += c1;
	return a1;
}
