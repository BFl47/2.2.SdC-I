int g(int x);

int f(int x) {
    int ebx = 1, ebp = 2;
    int c = x;
    c++;
    int a = g(c);
    a += ebx;
    a += ebp;
    return a;
}
