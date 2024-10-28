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

No * SemRepeticoes(No * L) {
	No* L2 = NULL;
	No* p1 = L; //p1 percorre a lista L
	
	while(p1 != NULL){
		No* p2 = L2; //p2 percorre a lista L2
		int repetido = 0;
		
		while(p2 != NULL){
			if(p1->E == p2->E){
				repetido == 1;
				break;
			}
			
			p2 = p2->Prox;
		}
		
		if(repetido == 0){
			No* pTemp = (No*) malloc(sizeof(No));
			
			pTemp->E = p1->E;
			pTemp->Prox = L2;
			L2 = pTemp;
		}
		
		p1 = p1->Prox;
	}
	
	return L2;
}

No * C_SemRepeticoes(No * L, int q=1) {
#ifndef CODEV
	printf("CODEV_BEGIN_EXEC\n");
#endif
	No * r;
	for (int t=0; t<q; t++) {
		r = SemRepeticoes(L);
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
			Lr = C_SemRepeticoes(L); Escreve(Lr); Destroi(Lr); Destroi(L);
		} else {
			/* automatic test */
			int nlin = n;
			n = 1000;
			for (int i=0; i<n; i++) {
				Insere(L,(i%2==0 ? 2 : 3));
			}
			if (nlin != -1) {
				for (int i=0; i<n; i++) {
					Insere(L,i);
				}
			}
			Lr = C_SemRepeticoes(L); Escreve(Lr); Destroi(Lr); Destroi(L);
		}
	}
	return 0;
}