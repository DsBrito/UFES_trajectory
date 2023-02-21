#include <stdio.h>
#include <stdlib.h>

void InverteVetor(int * vet, int qtd);
void ImprimeDadosDoVetor(int vet[], int qtd);

int main(int argc, char** argv) {
    int qtd, i;
    
    scanf("%d", &qtd);
    int vet[qtd];
    for(i=0; i<qtd; i++){
        scanf("%d", &vet[i]);
    }
    InverteVetor(vet, qtd);
    ImprimeDadosDoVetor(vet, qtd); 
    
    return (EXIT_SUCCESS);
}

void InverteVetor(int * vet, int qtd){
    int vet2[qtd];
    int i, j;
    
    j=qtd-1;
    for(i=0; i<qtd; i++, j--){
        vet2[j]= vet[i];
    }
    for(i=0; i<qtd; i++){
        vet[i]= vet2[i];
    }
}

void ImprimeDadosDoVetor(int vet[], int qtd){
    int i;
    
    if(qtd==0){
        printf("{}");
    }
    if(qtd==1){
        printf("{%d}", vet[0]);
    }
    if(qtd !=0 && qtd!=1){
        printf("{");
        for(i=0; i<qtd; i++){
            printf("%d", vet[i]);
            if(i != qtd-1)
            printf(", ");
        }
        if(i==qtd)
            printf("}");
    }
}