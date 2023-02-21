
#include <stdio.h>

int ehMinusculo(char ch){
	if((ch>='a')&&(ch<='z')){
		return 1;
	}
	return 0;
}

int ehMaiusculo(char ch){
	if((ch>='A')&&(ch<='Z')){
		return 1;
	}
	return 0;
}

int ehDigito(char ch){
	if((ch>='0')&&(ch<='9')){
		return 1;
	}
	return 0;
}

int main (int argc, char const *argv[]) {
int lixo,distancia;
char l1,l2;
do{
 	printf("Digite uma letra\n");
    	scanf("%c",&l1);
    	scanf("%c",&lixo);

	}while(!(ehMinusculo(l1)||ehMaiusculo(l1)));
	   do{
    	printf("Digite a segunda letra:\n");
    	scanf("%c",&l2);
    	scanf("%c",&lixo);

	}while(!(ehMinusculo(l1)&&ehMinusculo(l2))&&!(ehMaiusculo(l1)&&ehMaiusculo(l2)));

if(l1<l2){
	distancia=l2-l1;
}
else{
	distancia=l1-l2;
}

printf("A distancia entre '%c' e '%c' eh %d",l1,l2,distancia);

    return 0;
}
