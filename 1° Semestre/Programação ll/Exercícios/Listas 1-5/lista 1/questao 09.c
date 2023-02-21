/*
Leia um vetor de 10 posições e atribua valor 0 para todos os elementos que possuírem
valores negativos, -1 para os impares e 1 para os pares.
*/

#include <stdio.h>
int main (int argc, char const *argv[]) {
int vet[10];
int i;

for (i=0; i<10; i++){
    printf("digite o valor na posicao %d \n", i+1);
    scanf("%d", &vet[i]);
    if (vet[i] <=0){
        vet[i] = 0;
    }else{
    if (vet[i]%2 == 0){
        vet [i] = 1;
    }else{
    vet[i] = -1;
    }
    }
}
printf("o vetor final eh: \n");
for (i=0; i<10; i++){
    printf("|%d|", vet[i]);
}
     return 0;
}
