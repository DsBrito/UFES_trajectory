#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int postes[100];
    int qtd, i, k=1, maiorDiferenca=0, diferenca;
    
    scanf("%d", &qtd);
    
    for(i=0; i<qtd; i++){
        scanf("%d", &postes[i]);
    }
    
    for(i=0; i<qtd; i++){
        if(qtd != 1 && qtd !=0){
            if(k != qtd)
                diferenca= postes[i]-postes[k];
            if(diferenca<0)
                diferenca= diferenca*(-1);
            if(diferenca>maiorDiferenca)
                maiorDiferenca= diferenca;
            k++;
            diferenca= 0;
        }
    }
    
    k=1;
    for(i=0; i<qtd; i++){
        if(qtd != 1 && qtd !=0){
            if(k != qtd)
                diferenca= postes[i]-postes[k];
            if(diferenca<0)
                diferenca= diferenca*(-1);
            if(k== qtd)
                break;
            if(diferenca==maiorDiferenca)
                printf("(%d %d) ", i, k);
        }
        else{
            printf("IMPOSSIVEL\n");
        }
        k++;
    }
    
    return (EXIT_SUCCESS);
}

