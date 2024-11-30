#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Prox;
} No;

int KUltimo(No * L, int k, int &n) {
	/* retorna em n o número de elementos de L */
	if (L == NULL) {
		n = 0;
		return -1;
	} else {
		int x = KUltimo(L->Prox, k, n);
		n = n+1;
		if (n == k) {
			return L->E;
		} else if (n<k) {
			return -1;
		} else {
			return x;
		}
	}	
}

int KUltimo(No * L, int k) {
	int n;
	return KUltimo(L,k,n);
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