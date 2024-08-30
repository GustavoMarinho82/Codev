#include <stdio.h>
#include <stdlib.h>


int** multi_matriz(int r, int s, int t, int** M1, int** M2){
	/* insert your code here */
}

int main() {
	int r, s, t;
	
	while (scanf("%d %d %d", &r, &s, &t)>0) { 
		int **M1, **M2, **R;
		int i, j;
		
		M1 = AlocarMatriz(r, s);
		M2 = AlocarMatriz(s, t);
		R = AlocarMatriz(s, t);
		
		LerMatriz(M1, r, s);
		LerMatriz(M2, s, t);
		
		R = multi_matriz(r, s, t, M1, M2);

		EscreverMatriz(R, r, t);

		LiberarMatriz(M1, r);		
		LiberarMatriz(M2, s);		
		LiberarMatriz(R, r);		
	}
	
	return 0;
}