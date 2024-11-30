#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Prox;
} No;

int Ultimo(No * L) {
	if (L == NULL) {
		return -1;
	} else {
		if (L->Prox == NULL) {
			return L->E;
		} else {
			return Ultimo(L->Prox);
		}
	}
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
	No * L = NULL; No * u; 
	char op[2]; int e, k;
	while (scanf("%s", op)>0) {
		if (op[0] != 'a') {
			/* teste manual: i e = insere o elemento e; u = busca o último */
			if (op[0] == 'i') {
				scanf("%d", &e); Insere(L,e,u);
			} else {
				printf("%d\n", Ultimo(L));
			}
		} else {
			/* teste automático */
			for (int i=1; i<=50000; i++) {
				Insere(L,i,u);
			}	
			for (int t=1; t<=100; t++)  Ultimo(L);
			printf("%d\n", Ultimo(L));
		}
	}
	return 0;
}