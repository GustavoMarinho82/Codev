#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

bool DEBUG;

void RemoveMaiores(int L[], int &n, int k) {
	if (n > 0) {
		int nlin = n-1;
		RemoveMaiores(L, nlin, k);
		if (L[n-1] <= k) {
			L[nlin] = L[n-1];
			n = nlin+1;
		} else {
			n = nlin;
		}
	}
}

void C_RemoveMaiores(int L[], int &n, int k) {
#ifndef CODEV
	printf("CODEV_BEGIN_EXEC\n");
#endif
	RemoveMaiores(L,n,k);
#ifndef CODEV
	printf("CODEV_END_EXEC\n");
#endif
}

void Escreve(int L[], int n) {
	int * Lv = (int *) malloc(sizeof(int)*n);
	for (int i=0; i<n; i++) Lv[i] = L[i];
	sort(Lv,Lv+n);
	printf("["); for (int i=0; i<n; i++) printf("%d", Lv[i]); printf("]\n");
	free(Lv);
}

int main(int argc, char * argv[]) {
	setbuf(stdout, NULL); setbuf(stderr, NULL); DEBUG = (argc > 1); 
	int n; int * L; int k; 
	while (scanf("%d", &n)>0) {
		if (n!=-1) {
			/* n, e1, e2, ..., en, k */
			L = (int *) malloc(sizeof(int)*n); 
			for (int i=0; i<n; i++) scanf("%d", &L[i]);	
			scanf("%d", &k);
			C_RemoveMaiores(L,n,k); Escreve(L,n); 
			free(L);
		} else {
			/* automatic test */
			int nlin = 50000; k = 2;
			n = nlin;
			L = (int *) malloc(sizeof(int)*n); 
			for (int t=1; t<=20; t++) {
				n = nlin;
				for (int i=0; i<n; i++) L[i] = (i%2==0 ? 2 : 3);
				C_RemoveMaiores(L,n,k); 
				if (t==1) Escreve(L,n); 
			}
			free(L);
		}
	}
	return 0;
}