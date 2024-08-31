#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contagem(long long int x, int y){
    //Jeito sem usar string ou array
	int apareceu = 0;
    
    while(x!=0){
        if (x%10 == y){
            apareceu++;
        }
        x /= 10;
    }
	
	return apareceu;
}

int main(){
	long long int x;
	int y;

	while(scanf("%lld %d", &x, &y) > 0){
	    printf("%d\n", contagem(x, y));
	}
	return 0;
}