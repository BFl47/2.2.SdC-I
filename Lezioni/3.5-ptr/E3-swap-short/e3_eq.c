void swap(short* x, short* y) {
	short* a = x;
	short* c = y;
	
	short ax = *a;
	short cx = *c;
	
	short* d = x;
	*d = cx;
	d = y;
	*d = ax;
    
}
