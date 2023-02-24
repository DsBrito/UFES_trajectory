

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "palavra.h"
#include "hash.h"

struct hash
{
    int tamanho;
    Palavra **vet;
};

static int hash(char *s, int tamanho)
{
    int i;
    int total = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
        total += s[i];
    }

    return (total % tamanho);
};

Hash *inicHash(int tamanho)
{
    int i;
    Hash *h = (Hash *)malloc(sizeof(Hash));

    h->tamanho = tamanho;

    h->vet = (Palavra **)malloc(tamanho * sizeof(Palavra *));

    for (i = 0; i < tamanho; i++)
        h->vet[i] = NULL;
    return h;
};

Palavra *acessa(Hash *h, char *string)
{
    Palavra *p;

    // aplica funcao de hash
    int indice = hash(string, h->tamanho); // aplicando função de hash

    p = buscaPalavra(h->vet[indice], string);

    if (p)
        return p;

    p = IniciaPalavra(string);

    h->vet[indice] = inserePalavraLista(h->vet[indice], p);

    return p;
}

void imprimeHash(Hash *h)
{
    int i;

    for (i = 0; i < h->tamanho; i++)
    {
        printf("\nPosicao vet[%d]: \n", i);
        imprimeLista(h->vet[i]);
    }
}

void liberaHash(Hash *h)
{
    int i;
    for (i = 0; i < h->tamanho; i++)
        liberaListaPalavra(h->vet[i]);

    free(h->vet);
    free(h);
};