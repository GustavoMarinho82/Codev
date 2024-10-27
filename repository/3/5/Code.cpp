#include <stdio.h>
#include <stdlib.h>
#include "Bib1.h"
#include "Bib2.h"

/* Se achar útil empregar uma pilha ou fila em sua solução,
   utilize-a pela respectiva interface padrão 
   disponibilizada abaixo */ 
   
/* pilha */
void Constroi(Pilha &P);
void Destroi(Pilha &P);
void Empilha(Pilha &P, int x);
int Desempilha(Pilha &P);
int Topo(Pilha &P);
int Tamanho(Pilha &P);
/* pilha */

/* fila */
void Constroi(Fila &F);
void Destroi(Fila &F);
void Enfileira(Fila &F, int x);
int Desenfileira(Fila &F);
int Proximo(Fila &F);
int Tamanho(Fila &F);
/* fila */


void LerEscreverKUltimos(int k) {
	/* leia uma sequência de números (usando scanf()), e ao final (número lido é 0),
	   escreva os k últimos lidos (usando printf()). 
	   (Deixe um espaço ao final de cada número impresso.) */
	/* insert your code here */
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int k; 
	while (scanf("%d", &k)>0) {
		/* teste manual: 'k <sequência de elementos, último igual a 0>' */
		LerEscreverKUltimos(k);
	}
	return 0;
}