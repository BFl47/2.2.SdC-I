char* my_strcat(char* dest, const char* src) {
    char* c = dest;
    const char* d = src;
L:    
    if (*c == 0) goto E1;
    c++;
    goto L;
E1:;
	char al = *d;
	*c = al;
    if (*d == 0) goto E2; 
    c++;
    d++;
    goto E1;
    
E2:
    return dest;
}
