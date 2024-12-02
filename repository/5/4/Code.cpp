#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

int FIM_ENTRADA = -1000;
int ENTRADA_AUTOMATICA = -2000;

typedef struct NoL {
	int E;
	NoL * Prox;
} NoL;

typedef struct No {
	int E;
	No * Esq;
	No * Dir;
} No;


void ListaNosInternos2(No * T, NoL* &u) { //O~(n)
	if (T != NULL) {
		if ((T->Esq != NULL) || (T->Dir != NULL)) {
			NoL* L = (NoL*) malloc(sizeof(NoL));
			L->E = T->E;
			L->Prox = u;
			u = L;
		}
		ListaNosInternos2(T->Esq, u);
		ListaNosInternos2(T->Dir, u);
	}
}

NoL * ListaNosInternos(No * T) { //O~(n)
	NoL* u = NULL;
	ListaNosInternos2(T, u);
	return u;
}

NoL * C_ListaNosInternos(No * T) {
#ifndef CODEV
	printf("CODEV_BEGIN_EXEC\n");
#endif
	NoL * r;
	r = ListaNosInternos(T);
#ifndef CODEV
	printf("CODEV_END_EXEC\n");
#endif
	return r;
}

void Insere(No * &T, int e[], int &i) {
	if (e[i] == 0) {
		i++;
		T = NULL;
	} else  {
		T = (No *) malloc(sizeof(No));
		T->E = e[i]; i++;
		Insere(T->Esq, e, i);
		Insere(T->Dir, e, i);
	}
}

void Destroi(No * &T) {
	if (T != NULL) {
		Destroi(T->Esq);
		Destroi(T->Dir);
		free(T);
		T = NULL;
	}
}

void Destroi(NoL * &L) {
	NoL * p = L; NoL * pa = NULL;
	if (p != NULL) {
		pa = p; p = p->Prox;
		free(pa);
	}
	L = NULL;
}

void PreencheCheia(No * &T, int h) {
	if (h==0) {
		T = NULL;
	} else {
		T = (No *) malloc(sizeof(No));
		T->E = h;
		PreencheCheia(T->Esq, h-1);
		PreencheCheia(T->Dir, h-1);
	}
}

void PreencheZigZag(No * &T, int h) {
	if (h==0) {
		T = NULL;
	} else {
		T = (No *) malloc(sizeof(No));
		T->E = h;
		PreencheZigZag(T->Esq, h-1);
		T->Dir = NULL;
	}
}

void Escreve(NoL * L) {
	int n = 0;
	NoL * p = L;
	while (p != NULL) {
		n++; p = p->Prox;
	}
	int * Lv = (int *) malloc(sizeof(int)*n);
	p = L; int i = 0;
	while (p != NULL) {
		Lv[i] = p->E; i++; p = p->Prox;
	}
	std::sort(Lv,Lv+n);
	printf("[ "); for (int i=0; i<n; i++) printf("%d ", Lv[i]); printf("]\n");
	free(Lv);
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	No * T = NULL; 
	int * e = (int *) malloc(sizeof(int) * 1000000); int n=0;
	while (scanf("%d", &e[n])>0) {
		if (e[n] > ENTRADA_AUTOMATICA) {
			/* teste manual: visita preordem de T (0 para nulo) */
			while (e[n] != FIM_ENTRADA) {
				n++;
				scanf("%d", &e[n]);
			}
			int i=0;
			Insere(T,e,i);
		} else {
			/* teste automático */
			if (e[n] == ENTRADA_AUTOMATICA) {
				PreencheZigZag(T, 50000);
			} else {
				PreencheCheia(T, 19);
			}
		}
		NoL * L = C_ListaNosInternos(T); Escreve(L); Destroi(L); Destroi(T); 
		n=0; 
	}
	free(e);
	return 0;
}
