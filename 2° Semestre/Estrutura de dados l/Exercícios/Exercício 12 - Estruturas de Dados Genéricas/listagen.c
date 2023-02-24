

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listagen.h"

struct listagen
{

    void *item;
    ListaGen *proximo;
};

// cria lista vazia
ListaGen *criaLista(void)
{
    return NULL;
};

// insere
ListaGen *insereLista(ListaGen *lista, void *item)
{

    ListaGen *nova = (ListaGen *)malloc(sizeof(ListaGen));
    nova->item = item;
    nova->proximo = lista;

    return nova;
};

// retira
ListaGen *retiraLista(ListaGen *lista, int (*cb)(void *, void *), void *chave)
{

    ListaGen *p = lista;
    ListaGen *ant = NULL;

    // fazendo a busca por meio de callback
    while (p != NULL && cb(p->item, chave))
    {
        ant = p;
        p = p->proximo;
    }

    // lista vazia ou nao encontrou aluno
    if (p == NULL)
        return lista;

    // se for a primeira celula
    if (ant == NULL)
        lista = lista->proximo;
    else
        ant->proximo = p->proximo;

    // liberando celula

    free(p);

    // retornando a nova lista;

    return lista;
};

// pecorre
int pecorreLista(ListaGen *lista, int (*cb)(void *, void *), void *dado)
{

    ListaGen *p;

    for (p = lista; p != NULL; p = p->proximo)
    {
        int r = cb(p->item, dado);

        // se encontrou o item que buscava
        if (r == 0)
        {
            return r;
        }
    }

    return 1;
};

// libera celulas
ListaGen *libera(ListaGen *lista)
{

    ListaGen *p = lista;
    ListaGen *t;
    while (p != NULL)
    {
        t = p->proximo;
        free(p);
        p = t;
    }
};