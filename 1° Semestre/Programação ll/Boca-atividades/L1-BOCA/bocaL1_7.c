#include <stdio.h>

int main(){
    float n1, n2, n3; // n1 é o valor de entrada inserido, n2 e n3 sao valores da conversao Celsius ou Fahrenheit
    char temp; // temp é o tipo de temperatura inserido (c ou f)
    
    scanf("%f %c", &n1, &temp); //faz a leitura do numero e do caracter
    n2= 9*(n1/5)+32; //converte Celsius em Fahrenheit
    n3= 5*(n1-32)/9;

    if(temp == 'c' || temp == 'C') //se a leitura do caracter for c ou C
    printf("%.2f (F)\n", n2); // mostra o resultado na tela

    if(temp == 'f' || temp == 'F')//agora faz essa operacao se for o contrario Fahrenheit para Celsius
    printf("%.2f (C)\n", n3);

    return 0;
}
