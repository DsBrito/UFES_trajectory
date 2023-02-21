#include <stdio.h>
#include <stdlib.h>

void TrocaParEImpar(int vet[], int qtd);
void ImprimeDadosDoVetor(int vet[], int qtd);

int main(int argc, char** argv) {
    int qtd, i;
    
    scanf("%d", &qtd);
    int vet[qtd];
    for(i=0; i<qtd; i++){
        scanf("%d", &vet[i]);
    }
    TrocaParEImpar(vet, qtd);
    ImprimeDadosDoVetor(vet, qtd); 
    return (EXIT_SUCCESS);
}

void TrocaParEImpar(int vet[], int qtd){
    int i, k=1, a, b;
    
    if(qtd !=0 && qtd!=1){
        for(i=0; i<qtd; i++, k++){
            a= vet[i];
            b= vet[k];
            if(i%2==0 && k!=qtd){
                vet[i]=b;
                vet[k]=a;
            }
        }
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