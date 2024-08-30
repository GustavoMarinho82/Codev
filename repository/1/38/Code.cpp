#include <stdio.h>
#include <stdlib.h>

int* PA(int a, int r, int n) {
	/* insert your code here */
}

int main() {
	int i, a, r, n, *resp;
	
	while (scanf("%d %d %d", &a, &r, &n) > 0) {
		resp = PA(a, r, n);
	
		printf("[");
		for (i = 0; i < n; ++i) {
			if (i>0) printf(", ");
			printf("%d", resp[i]);
		}
		printf("]\n");
		free(resp);
	}
	
	return 0;
}