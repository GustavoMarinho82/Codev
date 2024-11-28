#include <stdio.h>
#include <stdlib.h>

long long int Bin(int n, int k) { //O~(k)
	// assume n >= k >= 0
	// retorna binomial de n,k = n! / (k! (n-k)!)
	if (k == 0){
		return 1;
		
	} else {
		return n * Bin(n-1, k-1) / k;
		/* Equivalente à [ n/k * Bin(n-1, k-1) ], mas a divisão tem que ser feita após
		 * a multiplicação. Porque o n/k pode gerar um decimal, que será convertido 
		 * para inteiro, assim podendo perder parte do seu valor. */ 
	}
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int n; int k; 
	while (scanf("%d %d", &n, &k)>0) {
		if (n>=0) {
			/* teste manual */
			printf("%lld\n", Bin(n,k));
		} else {
			/* teste automático */
			n = 50000; k = 49999;
			for (int t=1; t<=200; t++) Bin(n,k);
			printf("%lld\n", Bin(n,k));
		}
	}

	return 0;
}
