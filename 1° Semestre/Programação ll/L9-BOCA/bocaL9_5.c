#include <stdio.h>

int main(){

    int qtd, impar, par, i, numero, identificador;

    par=0;
    impar=0;

    scanf("%d", &qtd);

    for(i=1; i<=qtd; i++){
        scanf("%d", &numero);
        
        if(i==1){
        identificador= numero;
        }
        
        if(numero % 2==0){
            par++;
        }
        if(numero % 2!=0){
            impar++;
        }
    }
    if (identificador %2 == 0){
        printf("QTD PARES:%d", par);
    }
    if (identificador %2 != 0){
        printf("QTD IMPARES:%d", impar);
    }
    return 0;
}
