#include <stdio.h>
#include <stdlib.h>

float FazOperacao(float num1, float num2, char op){
    float resultado;
    
    switch(op){
        case '+':
            resultado= num1 + num2;
            break;
        
        case'-':
            resultado= num1 - num2;
            break;
            
        case'*':
            resultado= num1 * num2;
            break;
            
        case'/':
            resultado= num1 / num2;
            break;
    }
    while(scanf("%f", &num1)==1){
        scanf(" %c", &op);
        switch(op){
            case '+':
            resultado= resultado + num1;
            break;
        
        case'-':
            resultado= resultado - num1;
            break;
            
        case'*':
            resultado= resultado * num1;
            break;
            
        case'/':
            resultado= resultado / num1;
            break;
        }
    }
    return resultado;

}

float ResolveExpressao(char caracter){
    float resultado, num1, num2, maior=0;
    char op;
    
    while(caracter != '.'){
        if(caracter=='('){
            scanf("%f%f %c", &num1, &num2, &op);
            resultado= FazOperacao(num1, num2, op);
            printf("%.2f", resultado);
        }
        if(resultado>maior){
            maior= resultado;
        }
        if(caracter !='(' && caracter !=')'){
            printf("%c", caracter);
        }
        scanf("%c", &caracter);
    }
    return maior;
    
}

int main(int argc, char** argv) {
    char caracter;
    float maior;
    
    scanf("%c", &caracter);
    maior= ResolveExpressao(caracter);
    printf(". MAIOR:%.2f", maior);
    return (EXIT_SUCCESS);
}

