void swap(char* x, char* y) {
	char* a = x;
	char* c = y;
	char dl = *a;
	char dh = *c;
	*a = dh;
	*c = dl;
	return;    
}
