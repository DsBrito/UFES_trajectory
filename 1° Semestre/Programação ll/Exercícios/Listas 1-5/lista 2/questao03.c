

#include <stdio.h>

int main(){
int num, soma=0, qdPerf=0, impar=1,raiz=0;

printf("digite um numero para saber se ele eh um quadrado perfeito\n");
scanf("%d",&num);
while(num<=0){
	printf("o num deve ser positivo \n");
	scanf("%d",&num);
}
while((soma<=num)&&(qdPerf==0)){
	if(num==soma){
		qdPerf=1;
	}
	else{
		soma=soma+impar;
		impar=impar+2;
		raiz++;
	}
}
if(qdPerf==1){
	printf("o num %d eh um quadrado perfeito e a raiz de %d eh %d", num,num,raiz);
}
else{
	printf("%d nao eh um quadrado perfeito", num);

}

	return 0;
}
