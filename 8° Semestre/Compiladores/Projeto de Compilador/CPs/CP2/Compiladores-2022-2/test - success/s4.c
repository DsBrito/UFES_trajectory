#include <stdio.h>

/*Programa em C para simular uma calculadora de quatro operações*/
void hello_word (char* name, int age){
    int i = 3;
    printf("My name is %s, I'm %d years old, Hello World!\n", name, age);
}

int main() {
    int num1, num2;
    int vet[10];

    printf("=== CALCULADORA ===\n");
    printf("Numero: ");
    scanf("%i", &num1);
    printf("Numero: ");
    scanf("%i", &num2);

    printf("\nSoma: %i \n",    num1 + num2);
    printf("Subtracao: %i \n", num1 - num2);
    printf("Produto: %i \n",   num1 * num2);
    printf("%1 elevado a %i: %f \n",   num1, num2, num1 ^ num2);
    printf("Divisão: %f \n",   num1 / num2);
    printf("Resto da divisão: %f \n",  num1 % num2);

    hello_word("Paula", 18);    
    return 0;
}
