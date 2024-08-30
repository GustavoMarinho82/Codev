#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double polinomio(int N, double a[], int k) {
	/* insert your code here */
}

int main() {
	int N, k;
	double *a;
	
	while (scanf("%d", &N)>0) {
		bool manual = true;
		int i;

		if (N < 0) {
			N = 100000; manual = false;
		}
		a = (double*)calloc(N+1, sizeof(double));
		
		if (manual) {
			for (i = 0; i <= N; i++) {
				scanf("%lf", &a[i]);
			}
			scanf("%d", &k);
		} else {
			for (i = 0; i <= N; i++) {
				a[i] = 1;
			}
			k = 1;
		}
		
		printf("%.16g\n", polinomio(N, a, k)); 
		free(a);
	}
	
	return 0;
}