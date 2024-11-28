#include <stdio.h>
#include <stdlib.h>
#include "Bib1.h"

/* Interface padrão de pilha */
void Constroi(Pilha &P);
void Empilha(Pilha &P, int x);
int Desempilha(Pilha &P);
int Topo(Pilha &P);
int Tamanho(Pilha &P);
/* Interface padrão de pilha */

typedef struct Fila {
	Pilha P1,P2;
} Fila;

void Constroi(Fila &F) {
	/* insert your code here */
}
void Enfileira(Fila &F, int x) {
	/* insert your code here */
}

int Desenfileira(Fila &F) {
	/* insert your code here */
}

int Proximo(Fila &F) {
	/* insert your code here */
}

int Tamanho(Fila &F) {
	/* insert your code here */
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	Fila F; Constroi(F);
	char op[2]; int e;
	while (scanf("%s", op)>0) {
		/* teste manual: 'i e' = enfileira o elemento e; 'r' = desenfileira, 'p' = consulta o próximo, 'n' = consulta o tamanho */
		if (op[0] == 'i') {
			scanf("%d", &e); Enfileira(F,e);
		} else if (op[0] == 'r') {
			printf("%d\n", Desenfileira(F));
		} else if (op[0] == 'p') {
			printf("%d\n", Proximo(F));
		} else if (op[0] == 'n') {
			printf("%d\n", Tamanho(F));
		} else {
			/* teste automático */
			for (int i=1; i<=1000; i++) {
				Enfileira(F,i);
			}	
			while (Tamanho(F) > 0) { 
				printf("%d ", Tamanho(F));
				printf("%d ", Proximo(F));
				printf("%d ", Desenfileira(F));
			}	
			printf("\n");
		}
	}

	return 0;
}