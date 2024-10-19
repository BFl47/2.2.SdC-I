int is_negative(int x);
int is_negative2(char x);

unsigned f(int *v, unsigned n) {
    unsigned r14 = 0, r15 = 0;
    int* r12 = v;
	unsigned r13 = n;
L:
	if (r14 >= r13) goto E;
	char c = (char) r12[r14];
	int a = is_negative2(c);
	r15 += a;
    r14++;
    goto L;
E:
	a = r15;
    return a;
}
