#include <stdio.h>
#include <stdlib.h>

void LiberarMatriz(int ** M, int linhas) {
	for (int z = 0; z < linhas; z++) {
		free(M[z]);
	}
	free(M);
}

int ** AlocarMatriz(int linhas, int colunas) {
	int ** M = (int**)calloc(linhas, sizeof(int*));
			
	for (int i = 0; i < linhas; i++) {
		M[i] = (int*)calloc(colunas, sizeof(int));
	}
	return M;
}

void LerMatriz(int ** M, int linhas, int colunas) {
	for (int i = 0; i < linhas; i++) {
		for (int j = 0; j < colunas; j++) {
			scanf("%d", &M[i][j]);
		}
	}
}

void EscreverMatriz(int ** M, int linhas, int colunas) {
	printf("[");
	for (int i = 0; i < linhas; i++) {
		if (i>0) printf(", "); 
		printf("[");
		for (int j = 0; j < colunas; j++) {
			if (j>0) printf(", ");
			printf("%d", M[i][j]);
		}
		printf("]");
	}
	printf("]\n");
}

int** transposta(int** M, int n, int m){
	/* insert your code here */
}

int main() {
	int n, m;
	int ** M, ** Mt;
	
	while (scanf("%d", &n)>0) {
		int i; bool manual = true;

		if (n >= 0){
			scanf("%d", &m);
		} else {
			n=1000; m=1000; manual = false;
		}
		M = AlocarMatriz(n, m);
		if (manual) {
			LerMatriz(M, n, m);			
		} else {
			for (i=0; i<n; i++) {
				for (int j=0; j<m; j++) {
					M[i][j] = i*n+j;
				}
			}
		}
		Mt = transposta(M, n, m);
		
		EscreverMatriz(Mt, m, n);

		LiberarMatriz(Mt, m);			
		LiberarMatriz(M, n);			

	}
	
	return 0;
}