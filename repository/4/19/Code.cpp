#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

bool DEBUG;

void RemoveMaiores(int L[], int &n, int k) { //O(n)
	//Remove os Maiores Elementos de L[0..n-1], sem necessariamente manter a ordem, e atualiza o tamanho do vetor em n
	
	if (n > 0) {  // Caso base: o vetor tem pelo menos um elemento
		int nlin = n - 1;  // Armazena o índice do último elemento no vetor
        
		// Chamada recursiva para processar os elementos antes do último
		RemoveMaiores(L, nlin, k);
		
		// Verifica se o último elemento (L[n-1]) é maior que k
		if (L[n - 1] <= k) {
			// Se for menor ou igual a k, mantém o valor na posição correta
			L[nlin] = L[n - 1];  // Move o elemento para a posição nlin
			n = nlin + 1;  // Atualiza o tamanho do vetor
		} else {
			// Se for maior que k, simplesmente descarta o elemento
			n = nlin;  // Atualiza o tamanho do vetor (reduz o número de elementos)
		}
	}
}

void C_RemoveMaiores(int L[], int &n, int k) {
#ifndef CODEV
	printf("CODEV_BEGIN_EXEC\n");
#endif
	RemoveMaiores(L,n,k);
#ifndef CODEV
	printf("CODEV_END_EXEC\n");
#endif
}

void Escreve(int L[], int n) {
	int * Lv = (int *) malloc(sizeof(int)*n);
	for (int i=0; i<n; i++) Lv[i] = L[i];
	sort(Lv,Lv+n);
	printf("["); for (int i=0; i<n; i++) printf("%d", Lv[i]); printf("]\n");
	free(Lv);
}

int main(int argc, char * argv[]) {
	setbuf(stdout, NULL); setbuf(stderr, NULL); DEBUG = (argc > 1); 
	int n; int * L; int k; 
	while (scanf("%d", &n)>0) {
		if (n!=-1) {
			/* n, e1, e2, ..., en, k */
			L = (int *) malloc(sizeof(int)*n); 
			for (int i=0; i<n; i++) scanf("%d", &L[i]);	
			scanf("%d", &k);
			C_RemoveMaiores(L,n,k); Escreve(L,n); 
			free(L);
		} else {
			/* automatic test */
			int nlin = 50000; k = 2;
			n = nlin;
			L = (int *) malloc(sizeof(int)*n); 
			for (int t=1; t<=20; t++) {
				n = nlin;
				for (int i=0; i<n; i++) L[i] = (i%2==0 ? 2 : 3);
				C_RemoveMaiores(L,n,k); 
				if (t==1) Escreve(L,n); 
			}
			free(L);
		}
	}
	return 0;
}
