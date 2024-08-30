#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool sub_cadeia(char L[], char S[]){
	/* insert your code here */
}

char L[3000];
char S[3000];

int main(void){
	
	while (scanf(" %[^\n]", L)>0) {
		scanf(" %[^\n]", S);
		
		printf("%d\n", sub_cadeia(L, S));
	}

	return 0;
}