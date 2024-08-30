#include <stdio.h>
#include <stdlib.h>

void notas(int M[], int N[], int n, int Maiores[], int & r, int Menores[], int & s) {
	// escrever em r o número de matrículas com as maiores notas
	// escrever em s o número de matrículas com as maiores notas
	// escrever em Maiores[0..r-1] as matrículas das maiores notas
	// escrever em Menores[0..s-1] as matrículas das menores notas
	/* insert your code here */
}

int main() {
	int n, i, *M, *N, *Ma, *Me;
	
	while (scanf("%d", &n)>0) {
		bool manual = true;
		if (n<=0) {
			n = 1000000; manual = false;
		}

		M = (int*) calloc(n, sizeof(int));
		N = (int*) calloc(n, sizeof(int));
		Ma = (int*) calloc(n, sizeof(int));
		Me = (int*) calloc(n, sizeof(int));
		int nMa, nMe;
		
		if (manual) {
			for (i = 0; i < n; i++) {
				scanf("%d", &M[i]);
			}
				
			for (i = 0; i < n; i++) {
				scanf("%d", &N[i]);
			}
		} else {
			for (i = 0; i < n; i++) {
				M[i] = i;
				N[i] = 2;
			}
			N[n-2] = 1; N[n-1] = 3;
		}
		
		notas(M, N, n, Ma, nMa, Me, nMe);
		
		printf("([");
		for (i = 0; i < nMa; i++) {
			if (i>0) printf(", ");
			printf("%d", Ma[i]);
		}
		printf("], [");
		for (i = 0; i < nMe; i++) {
			if (i>0) printf(", ");
			printf("%d", Me[i]);
		}
		printf("])\n");
		
		free(M); free(N); free(Ma); free(Me);
	}
	
	return 0;
}