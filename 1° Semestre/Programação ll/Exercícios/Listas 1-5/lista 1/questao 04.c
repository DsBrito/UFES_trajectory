/*
Crie um programa capaz de ler os dados de uma matriz quadrada de inteiros (5x5). Ao
final da leitura o programa deverá imprimir o número da linha que contém o menor dentre
todos os números lidos.
*/
#include<stdlib.h>
#include<stdio.h>
int main(){
int mat[5][5], menornumero, i,j, linha;

for (i=1; i<6; i++){
    for (j=1; j<6;j++){
        printf ("digite o valor da matriz na posicao %dx%d\n", j,i);
        scanf ("%d", &mat[i][j]);
    }
}
printf("matriz lida\n");
menornumero = mat[1][1];
linha=1;
for (i=1; i<6; i++){
    for (j=1; j<6; j++){
            if(menornumero>mat[i][j]){
            linha=j;
            }
}
}
printf("o menor valor esta na linha %d da matriz dada", linha);
return 0;
}
