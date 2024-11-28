#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Prox;
} No;


No * Inverte(No * L) {
	/* insert your code here */
}

void Insere(No * &L, int e) {
	No * novo = (No *) malloc(sizeof(No));
	novo->E = e; novo->Prox = L; L = novo; 
}

void Escreve(No * L) {
	No * p = L;
	printf("[ "); for (p=L; p!=NULL; p=p->Prox) printf("%d ", p->E); printf("]\n");
}

void Destroi(No * &L) {
	No * p, * pr; p = L; 
	while (p != NULL) {
		pr = p; p = p->Prox; free(pr);
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
			Lr = Inverte(L); Escreve(Lr); Destroi(Lr); Destroi(L);
		} else {
			/* automatic test */
			n = 1000;
			for (int i=0; i<n; i++) {
				Insere(L,i%100);
			}
			for (int t=1; t<=1000; t++) { Lr = Inverte(L); Destroi(Lr); }
			Lr = Inverte(L); Escreve(Lr); Destroi(Lr); Destroi(L);
		}
	}
	return 0;
}