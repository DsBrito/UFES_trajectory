#include <stdio.h>

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

int main(){
    float num1, num2;
    while ( scanf("%f %f", &num1, &num2) == 2 ){
        float result;
        result = Soma(num1, num2);
        printf("%.2f", result);
        result = Subtracao(num1, num2);
        printf(" %.2f", result);
        result = Divisao(num1, num2);
        printf(" %.2f", result);
        result = Multiplicacao(num1, num2);
        printf(" %.2f\n", result);
    }
    return 0;
}
    
    