

#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "ListaComSentinela.h"
#include <string.h>

struct fila
{
    Lista *lista;
};

// inicia fila
FILA *iniciaFila(void)
{

    FILA *f = (FILA *)malloc(sizeof(FILA));
    f->lista = IniciaLista();
    return f;
};

// insere no final da fila
void insereFila(FILA *f, Aluno *a)
{
    InsereListaUltima(f->lista, a);
};

// retira sempre no inico
Aluno *retiraFila(FILA *f)
{
    return Retira(f->lista, "bruna");
};

// imprime do inico ao fim da fila
void imprimeFila(FILA *f)
{
    ImprimeLista(f->lista);
};

// libera memoria da fila
void destroiFila(FILA *f)
{
    DestroiLista(f->lista);
    free(f);
};