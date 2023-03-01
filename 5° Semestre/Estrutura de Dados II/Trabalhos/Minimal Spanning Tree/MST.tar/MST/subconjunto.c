#include <stdio.h>
#include <stdlib.h>
#include "subconjunto.h"
#include "vertice.h"
#include "lista.h"

struct sub
{
    int pai;
    int id;
};

/* aloca espaco para a struct de subconjuntos e inicializa as variaveis*/
tSub *criaSubconjunto(int pai, int id)
{
    tSub *sub = (tSub *)malloc(sizeof(tSub));
    sub->pai = pai;
    sub->id = id;
    return sub;
}

/* retorna o valor do inteiro pai */
int getPai(tSub *s)
{
    return s->pai;
}

/* retorna o valor do inteiro id */
int getid(tSub *s)
{
    return s->id;
}

/* libera a memoria alocada por um subconjunto*/
void liberaSubconjunto(tSub *sub)
{
    free(sub);
}

/* encontra o conjunto de um elemento com path compression*/
int find(tSub **vetSub, int i)
{
    /*encontra a raiz e transforma no pai de i*/
    if (vetSub[i]->pai != i)
    {
        vetSub[i]->pai = find(vetSub, vetSub[i]->pai);
    }
    return vetSub[i]->pai;
}

/* funcao q une dois conjuntox x e y pelo id*/
void Union(tSub **vetSub, int x, int y)
{
    int raizX = find(vetSub, x);
    int raizY = find(vetSub, y);

    if (vetSub[raizX]->id < vetSub[raizY]->id)
    {
        vetSub[raizX]->pai = raizY;
    }
    else if (vetSub[raizX]->id > vetSub[raizY]->id)
        vetSub[raizY]->pai = raizX;
    else
    {
        vetSub[raizY]->pai = raizX;
        vetSub[raizX]->id++;
    }
}