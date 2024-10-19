unsigned my_strlen(const char* s) {
    unsigned a = 0;
    const char* c = s;
    
L:    
    if (*c == 0) goto E;
    a++;
    c++;
    goto L;
E:
    return a;
}
