
#include <stdio.h>
int main(){
int vet[15],i,j,cont,qtdPrimos=0;
printf("Digite os valores do vetor \n");
for(i=0;i<15;i++){
	printf("vet[%d]:",i+1);
	scanf("%d",&vet[i]);
	while(vet[i]<=0){
		printf("Digite um valor valido (positivo)\nVet[%d]:",i+1);
		scanf("%d",&vet[i]);
	}
}
for(i=0;i<15;i++){
	cont=0;
	for(j=1;j<(vet[i]/2);j++){
		if(vet[i]%j==0){
			cont++;
		}
	}
	if(cont==1){
		qtdPrimos++;
	}
}
printf("o vetor possui %d numeros primos",qtdPrimos);
	return 0;
}
