#include <stdio.h>
#include <stdlib.h>

int RaizQuad2(int n, int i, int f){ //O(log n)
	/* Essa função é como uma busca binária recursiva. 
	 * Inicialmente ela busca a raiz de n no período entre [0, n+1] 
	 * Se o (meio do período)^2 é menor ou igual à raiz, o meio é o novo início, senão o meio é o novo fim.
	 * Isso acontece até que ((início+1) == fim), então a função retorna (início+1), que é o piso da raíz de n. */
	if (i+1 == f){
		return i;
		
	} else {
		long long int m = (i+f)/2;
		
		if (m*m <= n){
			return RaizQuad2(n, m, f);
			
		} else {
			return RaizQuad2(n, i, m);
		}
	}
}

int RaizQuad(int n) { //O(log n)
	// assume n >= 0
	// retorna ⌊√(n)⌋
	
	return RaizQuad2(n, 0, n+1);
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
