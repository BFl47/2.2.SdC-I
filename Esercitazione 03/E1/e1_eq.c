int min(int x, int y, int z) {
	int a = x;
	int c = y;
	int d = z;
	
    if (a >= c) 
    goto E;
    
    if (a >= d) 
    goto F;
    goto G;
        
    E: {
        if (c >= d) 
        goto F;
        a = c;
        goto G;
    }
    F: {
		a = d;
		goto G;
	}
    
    G: return a;
    
}
