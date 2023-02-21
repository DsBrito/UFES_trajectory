#include <stdio.h>
#include <stdlib.h>
#include<math.h>


int main(int argc, char** argv) {
    int i, tam, maior, menor, acimaMedia=0, reprovado=0;
    float soma=0, media, desvioPadrao, somaDesvioPadrao=0;
    
    scanf("%d", &tam);
    int nota[tam];
    
    for(i=0; i<tam; i++){
        scanf("%d", &nota[i]);
        soma= soma + nota[i];
    }
    media= soma/tam;
    maior = nota[0];
    menor = nota[0];
    
    for(i=0; i<tam; i++){
        if(nota[i]>media){
            acimaMedia++;
        }
        if(nota[i]<70){
            reprovado++;
        }
        if(nota[i]>maior){
            maior= nota[i];
        }
        if(nota[i]<menor){
            menor= nota[i];
        }
    }
    
    for(i=0; i<tam; i++){
        somaDesvioPadrao= somaDesvioPadrao + (nota[i]-media)*(nota[i]-media);
    }
    desvioPadrao= sqrt(somaDesvioPadrao/i);
    
    printf("MENOR:%d, ", menor);
    printf("MAIOR:%d, ", maior);
    printf("MEDIA:%.2f, ", media);
    printf("STD:%.2f, ", desvioPadrao);
    printf("ACIMA_MEDIA_CONC:%d, ", acimaMedia);
    printf("REPROV:%d", reprovado);    
    
    return (EXIT_SUCCESS);
}

