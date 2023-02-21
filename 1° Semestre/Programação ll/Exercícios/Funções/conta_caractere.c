#include <stdio.h>
#include <conio.h>
#include <locale.h>

int cont(char *s, char ch) // fun��o que retorna quantas vezes um caractere repete em um texto
                           // fun��o tamb�m retorna quantos caracteres que h� no texto
{
    int i;
    for (i = 0; s[i] != '\0'; i++)

        if (s[i] == ch)
        {
            printf("%d  ", i + 1);
        }
    printf("\n\nO numero de caracteres que ha no texto eh: ");
    return i;
    return 0;
}

int main()
{
    char texto[100];
    char x;
    int i, conta;
    printf("\nDigite o texto:");
    gets(texto);
    printf("\nDigite o caractere que busca:");
    scanf("%c", &x);
    printf("%d", cont(texto, x));
    // out(texto,x);

    getch();
    return 1;
}
