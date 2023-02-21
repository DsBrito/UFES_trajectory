/*
  


Considere que exista um arquivo chamado voo.txt que armazena 10 voos entre v�rias cidades. Cada
voo cont�m as seguintes informa��es:
<empresa a�rea> <n�mero do voo> <origem> <destino> <valor da passagem>
Empresa a�rea � um c�digo de 2 letras, o n�mero do voo tem 4 algarismos, origem e destino s�o c�digos
com 3 letras e o valor da passagem � um n�mero real. Fa�a um programa para informar ao interessado na
compra de uma passagem se existem voos entre as cidades fornecidas pelo teclado. A sa�da do seu
programa, quando n�o existir o voo desejado ser� �N�O EXISTEM VOOS�. Caso existam, imprimir a
empresa, o n�mero do voo e o valor da passagem. Pode haver mais de um voo entre as cidades desejadas.
*/
#include <stdio.h>
#include <stdlib.h>

struct voos{
char empresaAerea[3], origem[4],destino[5];
int numeroDoVoo;
float valorDaPassagem;
};

struct voos *lerVoos(){
int i;
struct voos *vet;
FILE* voo;
vet= (struct voos *)malloc(10*sizeof(struct voos));

voo = fopen("voo.txt", "r");
if (voo ==NULL){
    printf("Erro\n");
    exit(1);
}
for (i=0; i<10; i++){

    fscanf(voo, "%s %d %s %s %f",vet[i].empresaAerea, &(vet[i].numeroDoVoo), vet[i].origem, vet[i].destino, &(vet[i].valorDaPassagem) );
    printf("empresa: %s, numero do voo: %d \n origem: %s\n destino: %s\n passagem: %0.4f \n\n\n",vet[i].empresaAerea, &(vet[i].numeroDoVoo), vet[i].origem, vet[i].destino, vet[i].valorDaPassagem );
}
fclose(voo);
return vet;
};

void encontrarVoo (struct voos *vet){
int i;
char destinoDesejado[3], origemDesejada[3];

printf("digite a origem: \n");
scanf("%s", origemDesejada);
printf("digite o destino: \n");
scanf("%s", destinoDesejado);
for (i=0 ; i<10 ; i++){
    if (origemDesejada == vet[i].origem){
        if (destinoDesejado == vet[i].destino){
            printf("empresa: %s \n numero do voo: %d \n valor da passagem: %f", vet[i].empresaAerea, vet[i].numeroDoVoo, vet[i].valorDaPassagem);
        break;
        }
    }
}
    printf("nao existem voos");
};


int main(){
struct voos *vet;
vet = lerVoos();
encontrarVoo(vet);
return 0;
}
