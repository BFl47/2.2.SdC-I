int g(int);
int h(int);
        
int f(int x) {
	int b = x;
	int a = g(b);
	int bp = a;
	a = h(b);
	a += bp;
	return a;
}
