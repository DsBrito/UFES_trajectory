

#include <stdio.h>

int main(){
int i=0, voltaMenorTempo=0, numVoltas, primeira=0;
float vet[100],menorTempo, tempoTotal=0.0, tempoMedio;

printf("digite o numero de voltas dadas:\n");
scanf("%d",&numVoltas);
while(numVoltas<=0){
	printf("digite um valor valido\n");
	scanf("%d",&numVoltas);
}
while(i<numVoltas){
	printf("digite o tempo da volta numero %d:\n",(i+1));
	scanf("%f",&vet[i]);
	while(vet[i]<=0){
		printf("digite um valor valido\n");
		scanf("%f",&vet[i]);
	}
	if(primeira==0){
		menorTempo=vet[i];
		primeira=1;
	}
	if(vet[i]<menorTempo){


		menorTempo=vet[i];
		voltaMenorTempo=i+1;
	}
	tempoTotal=tempoTotal+vet[i];
	i++;
}
tempoMedio=tempoTotal/numVoltas;

printf("Melhor tempo: %.2f \nVolta em que o melhor tempo ocorreu: volta numero %d\nTempo medio das %d voltas: %.2f \n",menorTempo,voltaMenorTempo,numVoltas,tempoMedio);

	return 0;
}
