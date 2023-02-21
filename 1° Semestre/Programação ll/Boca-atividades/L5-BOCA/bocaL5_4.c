#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
    int qtd, i, a, b, fora=0, dentro=0;
    
    scanf("%d", &qtd);
    int vetor[qtd];
    
    for(i=0; i<qtd; i++){
        scanf("%d", &vetor[i]);
    }
    scanf("%d%d", &a, &b);
    
    for(i=0; i<qtd; i++){
        if(vetor[i]>=a && vetor[i]<=b)
            dentro++;
        else
            fora++;
    }
    
    printf("%d %d", dentro, fora);
    
    return (EXIT_SUCCESS);
}

