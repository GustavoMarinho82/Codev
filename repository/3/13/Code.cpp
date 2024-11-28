#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

typedef struct No {
	int E;
	No * Prox;
} No;

void RemoveMaiores(No * &L, int k) {
	/* insert your code here */
}

void Escreve(No * L) {
	int n = 0;
	No * p = L;
	while (p != NULL) {
		n++; p = p->Prox;
	}
	int * Lv = (int *) malloc(sizeof(int)*n);
	p = L; int i = 0;
	while (p != NULL) {
		Lv[i] = p->E; i++; p = p->Prox;
	}
	std::sort(Lv,Lv+n);
	printf("["); for (int i=0; i<n; i++) printf("%d", Lv[i]); printf("]\n");
	free(Lv);
}

void Destroi(No * &L) {
	No * p, * pr; p = L; 
	while (p != NULL) {
		pr = p; p = p->Prox; 
		free(pr);
	}
	L = NULL; 
}


void Insere(No * &L, int e) {
	No * novo = (No *) malloc(sizeof(No));
	novo->E = e; novo->Prox = L; L = novo; 
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int max_n; No * L = NULL; 
	while (scanf("%d", &max_n)>0) {
		if (max_n!=-1) {
			/* lê n, e1, e2, ..., en, k */
			for (int i=0; i<max_n; i++) {
				int e; scanf("%d", &e);	Insere(L,e); 
			}
			int k; scanf("%d", &k);
			RemoveMaiores(L,k); Escreve(L); Destroi(L);
		} else {
			/* automatic test */
			for (int t=1; t<=20; t++) {
				L = NULL;
				max_n = 50000;
				for (int i=0; i<max_n; i++) {
					Insere(L,(i%2==0 ? 2 : 3));
				}
				RemoveMaiores(L,2); 
				if (t==1) Escreve(L); 
				Destroi(L);
			}
		}
	}
	return 0;
}