int g(int x);

int f(int x) {
	int a = g(x);
	a++;
	return a;
}
