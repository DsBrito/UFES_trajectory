#include <stdio.h>

int main(){
	
	int l, c, i, j;
	int soma = 0, atual, total=0;

	scanf("%d %d", &l, &c);

	
	for (i = 0; i<l; i++){
		for(j = 0, soma=0; j<c; j++){
			scanf("%d", &atual);
			soma = soma + atual;
		}
                total= total +soma;
		printf("%d\n", soma);
	}

	printf("%d\n", total);

	return 0;
}
