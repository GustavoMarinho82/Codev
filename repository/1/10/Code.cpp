#include <stdio.h>
#include <math.h>

bool eh_Primo(long long int x) {
	/* insert your code here */
}
	
int main(){
	long long int x;

	while(scanf("%lld", &x)>0){
	    if (eh_Primo(x)) {
			printf("Primo\n");
	    } else {
			printf("Composto\n");
	    }
	}

	return 0;
}