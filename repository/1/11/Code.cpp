#include <stdio.h>
#include <stdlib.h>

void Imprime(int R[], int k) {
	for (int i=0; i<k; i++) {
		printf("%d ", R[i]);
	}
	printf("\n");
}

void Inverter(int V[], int k){ //k = tamanho do vetor
	for(int i=0; i<(k/2); i++){
		int aux = V[i];
		V[i] = V[k-i-1];
		V[k-i-1] = aux;
	}
}

void Soma(int A[], int n, int B[], int m, int R[], int &k) {
	Inverter(A, n); Inverter(B, m);
	
	k = 0;
	int sobra = 0;

	while(k < n || k < m || sobra == 1){
		R[k] = sobra;
		sobra = 0;
		
		if(k < n)
			R[k] += A[k];
		
		if(k < m)
			R[k] += B[k];
		
		if(R[k] >= 10){
			R[k] -= 10;
			sobra = 1;
		}
		
		k++;
	}

	Inverter(A, n); Inverter(B, m); Inverter(R, k);
}

int main() {
	int n, m; 
	
	int * A, * B, *R; int k;
	A = (int *) malloc(sizeof(int)*1000);
	B = (int *) malloc(sizeof(int)*1000);
	R = (int *) malloc(sizeof(int)*1000*1000);
	while (scanf("%d %d", &n, &m)>0) {
		for (int i=0; i<n; i++) {
			scanf("%d", &A[i]);
		}
		for (int i=0; i<m; i++) {
			scanf("%d", &B[i]);
		}
		
		Soma(A, n, B, m, R, k);  Imprime(R, k);
	}
	free(A); free(B); free(R);
}