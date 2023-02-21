#include <stdio.h>

int main(){
    char l1;

    scanf("%c", &l1); //leitura da letra inserida
    

    if(l1 == 'a' || l1 == 'e'|| l1 == 'i' || l1 == 'o'|| l1 == 'u' || l1 == 'A'|| l1 == 'E'|| l1 == 'I'|| l1 == 'O'|| l1 == 'U') //se a leitura de l1 for igual a uma dessas letras mensionadas no parenteses do if ele vai escrever "Vogal" na tela
    printf("Vogal\n");

    else
    printf("Nao vogal\n"); //caso contrario, ele vai escrever "Nao vogal"

    return 0;

}
