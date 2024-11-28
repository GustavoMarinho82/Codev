#include <stdio.h>
#include <stdlib.h>



long long int NumeroCaminhos(int n, int m, int X[], int Y[]) {
	/* insert your code here */
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int n; int m; int * X; int * Y;
	while (scanf("%d %d", &n, &m)>0) {
		if (n>=0) {
			/* teste manual */
			X = (int *) malloc(sizeof(int)*m); Y = (int *) malloc(sizeof(int)*m);
			for (int i=0; i<m; i++) scanf("%d", &X[i]);
			for (int i=0; i<m; i++) scanf("%d", &Y[i]);
			printf("%lld\n", NumeroCaminhos(n,m,X,Y));
			free(X); free(Y);
		} else {
			/* teste automático */
			n = 2000; m=2*n;
			X = (int *) malloc(sizeof(int)*m); Y = (int *) malloc(sizeof(int)*m);
			m = 0;
			for (int i=2; i<=n; i++) { 
				X[m] = i; Y[m] = i-1; m++;
				X[m] = i-1; Y[m] = i+1; m++;
			}
			printf("%lld\n", NumeroCaminhos(n,m,X,Y));
			free(X); free(Y);
		}
	}

	return 0;
}