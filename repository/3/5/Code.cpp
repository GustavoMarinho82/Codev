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


void LerEscreverKUltimos(int k) { //Tempo: O~(n) | Espaço aux: O(k)
	Fila F;
	Constroi(F);
	
	int buffer;
	
	while (scanf("%d", &buffer) > 0) { //O~(n)
		if (buffer != 0) {
			if (Tamanho(F) == k) //Se F for ultrapassar o tamanho de k, remove o elemento mais antigo, deixando só os k-1 últimos, na ordem de adição deles
				Desenfileira(F);
			
			Enfileira(F, buffer);
			
		} else {
			break;
		}
	}
	
	while (Tamanho(F) > 0) //O~(k)
		printf("%d ", Desenfileira(F));
	
	printf("\n");
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
