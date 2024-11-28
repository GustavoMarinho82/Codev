#include <stdio.h>
#include <stdlib.h>

int RaizQuad2(int n, int r){ //O(n)
	if ((r*r <= n) && (n < (r+1)*(r+1))) {
		return r;
	
	} else {
		return RaizQuad2(n, r+1);
	}
}

int RaizQuad(int n) { //O(n)
	// assume n >= 0
	// retorna r tal que r^2 <= n < (r+1)^2
	if (n == 0){
		return 0;
	
	} else {
		return RaizQuad2(n, 1);
	}
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int n; 
	while (scanf("%d", &n)>0) {
		if (n>=0) {
			/* teste manual */
			printf("%d\n", RaizQuad(n));
		} else {
			/* teste automático */
			n = 50000; 
			for (int t=1; t<=200; t++) RaizQuad(n);
			printf("%d\n", RaizQuad(n));
		}
	}

	return 0;
}
