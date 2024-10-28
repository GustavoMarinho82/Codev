#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Prox;
} No;

void Remove(No * &L, No * p) { //O(N)
	if (L == p){
		L = p->Prox;
		free(p);
	
	} else {
		No* pAnt = L;
		
		while(pAnt != NULL){ //O(N)
			if (pAnt->Prox == p){
				pAnt->Prox = p->Prox;
				free(p);
				break;
			}
			
			pAnt = pAnt->Prox;
		}
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
			n = 100000;
			No ** V = (No **) malloc(sizeof(No *) * n);
			for (int i=0; i<n; i++) {
				Insere(L,i%100); V[i] = L;
			}
			for (int i=0; i<10; i++) {
				C_Remove(L,V[i*9000]); 
			}			
			Escreve(L); Destroi(L);
			free(V);
		}
	}
	return 0;
}