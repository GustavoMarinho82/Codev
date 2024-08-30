#include <stdio.h>
#include <stdlib.h>

int* PG(int a, int q, int n) {
	/* insert your code here */
}

int main() {
	int i, a, q, n, *resp;

	while (scanf("%d %d %d", &a, &q, &n) > 0) {
		resp = PG(a, q, n);
	
		printf("[");
		for (i = 0; i < n; i++) {
			if (i>0) printf(", ");
			printf("%d", resp[i]);
		}
		printf("]\n");
		free(resp);
	}
	
	return 0;
}