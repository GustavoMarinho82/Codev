#include <stdio.h>
#include <stdlib.h>
#include "Bib1.h"
#include "Bib2.h"

/* Se achar útil empregar uma pilha ou fila em sua solução,
   utilize-a pela respectiva interface padrão 
   disponibilizada abaixo */ 
   
/* pilha */
void Constroi(Pilha &P);
void Empilha(Pilha &P, int x);
int Desempilha(Pilha &P);
int Topo(Pilha &P);
int Tamanho(Pilha &P);
/* pilha */

/* fila */
void Constroi(Fila &F);
void Enfileira(Fila &F, int x);
int Desenfileira(Fila &F);
int Proximo(Fila &F);
int Tamanho(Fila &F);
/* fila */

void AlternarPosNeg(int num[], int n) {
	/* num[0..n-1] são os números entrados pelo usuário */
	/* insert your code here */
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int * num; int n;
	while (scanf("%d", &n)>0) {
		if (n > -1) {
			/* teste manual: n, num[0..n-1] */
			num = (int *) malloc(sizeof(int) * n);
			for (int i=0; i<n; i++) {
				scanf("%d", &num[i]);
			}
			AlternarPosNeg(num, n);
			free(num);
		} else {
			/* teste automático */
			if (n==-1) {
				n = 100000;
				num = (int *) malloc(sizeof(int) * n);
				int s = 1;
				for (int i=0; i<n; i++) { num[i] = s*(i+1); s = -s; }
				AlternarPosNeg(num, n);
				free(num);
			} else if (n==-2) {
				n = 100000;
				num = (int *) malloc(sizeof(int) * n);
				for (int i=0; i<n/2; i++) num[i] = (i+1); 
				for (int i=n/2; i<n; i++) num[i] = -(i+1); 
				AlternarPosNeg(num, n);
				free(num);
			} else {
				n = 100000;
				num = (int *) malloc(sizeof(int) * n);
				for (int i=0; i<n/2; i++) num[i] = -(i+1); 
				for (int i=n/2; i<n; i++) num[i] = (i+1); 
				AlternarPosNeg(num, n);
				free(num);
			}
		}
	}

	return 0;
}