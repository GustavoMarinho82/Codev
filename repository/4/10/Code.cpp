#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Prox;
} No;


int Maior(No * L) { //O~(n)
	// Assume que a lista tem pelo menos um elemento
	if (L->Prox == NULL) {
		return L->E;
		
	} else {
		int x = Maior(L->Prox);
		
		return (x > (L->E)) ? x : (L->E);
	}
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
			int n = 50000;
			for (int i=n/2; i<=n; i++) {
				Insere(L,i);
			}	
			for (int i=1; i < n/2; i++) {
				Insere(L,i);
			}	
			for (int t=1; t<=100; t++)  Maior(L);
			printf("%d\n", Maior(L));
		}
	}
	return 0;
}
