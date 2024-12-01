#include <stdio.h>
#include <stdlib.h>



long long int NumeroCaminhos(int nx, int ny, bool ** Obs, long long int **T) {
	
	if (T[nx][ny] == -1) {
		if ((nx == 0) || (ny == 0) || (Obs[nx-1][ny-1])) {
			T[nx][ny] = 0;
		} else if ((nx==1) && (ny==1)) {
			T[nx][ny] = 1;
		} else {
			T[nx][ny] = NumeroCaminhos(nx-1, ny, Obs, T) + NumeroCaminhos(nx, ny-1, Obs, T);
		}
	}
	return T[nx][ny];
}

long long int NumeroCaminhos(int n, int m, int X[], int Y[]) {
	/* preparando estrutura de dados auxiliar Obs, T */
	bool ** Obs = (bool **) malloc(sizeof(bool *) * n);
	long long int ** T = (long long int **) malloc(sizeof(long long int *) * (n+1));
	for (int i=0; i<n; i++) {
		Obs[i] = (bool *) malloc(sizeof(bool) * n);
		for (int j=0; j<n; j++) Obs[i][j] = false; 
	}
	for (int i=0; i<=n; i++) {
		T[i] = (long long int *) malloc(sizeof(long long int) * (n+1));
		for (int j=0; j<=n; j++) T[i][j] = -1;
	}
	for (int i=0; i<m; i++) Obs[X[i]-1][Y[i]-1] = true;
	/* fim preparando Obs, T */
	
	long long int r = NumeroCaminhos(n, n, Obs, T);
	
	/* devolvendo memoria Obs, T */
	for (int i=0; i<n; i++) free(Obs[i]); 
	for (int i=0; i<=n; i++) free(T[i]);
	free(Obs); free(T);
	/* fim da devolução */

	return r;
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