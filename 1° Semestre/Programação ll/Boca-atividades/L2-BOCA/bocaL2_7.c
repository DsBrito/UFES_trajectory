#include <stdio.h>

int main(){
	int n, i, q;

	scanf("%d", &n);
	
	q=0;
	for(i=n; i>=1; i--){
		if(!(n%i)){
			q++;
		}
	}
	
	if(q==2){
		printf("Primo");
	}
	else{ printf("Nao primo");}

	return 0;
}