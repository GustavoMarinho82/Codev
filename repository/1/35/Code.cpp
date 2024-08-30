#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* Propriedade(int & n) {
	/* insert your code here */
}

int main(){
	int * L, n;
	
	L = Propriedade(n);
	
	printf("[");
	for (int i=0; i<n; i++) {
		if (i>0) printf(", ");
		printf("%d", L[i]);
	}
	printf("]\n");
	free(L);
		
	return 0;
}