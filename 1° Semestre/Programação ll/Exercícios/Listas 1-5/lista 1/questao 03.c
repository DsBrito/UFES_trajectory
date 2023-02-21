/*
Construa um programa para determinar e mostrar o número de dígitos de um número
inteiro informado pelo usuário.
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
