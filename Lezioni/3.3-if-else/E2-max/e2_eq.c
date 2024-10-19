int max(int x, int y) {
	int a = x;
	int c = y;
	if (a <= c) goto F;
	goto E;
	F: 
		a = c;
    E: 
		return a;
    
}
