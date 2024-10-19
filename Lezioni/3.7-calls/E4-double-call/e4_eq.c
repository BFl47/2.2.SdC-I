int g();
int h();
        
int f() {
    int a = g();
    int b = a;
    a = h();
    a += b;
    return a;
}
