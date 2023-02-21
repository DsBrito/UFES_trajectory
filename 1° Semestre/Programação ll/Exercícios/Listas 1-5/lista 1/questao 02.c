/*
Sendo h = 1 - 1/2 + 1/3 - 1/4 + ... + 1/N, construa um programa em C para calcular o
número h, sendo o número inteiro N fornecido pelo usuário. Seu algoritmo deve garantir
que apenas um valor maior do que zero seja aceito como entrada.
*/

#include <stdio.h>
int main () {
int i,n;
float h;

h=0.0;
printf("digite o numero desejado\n");
scanf("%d",&n);
while (n<0){
    printf("digite um numero positivo\n");
    scanf("%d", &n);
}
for (i=1; i<=n; i++){
    if (i%2==0){
        h=h-(1.0/i);
    }else{
    h=h+(1.0/i);
    }
}

printf ("o valor encontrado eh: %.2f", h);
     return 0;
}
