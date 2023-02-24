

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listahet.h"

#define PROFESSOR 0
#define ALUNO 1

typedef struct cel tCelula;

struct cel
{
    tCelula *proximo;
    void *item;
    int tipo;
};

// sentinela
struct listahet
{
    tCelula *primeiro;
    tCelula *ultimo;
};

ListaHet *IniciaLista(void)
{

    ListaHet *lista = (ListaHet *)malloc(sizeof(ListaHet));
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    return lista;
};

void InsereAluno(ListaHet *lista, Aluno *aluno)
{

    tCelula *nova = (tCelula *)malloc(sizeof(tCelula));
    nova->item = aluno;
    nova->tipo = ALUNO;
    nova->proximo = lista->primeiro;
    lista->primeiro = nova;
    if (lista->ultimo == NULL)
    {
        lista->ultimo = nova;
    }
};

void InsereProfessor(ListaHet *lista, Professor *professor)
{

    tCelula *nova = (tCelula *)malloc(sizeof(tCelula));
    nova->item = professor;
    nova->tipo = PROFESSOR;
    nova->proximo = lista->primeiro;
    lista->primeiro = nova;
    if (lista->ultimo == NULL)
    {
        lista->ultimo = nova;
    }
};

void ImprimeListaHet(ListaHet *lista)
{

    tCelula *p;

    for (p = lista->primeiro; p != NULL; p = p->proximo)
    {

        if (p->tipo == ALUNO)
        {
            printf("ALUNO: ");
            ImprimeAluno((Aluno *)p->item);
        }
        if (p->tipo == PROFESSOR)
        {
            printf("PROFESSOR: ");
            ImprimeProfessor((Professor *)p->item);
        }
    }
};

float ValorChurrasco(ListaHet *lista)
{

    tCelula *p = lista->primeiro;
    float valor = 0.0;

    while (p != NULL)
    {
        if (p->tipo == PROFESSOR)
        {
            valor = valor + 0.02 * RetornaSalario(p->item);
        }
        if (p->tipo == ALUNO)
        {
            valor = valor + 30.0;
        }

        p = p->proximo;
    }

    return valor;
};

void DestroiLista(ListaHet *lista)
{

    tCelula *p = lista->primeiro;
    tCelula *t;

    while (p != NULL)
    {
        t = p->proximo;
        free(p);
        p = t;
    }

    free(lista);
};
