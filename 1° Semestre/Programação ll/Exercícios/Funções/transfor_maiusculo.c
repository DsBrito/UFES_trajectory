#include <stdio.h>
#include <locale.h>

char *transformada(char *s)
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
    {

        s[i] = toupper(s[i]);
    }
    return s;
}
int main()
{
    char texto[100];
    printf("\nDigite o texto:");
    gets(texto);
    printf("%s", transformada(texto));

    return 1;
}
