#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Ant;
	No * Prox;
} No;

int KUltimo(No * L, int k) { //O(k-1)
	if(L == NULL)
		return -1;
	
	No* p = L->Ant;
	
	for(int i=0; i<(k-1); i++){ //O(k-1)
		if(p == L)
			return -1;
		
		p = p->Ant;
	}
	
	return p->E;
}

void Insere(No * &L, int e) {
	No * novo = (No *) malloc(sizeof(No));
	novo->E = e;
	if (L == NULL) {
		novo->Prox = novo;
		novo->Ant = novo;
		L = novo;
	} else {
		novo->Ant = L->Ant;
		L->Ant->Prox = novo;
		novo->Prox = L;
		L->Ant = novo;
		L = novo;
	}
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	No * L = NULL;  
	char op[3]; int e, k;
	while (scanf("%s", op)>0) {
		if (op[0] != 'a') {
			/* teste manual: i e = insere o elemento e; b k = busca o k-último */
			if (op[0] == 'i') {
				scanf("%d", &e); Insere(L,e);
			} else {
				scanf("%d", &k); printf("%d\n", KUltimo(L,k));
			}
		} else {
			/* teste automático */
			int n = 2000000;
			for (int i=1; i<=n; i++) {
				Insere(L,i);
			}	
			if (op[1] == '1') {
				printf("%d\n", KUltimo(L,n/2));
			} else {
				printf("%d\n", KUltimo(L,3));
				for (int i=1; i<=1000; i++) {
					KUltimo(L,3);
				}
			}
		}		
	}
	return 0;
}