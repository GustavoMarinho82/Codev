#include <stdio.h>
#include <stdlib.h>

long long int CalculaSoma(int n, int m[], int k) {
	/* m = [a1, a2, ..., ak] */
	
	/* insert your code here */
}

int main() {
	int n; int k; 
	int * m;
	while (scanf("%d %d", &n, &k)>0) {
		m = (int *) malloc(sizeof(int)*n);
		for (int i=0; i<k; i++) {
			scanf("%d", &m[i]);
		}
		printf("%lld\n", CalculaSoma(n, m, k));
		free(m);
	}
}