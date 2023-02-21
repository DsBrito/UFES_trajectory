#include <stdio.h>
#include <stdlib.h>

int EhPar(int n){
    if(n%2==0){
        return 1;
    }
    else{
        return 0;
    }
}

int main(int argc, char** argv) {
    int qtd, num, i, posicao=0, soma=0;
    
    scanf("%d", &qtd);
    
    for(i=0; i<qtd; i++){
        scanf("%d", &num);
        if(EhPar(num)==1){
            if(EhPar(posicao)==1){
                soma= soma+num;
            }
        }else{
            if(EhPar(posicao)==0){
                soma= soma+num;
            }
        }
        posicao++;
    }
    printf("SOMA:%d", soma);
    return (EXIT_SUCCESS);
}

