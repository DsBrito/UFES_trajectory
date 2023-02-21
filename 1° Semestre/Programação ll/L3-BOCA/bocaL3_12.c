#include <stdio.h>
#include <stdlib.h>

int somadosdigitos(int n){
    int numero, soma=0;
    while(n !=0){
        numero= n%10;
        soma= soma+numero;
        n= n/10;
    }
    return soma;
}

void parImpar(int n){
    if(n%2==0){
        printf("Par ");
    }
    else{
        printf("Impar ");
    }
}

void valorPrimo(int n){
    int i, p=0;
    for(i=1; i<=n; i++){
        if(n%i==0){
            p++;
        }
    }
    if(p==2){
        printf("Primo");
    }
    else{
        printf("Nao e primo");
    }
}

int main(int argc, char** argv) {
    int numero, i=0;
    
    scanf("%d", &numero);
    while(numero>9){
        numero=somadosdigitos(numero);
        printf("%d ", numero);
        parImpar(numero);
        valorPrimo(numero);
        printf("\n");
        i++;
    }
    if(i==0 && numero<10){
        printf("%d ", numero);
        parImpar(numero);
        valorPrimo(numero);
    }
    return (EXIT_SUCCESS);
}

