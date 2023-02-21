#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

char *atrrev(char *s) // INVERTE
{
    int i, len;
    char aux;
    for (i = 0, len = strlen(s) - 1; i < len; i++, len--)
    {
        aux = s[i];
        s[i] = s[len];
        s[len] = aux;
    }
    return s;
}

int main()
{
    char texto[100];
    printf("\nDigite o texto:");
    gets(texto);
    printf("%s", atrrev(texto));

    getch();
    return 1;
}
