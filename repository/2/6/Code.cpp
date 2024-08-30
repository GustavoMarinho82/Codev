#include <stdio.h>
#include <stdlib.h>

int Maior(int A[], int n) {
	/* insert your code here */
}

int main() {
	int n; 
	int * A;
	while (scanf("%d", &n)>0) {
		A = (int *) malloc(sizeof(int)*n);
		for (int i=0; i<n; i++) {
			scanf("%d", &A[i]);
		} 
		printf("%d\n", Maior(A, n));
		free(A);
	}
}