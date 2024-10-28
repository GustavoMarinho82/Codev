#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Prox;
} No;


int Maior(No * L) { //O~(N-1)
	//Assume que a lista tem pelo menos um elemento
	No* p = L->Prox;
	No* pMaior = L;
	
	while(p != NULL){ //O~(N-1) | N-> n de elementos da lista
		if(p->E > pMaior->E)
			pMaior = p;
		
		p = p->Prox;
	}
	
	return pMaior->E;
}

void Insere(No * &L, int e) {
	No * novo = (No *) malloc(sizeof(No));
	novo->E = e;
	novo->Prox = L;
	L = novo;
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	No * L = NULL; 
	char op[2]; int e, k;
	while (scanf("%s", op)>0) {
		if (op[0] != 'a') {
			/* teste manual: i e = insere o elemento e; m = busca o maior */
			if (op[0] == 'i') {
				scanf("%d", &e); Insere(L,e);
			} else {
				printf("%d\n", Maior(L));
			}
		} else {
			/* teste automático */
			int n = 1000000;
			for (int i=n/2; i<=n; i++) {
				Insere(L,i);
			}	
			for (int i=1; i < n/2; i++) {
				Insere(L,i);
			}	
			printf("%d\n", Maior(L));
		}
	}
	return 0;
}