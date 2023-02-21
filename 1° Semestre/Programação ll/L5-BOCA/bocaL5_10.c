#include <stdio.h>
#include <stdlib.h>

void OrdenaCrescente(int vet[], int qtd);
void ImprimeDadosDoVetor(int vet[], int qtd);

int main(int argc, char** argv) {
    int qtd, i;
    
    scanf("%d", &qtd);
    int vet[qtd];
    for(i=0; i<qtd; i++){
        scanf("%d", &vet[i]);
    }
    
    OrdenaCrescente(vet, qtd);
    ImprimeDadosDoVetor(vet, qtd); 
    
    return (EXIT_SUCCESS);
}

void OrdenaCrescente(int vet[], int qtd){
    int i, j, aux;
    
    for( i=0; i<qtd; i++ ){
        for( j=i+1; j<qtd; j++ ){
            if( vet[i] > vet[j] ){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
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