#include <stdio.h>
#include <stdlib.h>

/* 
 * 
 */
int main(int argc, char** argv) {
    int menor, numero, i, p, posicao, primeiro, ultimo;
    
    
    i=0;
    p=0;
    posicao=0;
    
    while(scanf("%d ", &numero)){        
        if(i==0){
            menor= numero;
            i++;
        }
        if(numero<menor){
            menor= numero;
        }
    }
    
    scanf("%*c");
    i=0;
        
    while(scanf("%d ", &numero)){
        if(numero==menor && i==0){
            primeiro=posicao;
            i++;
        }
        
        if(numero==menor){
            ultimo=posicao;
            p++;
        }
        
        if(i==0){
            primeiro=posicao+1;
            ultimo=posicao+1;
        }
        
        if(i==1 && p==0){
            ultimo=primeiro;
        }
        posicao++;
    }
    printf("%d %d %d", menor, primeiro, ultimo);
    return (EXIT_SUCCESS);
}

