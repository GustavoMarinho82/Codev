#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

void RemoveMaiores(int L[], int &n, int k) {
	/* insert your code here */
}

void C_RemoveMaiores(int L[], int &n, int k, int q=1) {
#ifndef CODEV
	printf("CODEV_BEGIN_EXEC\n");
#endif
	//No * r;
	for (int t=0; t<q; t++) {
		RemoveMaiores(L,n,k);
	}
#ifndef CODEV
	printf("CODEV_END_EXEC\n");
#endif
	//return r;
}

void Insere(int L[], int &n, int e) {
	L[n] = e; n = n+1;
}

void Escreve(int L[], int &n) {
	std::sort(L,L+n);
	printf("["); for (int i=0; i<n; i++) printf("%d", L[i]); printf("]\n");
}

int main() {
	setbuf(stdout, NULL); setbuf(stderr, NULL);
	int max_n; int * L; int n;
	while (scanf("%d", &max_n)>0) {
		if (max_n!=-1) {
			/* lê n, e1, e2, ..., en, k */
			L = (int *) malloc(sizeof(int)*max_n); n = 0;
			for (int i=0; i<max_n; i++) {
				int e; scanf("%d", &e);	Insere(L,n,e);
			}
			int k; scanf("%d", &k);
			C_RemoveMaiores(L,n,k); 
			Escreve(L,n);
			free(L);
		} else {
			/* automatic test */
			max_n = 1000000;
			L = (int *) malloc(sizeof(int)*max_n); n = 0;
			for (int i=0; i<max_n; i++) {
				Insere(L,n,(i%2==0 ? 2 : 3));
			}
			C_RemoveMaiores(L,n,2); Escreve(L,n);
			free(L);
		}
	}
	return 0;
}