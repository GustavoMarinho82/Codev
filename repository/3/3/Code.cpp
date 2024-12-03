#include <stdio.h>
#include <stdlib.h>
#include "Bib1.h"

#include <math.h> //-INFINITY
#define MAIOR(A,B) ((A > B) ? (A) : (B))

/* Interface padrão de pilha */
void Constroi(Pilha &P);
void Empilha(Pilha &P, int x);
int Desempilha(Pilha &P);
int Topo(Pilha &P);
int Tamanho(Pilha &P);
/* Interface padrão de pilha */

void Ordena2(Pilha &P, Pilha &Q, int &e_ord) { 
	/* Tempo: O~(n^2) | Espaço aux: O~(1 + pilha Q)
	 * e_ord -> qtd de elementos ordenados em P 
	 */
	
	if (e_ord != Tamanho(P)) {
		int maior = (int) -INFINITY;
		
		while (Tamanho(P) > e_ord) { //O~(n)
			maior = MAIOR(maior, Topo(P));
			Empilha(Q, Desempilha(P));
		}
		
		Empilha(P, maior);
		e_ord++;
			
		while (Tamanho(Q) > 0) { //O~(n)
			int x = Desempilha(Q);
			
			if (x == maior) {
				//Não empilha de volta em P, porque ele já foi tinha sido devolvido antes
				maior = (int) -INFINITY;
			
			} else {
				Empilha(P, x);
			}
		}
		
		Ordena2(P, Q, e_ord);
	}
}

void Ordena(Pilha &P) { //O~(n^2)
	//Pilha ordenada: [maior_e, segundo_maior_e, ... , menor_e]
	
	Pilha Q; Constroi(Q);
	int e_ord = 0; //e_ord -> qtd de elementos ordenados em P
	
	Ordena2(P, Q, e_ord);
}

void Escreve(Pilha &P) {
		while (Tamanho(P) > 0) {
			printf("%d ", Desempilha(P));
		}
		printf("\n");
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	Pilha P; Constroi(P);
	int n; int e;
	while (scanf("%d", &n)>0) {
		if (n>=0) {
			/* teste manual: 'n e_1 ... e_n' */
			for (int i=1; i<=n; i++) {
				scanf("%d", &e); Empilha(P,e);
			}
			Ordena(P); Escreve(P);
		} else {
			/* teste automático */
			if (n==-1) {
				for (int i=1; i<=1000; i++) {
					Empilha(P,i+(1001)*(i%2));
				}	
			} else {
				for (int i=1; i<=1000; i++) {
					Empilha(P,i+(1001)*(i%5==0 ? 0 : 1));
				}	
			}
			Ordena(P); Escreve(P);
		}
	}

	return 0;
}
