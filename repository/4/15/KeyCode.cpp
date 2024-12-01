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

No * Soma2a2(No * L) {
	if (L == NULL) {
		return NULL;
	} else {
		No * p; 
		No * R = Soma2a2(L->Prox);
		p = L->Prox;
		while (p != NULL) {
			Insere(R, L->E + p->E);
			p = p->Prox;
		}
		return R;
	}
}

No * C_Soma2a2(No * L, int q=1) {
#ifndef CODEV
	printf("CODEV_BEGIN_EXEC\n");
#endif
	No * r;
	for (int t=0; t<q; t++) {
		r = Soma2a2(L);
	}
#ifndef CODEV
	printf("CODEV_END_EXEC\n");
#endif
	return r;
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
	printf("[ "); for (int i=0; i<n; i++) printf("%d ", Lv[i]); printf("]\n");
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
		if (n!=-1) {
			/* lê n, e1, e2, ..., en */
			for (int i=0; i<n; i++) {
				int e; scanf("%d", &e);	Insere(L,e); 
			}
			Lr = C_Soma2a2(L); Escreve(Lr); Destroi(Lr); Destroi(L);
		} else {
			/* automatic test */
			n = 1000;
			for (int i=0; i<n; i++) {
				Insere(L,i);
			}
			Lr = C_Soma2a2(L); Escreve(Lr); Destroi(Lr); Destroi(L);
		}
	}
	return 0;
}