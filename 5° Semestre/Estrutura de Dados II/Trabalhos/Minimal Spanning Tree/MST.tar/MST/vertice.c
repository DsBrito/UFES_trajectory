#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vertice.h"

struct vertice
{
    int id;
    char *nome;
};

int comparaVertice(const void *a, const void *b)
{
    tVertice *a1 = *(tVertice **)a;
    tVertice *a2 = *(tVertice **)b;
    return strcmp(a1->nome, a2->nome);
}

tVertice *iniciaVertice(int id, char *nome)
{
    tVertice *ver = (tVertice *)malloc(sizeof(tVertice));
    ver->id = id;
    ver->nome = strdup(nome);
}

char *retornaNome(tVertice *vertice)
{
    return vertice->nome;
}

void imprimeNomeVertice(tVertice *vertice, FILE *f)
{
    fprintf(f, "%s", vertice->nome);
}

void liberaVertice(tVertice *vertice)
{
    free(vertice->nome);
}
