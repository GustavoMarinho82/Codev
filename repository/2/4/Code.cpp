#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Prox;
} No;

int KUltimo(No * L, int k) { //O~(N)
	No* pkUltimo = L;
	No* p = L->Prox;
	int n = 1;
	
	while(p != L){ //O~(N) | N-> n de elementos da lista
		if(n >= k)
			pkUltimo = pkUltimo->Prox;
		
		p = p->Prox;
		n++;
	}
	
	if(pkUltimo == L)
		return -1;
	else
		return pkUltimo->E;
}

void Constroi(No * &L, No * &u) {
	L = (No *) malloc(sizeof(No));
	u = L;
	L->Prox = L;
}

void Insere(No * &L, int e, No * &u) {
	No * novo = (No *) malloc(sizeof(No));
	novo->E = e;
	novo->Prox = u->Prox;
	u->Prox = novo;
	u = novo;
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	No * L = NULL; No * u; Constroi(L,u); 
	char op[2]; int e, k;
	while (scanf("%s", op)>0) {
		if (op[0] != 'a') {
			/* teste manual: i e = insere o elemento e; b k = busca o k-último */
			if (op[0] == 'i') {
				scanf("%d", &e); Insere(L,e,u);
			} else {
				scanf("%d", &k); printf("%d\n", KUltimo(L,k));
			}
		} else {
			/* teste automático */
			int n = 2000000;
			for (int i=1; i<=n; i++) {
				Insere(L,i,u);
			}	
			printf("%d\n", KUltimo(L,n/2));
		}
	}
	return 0;
}