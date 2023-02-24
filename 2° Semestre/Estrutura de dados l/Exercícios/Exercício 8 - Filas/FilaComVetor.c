

#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include <string.h>

#define TAM 10

struct fila
{
    int indice;
    int numero;
    Aluno *alunos[TAM];
};

// inicia fila
FILA *iniciaFila(void)
{

    FILA *f = (FILA *)malloc(sizeof(FILA));
    f->indice = 0;
    f->numero = 0;
    return f;
};

// insere no final da fila
void insereFila(FILA *f, Aluno *a)
{

    // testa se a fila ta cheia
    if (!f || f->numero >= TAM)
    {

        printf("\nPilha invalida ou cheia!\n");
    }

    // achando o final da fila (circular de vetor)

    int pos = (f->indice + f->numero) % TAM;

    // inserindo no final
    f->alunos[pos] = a;

    // incrementando a fila
    f->numero++;
};

// retira sempre no inico
Aluno *retiraFila(FILA *f)
{

    // testa se a fila ta vazia
    if (!f || f->numero == 0)
    {

        printf("\nPilha invalida ou vazia!\n");
        return NULL;
    }

    Aluno *a = f->alunos[f->indice];

    // faz o incremento circular do indice do inicio
    f->indice = (f->indice + 1) % TAM;

    f->numero--;

    return a;
};

// imprime do inico ao fim da fila
void imprimeFila(FILA *f)
{
    int i;
    int pos = 0;

    if (!f)
    {
        return;
    }

    for (i = 0; i < f->numero; i++)
    {
        pos = (f->indice + i) % TAM;
        ImprimeAluno(f->alunos[pos]);
    }
};

// libera memoria da fila
void destroiFila(FILA *f)
{

    if (!f)
    {
        return;
    }

    free(f);
};