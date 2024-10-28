#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

typedef struct No {
	int E;
	No * Prox;
} No;


void RemoveMaiores(No * &L, int k) { //O~(N)
	No* p = L;
	No* pAnt = NULL;
	
	while(p != NULL){ //O~(N) | N-> n de elementos da lista
		if(p->E > k){
			if(pAnt == NULL){
				L = p->Prox;
				free(p);
				p = L;
				
			} else {
				pAnt->Prox = p->Prox;
				free(p);
				p = pAnt->Prox;
			}
			
		} else {
			pAnt = p;
			p = p->Prox;
		}
	}
}

void C_RemoveMaiores(No * &L, int k, int q=1) {
#ifndef CODEV
	printf("CODEV_BEGIN_EXEC\n");
#endif
	//bool r;
	for (int t=0; t<q; t++) {
		RemoveMaiores(L,k);
	}
#ifndef CODEV
	printf("CODEV_END_EXEC\n");
#endif
	//return r;
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
			C_RemoveMaiores(L,k); Escreve(L); Destroi(L);
		} else {
			/* automatic test */
			max_n = 1000000;
			for (int i=0; i<max_n; i++) {
				Insere(L,(i%2==0 ? 2 : 3));
			}
			C_RemoveMaiores(L,2); Escreve(L); Destroi(L);
		}
	}
	return 0;
}