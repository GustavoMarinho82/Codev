#include <stdio.h>
#include <stdlib.h>


int RaizQuad(int n) {
	// assume n >= 0
	// retorna ⌊√(n)⌋
	/* insert your code here */
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