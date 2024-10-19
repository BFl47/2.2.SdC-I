int between(int x, int y, int z) {
	int a = x;
	int c = y;
	int d = z;
	
	if (a > c) 
		goto F;
	if (c > d)
		goto F;
	a = 1;
	goto E;
	F: a = 0;
	E: return a;
	
}
