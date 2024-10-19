void array_set(short* v, int n, short c) {
    short* p = v + n - 1;
    while (p >= v) {
        *p-- = c;
    }
}
