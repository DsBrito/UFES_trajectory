#include "tDatas.h"
#include <stdio.h>

int AcharMenorEntreAeB(tData * vet, int a, int b){
     int i, idx; 
     tData menor;
     
     menor = vet[a];
     idx = a;
     for(i = a+1; i <= b; i++)
     {
           if ( EhMenorDataAqDataB(&vet[i], &menor)){ 
                menor = vet[i];
                idx = i;
           }
     }
     return idx;
}

void OrdeneDatasCrescente(tData * vet, int qtd){
     int i, idxMenor;
     tData aux;
     
     for(i = 0; i < qtd-1; i++)
     {
        idxMenor = AcharMenorEntreAeB(vet, i+1, qtd-1);
        if ( EhMenorDataAqDataB(&vet[idxMenor], &vet[i]) ){
           aux = vet[idxMenor];
           vet[idxMenor] = vet[i];
           vet[i] = aux;
        }
     }
     
}

int AcharMaiorEntrePAePB(tData ** vet, int a, int b){
     int i, idx; 
     tData *maior;
     
     maior = vet[a];
     idx = a;
     for(i = a+1; i <= b; i++)
     {
           if ( EhMenorDataAqDataB(maior, vet[i]) ){ 
                maior = vet[i];
                idx = i;
           }
     }
     return idx;
}

void OrdenePDatasDecrescente(tData ** vet, int qtd){
     int i, idxMaior;
     tData *aux;
     
     for(i = 0; i < qtd-1; i++)
     {
        idxMaior = AcharMaiorEntrePAePB(vet, i+1, qtd-1);
        if ( EhMenorDataAqDataB(vet[i], vet[idxMaior]) ){
           aux = vet[idxMaior];
           vet[idxMaior] = vet[i];
           vet[i] = aux;
        }
     }
     
}

void ApresentaDatas(tData * vet, int qtd){
    int i;

    for(i = 0; i < qtd; i++)
    {
        ImprimeData( &(vet[i]) );
        printf("\n");
    }
    printf("\n");
}

void ApresentaPDatas(tData ** vet, int qtd){
    int i;

    for(i = 0; i < qtd; i++)
    {
        ImprimeData( vet[i] );
        printf("\n");
    }
    printf("\n");
}

int IniciaVetorPDatas(tData ** vetOut, tData * vetIn, int qtd){
    int i;

    for(i = 0; i < qtd; i++){
        vetOut[i] = &(vetIn[i]);
    }
}

