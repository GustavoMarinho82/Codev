#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double imposto(int L[], int n){
	/* insert your code here */
}

int main(void){
	int n, i, *L;
	
	while (scanf("%d", &n)>0) {
		L = (int*) calloc(n, sizeof(int));
		
		for (i = 0; i < n; i++) {
			scanf("%d", &L[i]);
		}
		
		printf("%.2f\n", imposto(L, n));
		
		free(L);
	}
	
	return 0;
}