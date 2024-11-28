#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Prox;
} No;

int NumeroElementos(No * L) {
	/* insert your code here */
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
			/* teste manual: i e = insere o elemento e; n = calcula o número de elementos */
			if (op[0] == 'i') {
				scanf("%d", &e); Insere(L,e);
			} else {
				printf("%d\n", NumeroElementos(L));
			}
		} else {
			/* teste automático */
			for (int i=1; i<=50000; i++) {
				Insere(L,i);
			}	
			for (int t=1; t<=100; t++) NumeroElementos(L);
			printf("%d\n", NumeroElementos(L));
		}
	}

	return 0;
}