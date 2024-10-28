#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Ant;
	No * Prox;
} No;

void Remove(No * &L, No * p) { //O~(1)
	if(L != NULL){
		if (L == p) //Ou (p->Ant == NULL)
			L = p->Prox;
		
		else
			p->Ant->Prox = p->Prox;
			
		if (p->Prox != NULL)
			p->Prox->Ant = p->Ant;
			
		free(p);
	}
}

void C_Remove(No * &L, No * p, int q=1) {
#ifndef CODEV
	printf("CODEV_BEGIN_EXEC\n");
#endif
	//No * r;
	for (int t=0; t<q; t++) {
		Remove(L,p);
	}
#ifndef CODEV
	printf("CODEV_END_EXEC\n");
#endif
	//return r;
}

void Insere(No * &L, int e) {
	No * novo = (No *) malloc(sizeof(No));
	novo->E = e;
	if (L == NULL) {
		novo->Prox = NULL; novo->Ant = NULL; L = novo;
	} else {
		novo->Prox = L; novo->Ant = NULL; 
		L->Ant = novo; L = novo;
	}
}

void Escreve(No * L) {
	No * p; No * pUlt = NULL;
	printf("Esq >> Dir: [ "); for (p=L; p!=NULL; p=p->Prox) {printf("%d ", p->E); pUlt = p;}; printf("]; ");
	printf("Dir >> Esq: [ "); for (p=pUlt; p!=NULL; p=p->Ant) printf("%d ", p->E); printf("]\n");
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
			/* lê n, e1, e2, ..., en, i (ei é o elemento a ser removido) */
			No ** V = (No **) malloc(sizeof(No *) * n);
			for (int i=0; i<n; i++) {
				int e; scanf("%d", &e);	Insere(L,e); V[i] = L;
			}
			int i; scanf("%d", &i);	
			C_Remove(L,V[i-1]); Escreve(L); Destroi(L);
			free(V);
		} else {
			/* automatic test */
			n = 1000000;
			No ** V = (No **) malloc(sizeof(No *) * n);
			for (int i=0; i<n; i++) {
				Insere(L,i%100); V[i] = L;
			}
			for (int i=0; i<1000; i++) {
				C_Remove(L,V[i*900]); 
			}			
			Escreve(L); Destroi(L);
			free(V);
		}
	}
	return 0;
}