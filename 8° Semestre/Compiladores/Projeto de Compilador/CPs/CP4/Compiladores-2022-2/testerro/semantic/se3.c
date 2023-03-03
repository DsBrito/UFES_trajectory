#include <stdio.h>

/*Programa em C para simular uma calculadora de quatro operações*/
int hello_word (char* name, int age){
    printf("My name is %s, I'm %d years old, Hello World!\n", name, age);
    return 2;
}

int main() {
    int num1, num2;
    int vet[10];
    vet[1] = ((2+3)*6);
    num1 = vet[1] + 3;
    vet = num1;

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

    num1 = hello_word("Paula", 18);    
    return 2;
}
