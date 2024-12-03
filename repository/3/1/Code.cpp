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

void Constroi(Fila &F) { //O~(1)
	Constroi(F.P1);
	Constroi(F.P2);
}

void Enfileira(Fila &F, int x) { //O~(1)
	Empilha(F.P1, x);
}

int Desenfileira(Fila &F) { //O~(2N) = O~(N)
	while (F.P1.N > 1) //O~(N-1) = O~(N)
		Empilha(F.P2, Desempilha(F.P1));

	int proximo = Desempilha(F.P1);

	while (F.P2.N > 0) //O~(N)
		Empilha(F.P1, Desempilha(F.P2));

	return proximo;
}

int Proximo(Fila &F) { //O~(2N) = O~(N)
	while (F.P1.N > 0) //O~(N)
		Empilha(F.P2, Desempilha(F.P1));

	int proximo = Topo(F.P2);

	while (F.P2.N > 0) //O~(N)
                Empilha(F.P1, Desempilha(F.P2));

	return proximo;
}

int Tamanho(Fila &F) {
	return(F.P1.N);
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
