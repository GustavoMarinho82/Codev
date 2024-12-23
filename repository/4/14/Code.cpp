#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

typedef struct No {
	int E;
	No * Prox;
} No;

void Insere(No * &L, int e) {
	No * novo = (No *) malloc(sizeof(No));
	novo->E = e; novo->Prox = L; L = novo; 
}

bool BuscarElemento(No* L, int x) { //O~(n)
	if (L == NULL) {
		return false;
	
	} else {
		return (x == L->E) || BuscarElemento(L->Prox, x);
	}
}

No * SemRepeticoes(No * L) { //O~(n^2)
	//Essa função não respeita a ordem da lista original
	if (L == NULL) {
		return NULL;
	
	} else {
		if (!BuscarElemento(L->Prox, L->E)) {
			No* R = (No*) malloc(sizeof(No));
			R->E = L->E;
			R->Prox = SemRepeticoes(L->Prox);
			return R;
			
		} else {
			return SemRepeticoes(L->Prox);
		}
	}
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


int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int n; No * L = NULL; No * Lr;
	while (scanf("%d", &n)>0) {
		if (n>-1) {
			/* lê n, e1, e2, ..., en */
			for (int i=0; i<n; i++) {
				int e; scanf("%d", &e);	Insere(L,e); 
			}
			Lr = SemRepeticoes(L); Escreve(Lr); Destroi(Lr); Destroi(L);
		} else {
			/* automatic test */
			if (n==-1) {
				n = 1000;
				for (int i=0; i<n; i++) {
					Insere(L,(i%2==0 ? 2 : 3));
				}
				Lr = SemRepeticoes(L); Escreve(Lr); Destroi(Lr); Destroi(L);
			} else {
				n = 1000;
				for (int i=0; i<n; i++) {
					Insere(L,i);
				}
				Lr = SemRepeticoes(L); Escreve(Lr); Destroi(Lr); Destroi(L);
			}
		}
	}
	return 0;
}
