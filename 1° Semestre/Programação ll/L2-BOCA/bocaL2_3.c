#include <stdio.h>

int main(){
	int quantidade, num, quantNum, maior, menor, par, impar, i;
	float soma;

	scanf("%d", &quantidade);
	
	i=0;
	quantNum=0;
	par=0;
	impar=0;
	soma=0;
	
	menor=quantidade;

	while(quantNum<quantidade){

		scanf("%d", &num);

		if(i==0){
			menor=num;
			maior=num;
			i++;
		}

		if(num<=menor){
			menor=num;
		}
		if(num>=maior){
			maior=num;
		}
		if(num%2){
			impar++;
		}
		if(!(num%2)){
			par++;
		}
		soma= soma+num;
		quantNum++;
	}
	
	printf("%d %d %d %d %.6f", maior, menor, par, impar, soma/quantidade);

	return 0;
}