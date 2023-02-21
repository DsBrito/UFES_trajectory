#include <stdio.h>

int SomarDigitos(int numero){
    int soma=0;
    
    while(numero !=0){
        soma= soma+(numero%10);
        numero = numero/10;
    }
    return soma;
}

int main(){
    int numero, soma;
    
    scanf("%d", &numero);
    
    while(numero>9){
        SomarDigitos(numero);
        soma= SomarDigitos(numero);
        numero=soma;

    }
    
    printf("RESP:%d", numero);
    return 0;
}
    
    