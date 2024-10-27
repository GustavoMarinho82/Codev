#include <stdio.h>
#include <stdlib.h>

long long int CalculaSoma(int n, int m[], int k) {
	/* m = [a1, a2, ..., ak] */
	
	long long int s = 0;
	for (int i = 1; i <= n; i++) {
		bool somar = false;
		for (int j=0; j<k; j++) {
			if (i%m[j] == 0) {
				somar = true; break;
			}
		}
		if (somar) {
			s += i;
		}
	}
	return s;
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