#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Prox;
} No;

int KUltimo2(No * L, No * LAnt, int k) { //O(n)
	if (k > 1){
		return (L->Prox == NULL) ? -1 : KUltimo2(L->Prox, LAnt, k-1);
		
	} else {
		return (L->Prox == NULL) ? (LAnt->E) : KUltimo2(L->Prox, LAnt->Prox, k);
	}
}

int KUltimo(No * L, int k) { //O(n)
	return (L == NULL) ? -1 : KUltimo2(L, L, k);
}

void Constroi(No * &L, No * &u) {
	L = NULL; u = NULL;
}

void Insere(No * &L, int e, No * &u) {
	No * novo = (No *) malloc(sizeof(No));
	novo->E = e;
	novo->Prox = NULL;
	if (L == NULL) {
		L = novo;
	} else {
		u->Prox = novo;
	}
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
			int n = 50000;
			for (int i=1; i<=n; i++) {
				Insere(L,i,u);
			}	
			for (int t=1; t<=100; t++) KUltimo(L,n/2);  
			printf("%d\n", KUltimo(L,n/2));
		}
	}
	return 0;
}
