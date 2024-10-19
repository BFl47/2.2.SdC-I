int fib(int n) {
	int b = n;
	if (b >= 2) goto E;
    int a = 1;
    return a;
E:
	b--;
	int di = fib(b);
	b--;
	int bp = fib(b);
    return di + bp;
}
