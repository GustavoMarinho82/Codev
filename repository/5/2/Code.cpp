#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int E;
	No * Esq;
	No * Dir;
} No;


int SomaFolhas(No * T) {
	/* insert your code here */
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

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	No * T = NULL; 
	int * e = (int *) malloc(sizeof(int) * 1000000); int n=0;
	while (scanf("%d", &e[n])>0) {
		if (e[n] > -2) {
			/* teste manual: visita preordem de T (0 para nulo) */
			while (e[n] != -1) {
				n++;
				scanf("%d", &e[n]);
			}
			int i=0;
			Insere(T,e,i);
			printf("%d\n", SomaFolhas(T));
			Destroi(T);
			n=0;
		} else {
			/* teste automático */
			if (e[n] == -2) {
				PreencheCheia(T, 19);
			} else {
				PreencheZigZag(T, 50000);
			}
			printf("%d\n", SomaFolhas(T));
			Destroi(T);
		}
	}
	free(e);
	return 0;
}