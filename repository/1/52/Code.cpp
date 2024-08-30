#include <stdio.h>
#include <stdlib.h>


double* sistema(double** a, double* b, int N){
	/* insert your code here */
}

int main() {
	int N;
	
	while (scanf("%d", &N)>0) {
		int i, j;
		double **a, *b, *x;
		bool manual = true;
		
		if (N < 1) {
			N = 1000; 
			manual = false;
		} 
		a = AlocarMatriz(N, N);
		b = (double*)calloc(N, sizeof(double));
		if (manual) {
			LerSistema(a, b, N);			
		} else {
			for (i = 0; i < N; i++) {
				b[i] = 1;
				for (j = 0; j < N; j++) {
					a[i][j] = 1;
				}
			}
		}
					
		x = sistema(a, b, N);	
		
		for (i = 0; i < N; i++) {
			if (i>0) printf(" ");
			printf("%.1f", x[i]);
		}
		printf("\n");
		LiberarMatriz(a, N);			
		free(b);
		free(x);
		
	}
	
	return 0;
}