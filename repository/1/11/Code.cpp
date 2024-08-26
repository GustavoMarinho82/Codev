#include <stdio.h>
#include <stdlib.h>

void Imprime(int R[], int k) {
	for (int i=0; i<k; i++) {
		printf("%d ", R[i]);
	}
	printf("\n");
}


void Soma(int A[], int n, int B[], int m, int R[], int &k) {
	/* insert your code here */
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