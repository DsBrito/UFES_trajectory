/*
Construa um programa para determinar e mostrar o n�mero de d�gitos de um n�mero
inteiro informado pelo usu�rio.
*/

#include<stdio.h>

int main (){
int n,i;

printf ("digite um numero inteiro\n");
scanf("%d", &n);

if (n<0){
    n = n*-1;
}

for(i=0; n>0 ;i++){
    n = n/10;
}


printf ("o numero digitado tem %d digitos", i);
return 0;
}
