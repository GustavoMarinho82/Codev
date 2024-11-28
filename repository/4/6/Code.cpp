#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef struct No {
	int E;
	int niv;
	No * Esq;
	No * Dir;
} No;


void AtualizaNivel(No * T) {
	/* insert your code here */
}


void C_AtualizaNivel(No * T) {
#ifndef CODEV
	printf("CODEV_BEGIN_EXEC\n");
#endif
	AtualizaNivel(T);
#ifndef CODEV
	printf("CODEV_END_EXEC\n");
#endif
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

void PreencheCheia(No * &T, int h, int &i) {
	if (h==0) {
		T = NULL;
	} else {
		T = (No *) malloc(sizeof(No));
		T->E = i; i++;
		PreencheCheia(T->Esq, h-1, i);
		PreencheCheia(T->Dir, h-1, i);
	}
}

void PreencheZigZag(No * &T, int h, int &i) {
	if (h==0) {
		T = NULL;
	} else {
		T = (No *) malloc(sizeof(No));
		T->E = i; i++;
		PreencheZigZag(T->Esq, h-1, i);
		T->Dir = NULL;
	}
} 

void Escreve(No * T) {
	if (T != NULL) {
		printf("niv(%d)=%d ", T->E, T->niv);
		Escreve(T->Esq); Escreve(T->Dir);
	}
}

int FIM_ENTRADA = -1000;
int ENTRADA_AUTOMATICA = -2000;

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
			int i=1;
			if (e[n] == ENTRADA_AUTOMATICA) {
				PreencheCheia(T, 19, i); 
			} else {
				PreencheZigZag(T, 50000, i); 
			}
		}
		C_AtualizaNivel(T); Escreve(T); printf("\n"); Destroi(T);
		n=0;
	}
	free(e);
	return 0;
}