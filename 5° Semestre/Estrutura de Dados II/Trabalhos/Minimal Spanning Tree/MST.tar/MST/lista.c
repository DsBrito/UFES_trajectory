#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "vertice.h"

struct lista
{
    tVertice *vertice;
    int id;
    char *nome;
    tLista *prox;
};

tLista *iniciavazia()
{
    return NULL;
}

int getIdLista(tLista *lista)
{
    return lista->id;
}

/*Insere na lista*/
tLista *insere(tVertice *vertice, tLista *lista, int id, char *nome)
{
    tLista *nova = (tLista *)malloc(sizeof(tLista));
    nova->prox = lista;
    nova->vertice = vertice;
    nova->id = id;
    nova->nome = strdup(nome);
    return nova;
}

/*função para pegar o tamanho da lista*/
int getTamanho(tLista *l)
{
    tLista *aux = l;
    int cont = 0;
    while (aux->prox != NULL)
    {
        cont++;
        aux = aux->prox;
    }
    cont++;
    // printf("tam:%d\n",cont);
    return cont;
}

/*Função que tranforma a lista num vetor*/
tVertice **pop(tLista *l, int tam)
{
    tVertice **vet = (tVertice **)malloc(sizeof(tVertice *) * tam); // LIBERAR
    tLista *p = l;
    int i = 0;

    for (p = l; p != NULL; p = p->prox)
    {
        vet[i] = p->vertice;
        i++;
    }
    return vet;
}
/*função para liberar a lista*/
void liberaLista(tLista *lista)
{
    tLista *p = lista;
    tLista *t;

    while (p != NULL)
    {
        t = p->prox;
        liberaVertice(p->vertice);
        free(p->vertice);
        free(p->nome);
        free(p);
        p = t;
    }
}
