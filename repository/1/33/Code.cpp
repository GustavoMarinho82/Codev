#include <stdio.h>
#include <stdlib.h>

double troco(int M[], int Q[], int n) {
	/* insert your code here */
}

int main(){
	int n, i;
	int *M, *Q;
	
	while (scanf("%d", &n) > 0) {
		M = (int*) calloc(n, sizeof(int));
		Q = (int*) calloc(n, sizeof(int));
		
		for (i = 0; i < n; i++) { 
			scanf("%d", &M[i]);
		}
		
		for (i = 0; i < n; i++) {
			scanf("%d", &Q[i]);
		}
		
		printf("%.2f\n", troco(M, Q, n));
		
		free(M);
		free(Q);
	}
	
	return 0;
}