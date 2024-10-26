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

void Subtrai(int A[], int n, int B[], int m, int R[], int &k) { //Considera que A >= B
	Inverter(A, n); Inverter(B, m);
	
	int debito = 0;

	for(k = 0; k<n; k++){ //O~(n)
		R[k] = A[k] - debito; 
		debito = 0;
		
		if(k < m)
			R[k] -= B[k];
		
		if(R[k] < 0){
			R[k] += 10;
			debito = 1;
		}
	}

	for(int i=k-1; i>=0; i--){ //O(n)
		if(R[i] == 0)
			k--;
		else
			break;
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
		Subtrai(A, n, B, m, R, k);  Imprime(R, k);
	}
	free(A); free(B); free(R);
}