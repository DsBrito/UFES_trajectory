

#include "listaalunos.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct cr
{

    float CR;
    int n;
};

// #########################################################################33
// FUNÇÃO DE CALLBACKSS

static int comparacaoMat(void *aluno, void *mat)
{

    Aluno *a = (Aluno *)aluno;
    int *idmat = (int *)mat;

    // retorn 0 se forem iguais

    if (RetornaMatricula(a) == *idmat)
        return 0;

    // retorna 1 se nao forem iguais
    return 1;
};

static int acumula(void *aluno, void *dado)
{
    struct cr *acumulado = (struct cr *)dado;
    acumulado->CR += RetornaCR(aluno);
    acumulado->n++;

    // para continuar o processo de pecorrer
    return 1;
}

static int imprime(void *aluno, void *dado)
{

    ImprimeAluno(aluno);
    // retorna para continuar pecorrendo
    return 1;
};

// retira alluno com matricula passada como parametro
ListaGen *retriaAluno(ListaGen *lista, int matricula)
{
    return retiraLista(lista, comparacaoMat, &matricula);
};

// verifica se o aluno esta na lista
int pertenceAluno(ListaGen *lista, int matricula)
{
    return pecorreLista(lista, comparacaoMat, &matricula);
};

// imprime lista de alunos
void imprimeAlunos(ListaGen *lista)
{
    pecorreLista(lista, imprime, NULL);
};

// calcula media de CR da turma
float mediaTurma(ListaGen *lista)
{

    struct cr *acumulado = (struct cr *)malloc(sizeof(struct cr));
    acumulado->CR = 0.0;
    acumulado->n = 0;
    pecorreLista(lista, acumula, acumulado);

    float media = (acumulado->CR / acumulado->n);

    free(acumulado);

    return media;
};

ListaGen *retiraAluno(ListaGen *lista, int matricula)
{

    return retiraLista(lista, comparacaoMat, &matricula);
};

int comparaMat(void *aluno1, void *aluno2)
{
    Aluno *a1 = (Aluno *)aluno1;
    Aluno *a2 = (Aluno *)aluno2;

    // se forem iguais retorna zero (0)
    if (RetornaMatricula(a1) == RetornaMatricula(a2))
        return 0;

    // retorna 1 para nao parar de pecorrer
    return 1;
};
