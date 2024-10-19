short sum(short* v, int n) {
    short* d = v;
    short a = 0;
    int c = 0;
L:    
    if (c >= n) goto E;
    a = a + d[c];
    c++;
    goto L;
E:
    return a;
}
