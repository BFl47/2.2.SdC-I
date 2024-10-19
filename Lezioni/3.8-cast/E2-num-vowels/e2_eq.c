int is_vowel(char c); // restituisce 0/1

int num_vowels(char *s) {
    int b = 0;
    char* di = s;
L:	
	if (*di == 0) goto E;
	int a = is_vowel(*di);
	b += a;
	di++;
    goto L;
E:
    return b;
}
