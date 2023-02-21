#include <stdio.h>

int main(){
    int numero, positivo, negativo, somaPositivo, somaNegativo;
    char caracter;

    positivo=0;
    negativo=0;
    somaPositivo=0;
    somaNegativo=0;
    caracter=' '; 
    
    while(caracter == ' ' || caracter == '\n'){
        caracter= '\0';
        scanf("%d", &numero);
        scanf("%c", &caracter);

        if(numero > 0){
            positivo++;
            somaPositivo= somaPositivo+numero;
        }
        if(numero <0){
            negativo++;
            somaNegativo= somaNegativo + numero;
        }
        
    }
    printf("%d %d %d %d", negativo, positivo, somaNegativo, somaPositivo);
    return 0;
}
