#include <stdio.h>
#include <stdlib.h>

int EhPar (int x){
    if(x%2==0){
        return 1;
    }
    else{
        return 0;
    }
}

void PrintaPares (int N){
    int parametro, num=1;
    for(parametro=1; parametro<=N; parametro++){
        if(EhPar(num)==1){
            printf("%d ", num);
        }
        else{
            num++;
            printf("%d ", num);
        }
        num++;
    }
}

void PrintaImpares (int N){
    int parametro, num=1;
    for(parametro=1; parametro<=N; parametro++){
        if(EhPar(num)==0){
            printf("%d ", num);
        }
        else{
            num++;
            printf("%d ", num);
        }
        num++;
    }
}

int main(int argc, char** argv) {
    int numero, quantidade;
    
    scanf("%d", &numero);
    
    if(numero==0){
        scanf("%d", &quantidade);
        PrintaPares(quantidade);
    }
    else{
        scanf("%d", &quantidade);
        PrintaImpares(quantidade);
    }
    return (EXIT_SUCCESS);
}

