

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include <ctype.h>

#define NPAL 64
#define NTAB 127

int le_palavra(FILE *fp, char *s)
{

    int i = 0;
    int c;

    // pula o que é diferente de letras
    while ((c = fgetc(fp)) != EOF)
    {
        if (isalpha(c))
            break;
    }

    if (c == EOF)
        return 0;
    else
        s[i++] = c;

    while ((i < NPAL - 1) && (c = fgetc(fp)) != EOF && isalpha(c))
        s[i++] = c;

    s[i] = '\0';

    return i;
};

int main(int argc, char **argv)
{

    FILE *fp;
    Hash *tab;

    char s[NPAL];

    if (argc != 2)
    {
        printf("Arquivo nao encontrado!\n");
        return 0;
    }

    // fp= fopen("entrada.txt", "rt");
    fp = fopen(argv[1], "rt");

    if (fp == NULL)
    {
        printf("Erro na abertura do arquivo!\n");
        return 0;
    }

    tab = inicHash(NTAB);

    while (le_palavra(fp, s))
    {
        Palavra *p = acessa(tab, s);

        atualizaOcorrencias(p); // incrementa ocorrencia
    }
    imprimeHash(tab);

    liberaHash(tab);

    return (EXIT_SUCCESS);
};