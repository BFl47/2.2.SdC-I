int sum(int n) {
    int a = 0;
    int c = n;
    L:
		if (c <= 0) goto E;		//c-0 <= 0
		a += c;
		c--;
		goto L;

    E: 
		return a;
}
