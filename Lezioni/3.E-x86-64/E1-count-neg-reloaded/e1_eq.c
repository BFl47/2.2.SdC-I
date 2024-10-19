int is_negative(int x);

unsigned f(int *v, unsigned n) {
    unsigned r14 = 0, r15 = 0;
    int* r12 = v;
	unsigned r13 = n;
L:
	if (r14 >= r13) goto E;
	int a = is_negative(r12[r14]);
	r15 += a;
    r14++;
    goto L;
E:
	a = r15;
    return a;
}
