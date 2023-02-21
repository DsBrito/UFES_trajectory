#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int x, qtd, i;
    
    scanf("%d", &x);
    scanf("%d", &qtd);
    int vet[qtd];
    
    for(i=0; i<qtd; i++){
        scanf("%d", &vet[i]);
    }
    
    for(i=0; i<qtd; i++){
        if(vet[i]==x){
            printf("RESP:%d", i);
            return 0;
        }
    }
    printf("RESP:%d", qtd);
    return (EXIT_SUCCESS);
}

