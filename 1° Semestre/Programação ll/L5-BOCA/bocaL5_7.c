#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
    int i, k=1, qtd, razao;
    
    scanf("%d", &qtd);
    int vet[qtd];
    
    for(i=0; i<qtd; i++){
        scanf("%d", &vet[i]);
    }
    
    if(qtd==1 || qtd==0){
        printf("NAO");
        return 0;
    }
    razao= vet[1]-vet[0];
    for(i=0; k<qtd-1; i++){
        if((vet[k]-vet[i])!= razao){
            printf("NAO");
            return 0;
        }
        k++;
    }
    printf("RESP:%d", razao);
    return (EXIT_SUCCESS);
}

