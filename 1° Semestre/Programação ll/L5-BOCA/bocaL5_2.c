#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int i, tam, qtd=1, qtd2=1, qtd3=1, qtd4=1, notaAtual;
    
    scanf("%d", &tam);
    int nota[tam];
    
    for(i=0; i<tam; i++){
        scanf("%d", &nota[i]);
    }
    
    notaAtual= nota[0];
    for(i=1; i<tam; i++){
        qtd++;
        if(nota[i]>notaAtual){
            qtd2++;
        }
        if(nota[i]<notaAtual){
            qtd3++;
        }
        if(nota[i]==notaAtual){
            qtd4++;
        }
        notaAtual = nota[i];
    }
    if(qtd2==tam && qtd!=1){
        printf("CRESCENTE");
    }
    if(qtd3==tam && qtd!=1){
        printf("DECRESCENTE");
    }
    if(qtd2 != tam && qtd3!= tam && qtd4!=tam && qtd !=1){
        printf("DESORDENADO");
    }
    if(qtd4==tam || qtd==1){
        printf("CRESCENTE&DECRESCENTE");
    }
    
    return (EXIT_SUCCESS);
}

