// Scrivere la soluzione qui...

int esce(int i, int j, int w, int h) {
	if (i-2 < 0 || j-2 < 0 || i+2 > h || j+2 > w)
		return 1;
	return 0;
}

int media(int i, int j, unsigned char* in, int w, int h) {
	int ris = 0;
	for (int r = i-2; r <= i+2; r++) {
		for (int c = j-2; c <= j+2; c++) 
			ris += in[r*w + c];
	}
	ris /= 25;
	return ris;
}
	
void blur5(unsigned char* in, unsigned char* out, int w, int h) {
	for (int i = 0; i <= h; i++) {
		for (int j = 0; j <= w; j++) {
			if (esce(i, j, w, h)) 
				out[i*w + j] = in[i*w + j];
			
			else 
				out[i*w + j] = media(i, j, in, w, h);	
		}
	}
	
}
