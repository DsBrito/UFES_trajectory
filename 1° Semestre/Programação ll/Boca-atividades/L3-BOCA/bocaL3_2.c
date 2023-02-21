#include <stdio.h>
#include <stdlib.h>

float Soma(float num1, float num2){
    float result;
    result= num1+num2;
    return result;
}
float Subtracao(float num1, float num2){
    float result;
    result= num1-num2;
    return result;
}
float Divisao(float num1, float num2){
    float result;
    result= num1/num2;
    return result;
}
float Multiplicacao(float num1, float num2){
    float result;
    result= num1*num2;
    return result;
}


int main(int argc, char** argv) {
    float num1, num2, num3, result;
    char operador;
    
    scanf("%f%f %c", &num1, &num2, &operador);
    switch(operador){
                case '+':
                    result = Soma(num1, num2);
                    break;
                    
                case '-':
                    result = Subtracao(num1, num2);
                    break;
                    
                case '*':
                    result = Multiplicacao(num1, num2);
                    break;
                    
                case '/':
                    result = Divisao(num1, num2);
                    break;
    }
    
    while(scanf("%f %c", &num3, &operador)==2){
        switch(operador){
                case '+':
                    result = Soma(result, num3);
                    break;
                    
                case '-':
                    result = Subtracao(result, num3);
                    break;
                    
                case '*':
                    result = Multiplicacao(result, num3);
                    break;
                    
                case '/':
                    result = Divisao(result, num3);
                    break;
    }
    }
    printf("%.2f", result);
                
                    
    return (EXIT_SUCCESS);
}

